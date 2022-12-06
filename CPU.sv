module CPU (

    parameter DATA_WIDTH = 32,
    parameter INSTR_WIDTH = 32,
    parameter ADDRESS_WIDTH = 32,
    parameter PC_WIDTH = 32,
    parameter ALUCTRL_WIDTH = 4,
    parameter IMMSRC_WIDTH = 3,
    parameter IMMOP_WIDTH = 25


)(

    input logic                   clk, rst,

    //these are all the debugging outputs, its all internal signals
    //all will be recorded, and show the ones wanted on GTKWave


    output logic [DATA_WIDTH-1:0]       ImmExt_Out,
    output logic [PC_WIDTH-1:0]         PC_Out,

    //ALl Jump_Calc, PCReg, and PC/Instruction outputs
    output logic [DATA_WIDTH-1:0]       PC_Target_Out,
    output logic [INSTR_WIDTH-1:0]      Instruction_Out,
    output logic [PC_WIDTH-1:0]         PC_new_Out,

    //All Register File Outputs
    output logic [DATA_WIDTH-1:0]       RD1_Out,
    output logic [DATA_WIDTH-1:0]       RD2_Out,

    //All Memory File Outputs
    output logic [DATA_WIDTH]           MemAddr_Out,
    output logic [DATA_WIDTH]           MemData_Out,

    //All ALU elements (not including system out)
    output logic                        ZERO_Out,

    //All the Decode Elements
    output logic [ADDRESS_WIDTH-1:0]    AD1_Out,
    output logic [ADDRESS_WIDTH-1:0]    AD2_Out,
    output logic                        PCsrc_Out,
    output logic                        Resultsrc_Out,
    output logic                        MemWrite_Out,
    output logic [ALUCTRL_WIDTH-1:0]    ALUctrl_Out,
    output logic                        ALUsrc_Out,
    output logic [IMMSRC_WIDTH-1:0]     Immsrc_Out,
    output logic                        RegWrite_Out,
    output logic [IMMOP_WIDTH=1:0]      ImmOp_Out,
    output logic [PC_WIDTH-1:0]         Decode_PC_Out,
    output logic [ADDRESS_WIDTH-1:0]    WrAddr_Out,



    output logic [DATA_WIDTH-1:0]   Out

    

);


//all the internal signals:
//all are labled with the format <beginningConnection>_<endConnection>

//All are done with internal signals, such that the outputs can be assigned in the combinational loops
logic PCMuxDout_InstrMemAddr;



PC_Mux mux_2 (

);

InstrMem instr_mem (

);

PCInc pc_inc (

);

Decode Decode (

);

RegFIle reg_file (

);

SignExt Sign_Extend (

);

ALUMux mux_2 (

);

ALU ALU (

);

MemFile instr_mem (

);

DoutMux mux_2 (

);




always_comb begin


//Assigning all the debugging output

end


endmodule