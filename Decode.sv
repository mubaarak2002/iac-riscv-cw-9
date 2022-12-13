module Decode #(

    //input parameters
    parameter INSTRW = 32,
    parameter ZEROW = 1,

    //ALU  and Immidiate parameters
    parameter ALUCTRLW = 4,
    parameter UPPERIMW = 20,
    parameter SHORTIMMW = 5,
    parameter IMMSELW = 3,
    parameter IMMOPW = 25,
    
    //read and write parameters
    parameter RDADDR1W = 5,
    parameter RDADDR2W = 5,
    parameter MEMWRITEW = 32,
    parameter WRADDRW = 5,

    //other parameters
    parameter OPCODEW = 7,
    parameter PCWIDTH = 16,
    parameter BRCHCDEW = 3

)(
    //inputs
    input logic [INSTRW-1:0]      Instruction,
    input logic [ZEROW-1:0]       ZERO,
    input logic [PCWIDTH-1:0]      PC_next,


    //ALU & Results Outputs
    output logic [ALUCTRLW-1:0]   ALUctrl,
    output logic                  ALUsrc,
    output logic                  ResultSrc,


    //Memory Outputs
    output logic [RDADDR1W-1:0]   RdAdd1,
    output logic [RDADDR2W-1:0]   RdAdd2,
    output logic [WRADDRW-1:0]    WrAddr,
    output logic                  RegWrite,
    output logic                  MemWrite,

    //immidiate Outputs
    output logic [IMMOPW-1:0]     ImmOp,
    output logic [IMMSELW-1:0]    Immsrc,
    output logic [PCWIDTH-1:0]    PC,

    //PC outputs
    output logic                  PCSrc

);

//All internal signals:
logic [RDADDR1W-1:0]    rd;
logic [RDADDR2W-1:0]    rs1;
logic [RDADDR2W-1:0]    rs2;
//note this is the longest possible immidiate command
logic [IMMOPW-1:0]      Imm;

logic [UPPERIMW-1:0]    UpperImm;
logic [SHORTIMMW-1:0]   ShortImm;
logic [OPCODEW-1:0]     opcode;
logic [ALUCTRLW-1:0]    ALUopcode;
logic [RDADDR1W-1:0]    r0;
logic [BRCHCDEW-1:0]  branchcode;



always_comb begin
    //rd is used across all commands, and is the destination register
    rd  = Instruction[11:7];

    //this is the "zero address", which corresponds to register x0 which always contains zero
    //mostly used in this program for all "irelevant adresses" for simplicity.
    r0 = 5'b00000;

    //sometimes replaced with immidaiate operand, and are not always applicable
    rs1 = Instruction[19:15];
    rs2 = Instruction[24:20];

    //extract the immidiate operand from its position in the Instruction
    //(only useful when opcode asks for immidiate, else just gibberish
    //needs to be decoded by the sign_extend module as per 
    //contains every possible jump instruction
    Imm = Instruction [31:7];


    //this is the opcode of the function
    opcode = Instruction [6:0];

    //This is the branchcode, which indicates what Branch instruction is to be done.
    branchcode = Instruction [14:12];

    //this is the specific bits needed for an ALU instruction:
    ALUopcode = {Instruction[30], Instruction[14:12]};


    //now that the predetermined signals are defined, all possible opcodes can be considered
    
    
    
    
    case(opcode)

    //this is the case for all arithmatic operations doing only register operations
    7'b0110011:begin

        //addresses, because no immidiate operands, all register addresses are used
        assign RdAdd1 = rs1;
        assign RdAdd2 = rs2;
        assign WrAddr = rd;
        //output must be written to the register address
        assign RegWrite = 1'b1;
        //ALU takes input from the registers on ALU_Mux
        assign ALUsrc = 1'b0;
        //Opcode is defined above 
        assign ALUctrl = ALUopcode;
        //result should come from ALU, not memory
        assign ResultSrc = 1'b0;
        //PC is next address, no jump occurred
        assign PCSrc = 1'b0;

        //no immidiates are being used here, so can connect them, but nothing will happen
        assign ImmOp = Imm;
        assign Immsrc = 3'b000;
        //not writing to memory
        assign MemWrite = 0'b0;
        //output only needed for x[rd] = PC + upImm
        assign PC = {(PCWIDTH){1'b0}};

    end


    //this is the case for all arithmatic operations doing Immidiate Operations
    7'b0010011: begin

        //addresses, because no immidiate operands, all register addresses are used
        assign RdAdd1 = rs1;
        //rs2 will not be selected so is irrelevant
        assign RdAdd2 = r0;
        assign WrAddr = rd;
        //output must be written to the register address
        assign RegWrite = 1'b1;
        //ALU takes input from the Immidiate Extend on ALU_Mux
        assign ALUsrc = 1'b1;
        //Opcode is defined above 
        assign ALUctrl = {1'b0, branchcode};
        //result should come from ALU, not memory
        assign ResultSrc = 1'b0;
        //PC is next address, no jump occurred
        assign PCSrc = 1'b0;

        //no immidiates are being used here, so can connect them, but nothing will happen
        assign ImmOp = Imm;
        //selecting the immidiate for ALU
        assign Immsrc = 3'b000;
        //not writing to memory
        assign MemWrite = 0'b0;
        //output only needed for x[rd] = PC + upImm
        assign PC = {(PCWIDTH){1'b0}};

    end

    //this is the case for all Store Operation
    7'b0100011: begin

        //memory address register location
        assign RdAdd1 = rs1;
        //data to be stored
        assign RdAdd2 = rs2;
        //not writing so doesnt matter
        assign WrAddr = r0;
        //no need to write becasue are storing in memory not registers
        assign RegWrite = 1'b0;
        //ALU is reading immidiate for offset
        assign ALUsrc = 1'b0;
        //need to add, such that offset + r2 equals address. instruction gives 010, dont know why, so doing manually
        assign ALUctrl = 4'b0000;
        //doesnt matter, but make data output be value stored to make debugging easier
        assign ResultSrc = 1'b1;
        //no jumps occurring
        assign PCSrc = 1'b0;
        //pass whole immidiate value
        assign ImmOp = Imm;
        //want just the store bits
        assign Immsrc =3'b010;
        //write to memory
        assign MemWrite = 1'b1;
        //output only needed for x[rd] = PC + upImm
        assign PC = {(PCWIDTH){1'b0}};

    end

    //this is the case for all Load Operations
    7'b0000011: begin

        //memory address register location
        assign RdAdd1 = rs1;
        //doesn't matter as immidiate operand is being used
        assign RdAdd2 = r0;
        //storage register address location
        assign WrAddr = rs2;
        //writing value to a register, so need to enable Write Enable
        assign RegWrite = 1'b1;
        //ALU is reading immidiate for offset
        assign ALUsrc = 1'b1;
        //use ALU code because it doesnt change the output
        assign ALUctrl = 4'b0000;
        //Value needs to be stored into the register designated in rs2, need input from data memory
        assign ResultSrc = 1'b1;
        //no jumps occurring
        assign PCSrc = 0'b0;
        //pass whole immidiate value
        assign ImmOp = Imm;
        //want the immidiate for the load instruction
        assign Immsrc = 3'b100;
        //need to write to data memory
        assign MemWrite = 1'b1;
        //output only needed for x[rd] = PC + upImm
        assign PC = {(PCWIDTH){1'b0}};

    end

    //this is the case for the JAL operation
    7'b1101111: begin

        //read data from register 1 (doesnt matter)
        assign RdAdd1 = rs1;
        //read data from register 2 (doesnt matter)
        assign RdAdd2 = rs2;
        //write new PC to register rd
        assign WrAddr = rd;
        //need to write return address to register
        assign RegWrite = 1'b1;
        //ALU is cut off from calculations due to the jump_calc Block
        assign ALUsrc = 1'b1;
        //ALU is cut off from calculations due to the jump_calc Block
        assign ALUctrl = 4'b0;
        //doesnt matter as not being stored anywhere
        assign ResultSrc = 1'b0;
        //get new PC value from the Jump_calc Module
        assign PCSrc = 1'b1;
        //want the Immidiate to be calculated 
        assign ImmOp = Imm;
        //Need Immidiate for offset, use the specific command for Jump instructions
        assign Immsrc = 3'b011;
        //not writing to memory
        assign MemWrite = 1'b0;
        //output only needed for x[rd] = PC + upImm
        assign PC = {(PCWIDTH){1'b0}};

    end

/*Decided that this wouldn't be implemented on our cpu
        //this is the case for the JALr operation
        //this is a jump to  a new destination from a register.
    7'b1100111: begin

        //read data from register 1 ( pc = x[r1] + immOp)
        assign RdAdd1 = ;
        //
        assign RdAdd2 = ;
        //
        assign WrAddr = ;
        //
        assign RegWrite = ;
        //
        assign ALUsrc = ;
        //
        assign ALUctrl = ;
        //
        assign ResultSrc = ;
        //
        assign PCSrc = ;
        //
        assign ImmOp = ;
        //
        assign Immsrc = ;
        //
        assign MemWrite = ;
        //
        assign PC = ;

    end

*/

    //this is the case for Load Upper Immidiate Operations (Store the upper immidiate in rd)
    //note add upper immidiate is just an add opperation (use add to do it)
    7'b0110111: begin

        //this is ALUop1, so needs to be 0 as adding 0 + upImm = upImm, which needs to be stored in rd
        assign RdAdd1 = r0;
        //doesn't matter as immidiate operand is being used 
        assign RdAdd2 = r0;
        //storage register address location
        assign WrAddr = rd;
        //writing value to a register, so need to enable Write Enable
        assign RegWrite = 1'b1;
        //ALU is reading immidiate for offset
        assign ALUsrc = 1'b1;
        //use ALU code because it doesnt change the output
        assign ALUctrl = 4'b0000;
        //No use for data memory
        assign ResultSrc = 1'b0;
        //no jumps occurring
        assign PCSrc = 0'b0;
        //pass whole immidiate value
        assign ImmOp = Imm;
        //want the immidiate for the upper Immidiate
        assign Immsrc = 3'b001;
        //not writing to memory
        assign MemWrite = 1'b0;
        //output only needed for x[rd] = PC + upImm
        assign PC = {(PCWIDTH){1'b0}};

    end

    //this is the case for Add upper immidiate to PC (x[rd] = PC + upImm) NOTE: This does not jump
    7'b0010111: begin

        //this is ALUop1, so needs to be 0 as adding 0 + upImm + PC = upImm + PC, which needs to be stored in rd
        assign RdAdd1 = r0;
        //doesn't matter as immidiate operand is being used 
        assign RdAdd2 = r0;
        //storage register address location
        assign WrAddr = rd;
        //writing value to a register, so need to enable Write Enable
        assign RegWrite = 1'b1;
        //ALU is reading immidiate for offset
        assign ALUsrc = 1'b1;
        //use ALU code because it doesnt change the output
        assign ALUctrl = 4'b0000;
        //No use for data memory
        assign ResultSrc = 1'b0;
        //no jumps occurring
        assign PCSrc = 0'b0;
        //pass whole immidiate value
        assign ImmOp = Imm;
        //want the immidiate for the upper Immidiate
        assign Immsrc = 3'b001;
        //not writing to memory
        assign MemWrite = 1'b0;
        //need to subtract 4 because input is PC_next, which has 4 added to it
        assign PC = PC_next - {{(PCWIDTH-4){1'b0}}, 4'b0100};

    end


    //BRANCH INSTRUCTIONS NOTE:::: 
    /*
    To do a branch condition, the ZERO flag needs to be set, else the branch instruction wont operate as intended.
    Above each case/instruction is the function that needs to be run the step BEFORE the branch instruction. These
    instructions are the conditionals in the "if statements" on the branch instructions

    Each branch instruction also has conditionals inside them, as the decode block determines wether to jump or not

    --SOMEONE CHECK --
    The instruction can actually be completed in the same cycle because the instruction is done, zero flag is set, then theres
    technically a small delay, but then the zero flag is set. and PC is changed on the next cycle

    */

    //this is the opcode for a branch instruction
    7'b1100011: begin

        //all branch instructions have their own branchcode, but the same opcode
        case(branchcode)
        //This is the beq, branch equal, the test is r1 r2 rd => x[rd] = x[r1] - x[r2].
        //Thus, if ZERO = 1, they are equal, else they are not equal
        3'b000: begin
            
            //the two registers in question
            assign RdAdd1 = rs1;
            assign RdAdd2 = rs2;

            //not writing so set to 0
            assign WrAddr = r0;
            assign RegWrite = 1'b0;

            //ALU instruction can be completed the same cycle, just ignore a small delay
            // need to do rs2 - rs1 to see if they are equal
            //using register not immidiate  
            assign ALUsrc = 1'b0;
            assign ALUctrl = 4'b1000;
            //want result from ALU
            assign ResultSrc = 1'b0;

            //if zero = 1, PCsrc = jump output
            assign PCSrc = (ZERO == 1) ? 1'b1 : 1'b0;

            //pass the immidiate and take the immidiate for branch instructions
            assign ImmOp = Imm;
            assign Immsrc = 3'b111;

            //not writing to memory
            assign MemWrite = 1'b0;
            ////output only needed for instruction x[rd] = PC + upImm
            assign PC = {(PCWIDTH){1'b0}};

        end

        //This is the bne, branch equal, the test is r1 r2 rd => x[rd] = x[r1] - x[r2].
        //Thus, if ZERO = 0, they are equal, else they are not equal
        3'b001: begin
            
            //the two registers in question
            assign RdAdd1 = rs1;
            assign RdAdd2 = rs2;

            //not writing so set to 0
            assign WrAddr = r0;
            assign RegWrite = 1'b0;

            //ALU instruction can be completed the same cycle, just ignore a small delay
            // need to do rs2 - rs1 to see if they are equal
            //using register not immidiate  
            assign ALUsrc = 1'b0;
            assign ALUctrl = 4'b1000;
            //want result from ALU
            assign ResultSrc = 1'b0;

            //if zero = 1, PCsrc = jump output
            //this is the only change from beq
            assign PCSrc = (ZERO == 1) ? 1'b0 : 1'b1;

            //pass the immidiate and take the immidiate for branch instructions
            assign ImmOp = Imm;
            assign Immsrc = 3'b111;

            //not writing to memory
            assign MemWrite = 1'b0;
            ////output only needed for instruction x[rd] = PC + upImm
            assign PC = {(PCWIDTH){1'b0}};

        end

        //This is the blt, branch less than (signed), the test is r1 r2 rd => x[rd] = x[r1] < x[r2].
        //Thus, if ZERO = 1, x[r1] < x[r2], PCsrc = jump output
        3'b100: begin
            
            //the two registers in question
            assign RdAdd1 = rs1;
            assign RdAdd2 = rs2;

            //not writing so set to 0
            assign WrAddr = r0;
            assign RegWrite = 1'b0;

            //ALU instruction can be completed the same cycle, just ignore a small delay
            // need to do rs2 < rs1 to see if they are equal
            //using register not immidiate  
            assign ALUsrc = 1'b0;
            assign ALUctrl = 4'b0010;
            //want result from ALU
            assign ResultSrc = 1'b0;

            //if zero = 1, x[r1] > x[r2], PCsrc = jump output
            assign PCSrc = (ZERO == 1) ? 1'b1 : 1'b0;

            //pass the immidiate and take the immidiate for branch instructions
            assign ImmOp = Imm;
            assign Immsrc = 3'b111;

            //not writing to memory
            assign MemWrite = 1'b0;
            ////output only needed for instruction x[rd] = PC + upImm
            assign PC = {(PCWIDTH){1'b0}};

        end

        //This is the blt, branch less than (signed), the test is r1 r2 rd => x[rd] = x[r1] < x[r2].
        //Thus, if ZERO = 1, x[r1] < x[r2], PCsrc = jump output
        3'b110: begin
            
            //the two registers in question
            assign RdAdd1 = rs1;
            assign RdAdd2 = rs2;

            //not writing so set to 0
            assign WrAddr = r0;
            assign RegWrite = 1'b0;

            //ALU instruction can be completed the same cycle, just ignore a small delay
            // need to do rs1 > rs2 (signed) to see if they are equal
            //using register not immidiate  
            assign ALUsrc = 1'b0;
            assign ALUctrl = 4'b0011;
            //want result from ALU
            assign ResultSrc = 1'b0;

            //if zero = 1, x[r1] > x[r2], PCsrc = jump output
            assign PCSrc = (ZERO == 1) ? 1'b1 : 1'b0;

            //pass the immidiate and take the immidiate for branch instructions
            assign ImmOp = Imm;
            assign Immsrc = 3'b111;

            //not writing to memory
            assign MemWrite = 1'b0;
            ////output only needed for instruction x[rd] = PC + upImm
            assign PC = {(PCWIDTH){1'b0}};

        end

        //these are the greater than/equal to branches, which is just the opposite of the less than branches
        //this means theyre the same with the opposite "assign PCSrc = ... " lines


        //This is the bge, branch greater than (signed), the test is r1 r2 rd => x[rd] = x[r1] > x[r2].
        //Thus, if ZERO = 1, x[r1] > x[r2], PCsrc = jump output
        3'b100: begin
            
            //the two registers in question
            assign RdAdd1 = rs1;
            assign RdAdd2 = rs2;

            //not writing so set to 0
            assign WrAddr = r0;
            assign RegWrite = 1'b0;

            //ALU instruction can be completed the same cycle, just ignore a small delay
            // need to do rs2 < rs1 to see if they are equal
            //using register not immidiate  
            assign ALUsrc = 1'b0;
            assign ALUctrl = 4'b0010;
            //want result from ALU
            assign ResultSrc = 1'b0;

            //if zero = 1, x[r1] > x[r2], PCsrc = jump output
            assign PCSrc = (ZERO == 1) ? 1'b0 : 1'b1;

            //pass the immidiate and take the immidiate for branch instructions
            assign ImmOp = Imm;
            assign Immsrc = 3'b111;

            //not writing to memory
            assign MemWrite = 1'b0;
            ////output only needed for instruction x[rd] = PC + upImm
            assign PC = {(PCWIDTH){1'b0}};

        end

        //This is the bgeu, branch greater than (unsigned signed), the test is r1 r2 rd => x[rd] = x[r1] < x[r2].
        //Thus, if ZERO = 1, x[r1] > x[r2], PCsrc = jump output
        3'b110: begin
            
            //the two registers in question
            assign RdAdd1 = rs1;
            assign RdAdd2 = rs2;

            //not writing so set to 0
            assign WrAddr = r0;
            assign RegWrite = 1'b0;

            //ALU instruction can be completed the same cycle, just ignore a small delay
            // need to do rs1 < rs2 (signed) to see if they are equal
            //using register not immidiate  
            assign ALUsrc = 1'b0;
            assign ALUctrl = 4'b0011;
            //want result from ALU
            assign ResultSrc = 1'b0;

            //if zero = 1, x[r1] > x[r2], PCsrc = jump output
            assign PCSrc = (ZERO == 1) ? 1'b0 : 1'b1;

            //pass the immidiate and take the immidiate for branch instructions
            assign ImmOp = Imm;
            assign Immsrc = 3'b111;

            //not writing to memory
            assign MemWrite = 1'b0;
            ////output only needed for instruction x[rd] = PC + upImm
            assign PC = {(PCWIDTH){1'b0}};

        end




        //default function is add 0 to r0, but does not write to data memory
        //so an invalid opcode is another way of doing a noOp
        default: begin

            assign RdAdd1 = {(RDADDR1W){1'b0}};
            assign RdAdd2 = {(RDADDR1W){1'b0}};
            assign WrAddr = {(WRADDRW){1'b0}};
            assign RegWrite = 1'b0;
            assign ALUsrc = 1'b1;
            assign ALUctrl = 4'b0;
            assign ResultSrc = 1'b0;
            assign PCSrc = 1'b0;
            assign ImmOp = 25'b0;
            assign Immsrc = 3'b000;
            assign MemWrite = 0'b0;
            assign PC = {(PCWIDTH){1'b0}};

        end

        endcase
    end



    //default function is add 0 to r0, but does not write to data memory
    //so an invalid opcode is another way of doing a noOp
    default: begin

        assign RdAdd1 = {(RDADDR1W){1'b0}};
        assign RdAdd2 = {(RDADDR1W){1'b0}};
        assign WrAddr = {(WRADDRW){1'b0}};
        assign RegWrite = 1'b0;
        assign ALUsrc = 1'b1;
        assign ALUctrl = 4'b0;
        assign ResultSrc = 1'b0;
        assign PCSrc = 1'b0;
        assign ImmOp = 25'b0;
        assign Immsrc = 3'b000;
        assign MemWrite = 0'b0;
        assign PC = {(PCWIDTH){1'b0}};

    end
    endcase

    


end

endmodule
