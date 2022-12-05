/*
The ALU unit can perform 10 different operations based on the opcode (ALUCtrl). See the Readme for the details
On the Opcode. The two inputs must have the same input data width (32b), as the ALU does not sign extend. The ALU is 
asyncronous and thus does not have a clocked input. ALUCTRL is 3 bits wide, allowing for 8 commands.
*/

module ALU #(

    //width of both operands
    parameter DATA_WIDTH = 32,
    //width of opcode
    parameter ALUCTRL_WIDTH = 4
    //func3 is the 3 least significant bits of the control code, and then the fifth bit of func7 is the 
    //most significant bit to help differentiate subtract and add, as well as shift right logic and arithmatic

) (

    input logic  [ALUCTRL_WIDTH-1:0]  ALUCtrl,
    input logic  [DATA_WIDTH-1:0]     ALUop1,
    input logic  [DATA_WIDTH-1:0]     ALUop2,
    output logic [DATA_WIDTH-1:0]     SUM,
    output logic                      ZERO

);

//combinational logic so not using always_ff, these are all the different opcodes. SLT sets the output SUM to 1 if
//op1 > op2, else sets it to 0, EQ is 1 if both the operands equal eachother.

always_comb
    begin

    case (ALUCtrl)
        4'b0000: SUM = ALUop1 + ALUop2; //add
        4'b1000: SUM = ALUop1 - ALUop2; //subtract (func7[5] == 1)
        4'b0001: SUM = ALUop1 << ALUop2[4:0]; //shift Left Logical
        //fix for signed 
        4'b0010: SUM = ($signed(ALUop1) < $signed(ALUop2)) ? 32'b1 : 32'b0; //SLT (set less than)
        4'b0011: SUM = (ALUop1 < ALUop2) ? 32'b1 : 32'b0;; //set less than (unsigned)
        4'b0100: SUM = ALUop1 ^ ALUop2; //bitwise XOR
        4'b0101: SUM = ALUop1 >> ALUop2[4:0]; //shift Right Logical
        4'b1101: SUM = ALUop1 >>> ALUip2[4:0]; //shift right arithmatic (func7[5] == 1)
        4'b0110: SUM = ALUop1 | ALUop2;//OR
        4'b0111: SUM = ALUop1 & ALUop2;//and
        default: SUM = 32'b0;


    endcase

    //setting ZERO
    if (SUM == 32'b0) assign ZERO = 1'b1;
    else assign ZERO = 1'b0;

 
    end



endmodule
