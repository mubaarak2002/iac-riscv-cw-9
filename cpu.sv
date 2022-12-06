module CPU #(
    parameter ADDRESS_WIDTH = 5,
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



    output logic [DATA_WIDTH-1:0]        Out

    
    // input logic                   trigger,

);

//All internal signals
logic [PC_WIDTH-1:0] PC;
logic [PC_WIDTH-1:0] PC_new;
logic [PC_WIDTH-1:0] PC_to_PCreg;
logic [PC_WIDTH-1:0] PC_Next_Cycle;
logic [PC_WIDTH-1:0] PC_target;
logic [PC_WIDTH-1:0] PC_to_Extend;
logic PCsrc;
logic zero;
logic Resultsrc;
logic MemWrite;
logic WEn;
logic [DATA_WIDTH-1:0] MemWrAdd;
logic [ADDRESS_WIDTH-1:0] RA1;
logic [DATA_WIDTH-1:0] RD1;
logic [ADDRESS_WIDTH-1:0] RA2;
logic [DATA_WIDTH-1:0] RD2;
logic [ADDRESS_WIDTH-1:0] WA3;
logic [INSTR_WIDTH-1:0] Instr;
logic [ALUCTRL_WIDTH-1:0] ALUctrl;
logic ALUsrc;
logic [IMMSELW-1:0] ImmSel;
logic [ImmOp-1:0] ImmOp;
logic [DATA_WIDTH-1:0] ImmExt;
logic [DATA_WIDTH-1:0] ALU_OP2;
logic [DATA_WIDTH-1:0] ALU_Result;
logic [DATA_WIDTH-1:0] Data_Out;
logic [DATA_WIDTH-1:0] Memory_Read;



//all the internal signals:
//all are labled with the format <beginningConnection>_<endConnection>

//All are done with internal signals, such that the outputs can be assigned in the combinational loops



PC_Mux mux_2 (

    .(option0)  PC_new,
    .(option1)  PC_target,
    .(sel)      PCsrc,
    .(dout)     PC_to_PCreg

);

PCreg PC_reg (

    .(clk)          clk,
    .(rst)          rst,
    .(New_PC)       PC_Next_Cycle,
    .(Current_PC)   PC_to_PCreg

);

InstrMem instr_mem (

    .(PC)       PC_Next_Cycle,
    .(instr)    Instr

);

PCInc pc_inc (

    .(PC)       PC_Next_Cycle,
    .(PC_new)   PC_new

);

Decode Decode (

    .(Instruction)  Instr,
    .(ZERO)         zero,
    .(PC_next)      PC_new,
    .(ALUctrl)      ALUctrl,
    .(ALUsrc)       ALUsrc,
    .(ResultSrc)    Resultsrc,
    .(RdAdd1)       RA1,
    .(RdAdd2)       RA2,
    .(WrAddr)       WA3,
    .(RegWrite)     WEn,
    .(MemWrite)     MemWrite,
    .(ImmOP)        ImmOP,
    .(Immsrc)       ImmSel,
    .(PC)           PC_to_Extend,
    .(PCSrc)        PCsrc

);

RegFile reg_file (

    .(clk)      clk,
    .(RA1)      RA1,
    .(RA2)      RA2,
    .(WA3)      WA3,
    .(WD3)      Data_Out,
    .(WEN)      WEn,
    .(RD1)      RD1,
    .(RD2)      RD2


);

SignExt Sign_Extend (

    .(ImmSel)   (ImmSel)
    .(PC)       (PC_to_Extend)
    .(Imm)      (ImmOp)
    .(ImmExt)   (ImmExt)

);

ALUMux mux_2 (

    .(option0)  RD2,
    .(option1)  ImmExt,
    .(sel)      ALUsrc,
    .(dout)     ALU_OP2

);

ALU ALU (

    .(ALUCtrl)  ALUctrl,
    .(ALUop1)   RD1,
    .(ALUop2)   ALU_OP2,
    .(SUM)      ALU_Result,
    .(ZERO)     zero

);

MemFile instr_mem (
    .(ALUresult)    Data_Out,
    .(clk)          clk,
    .(WE)           MemWrite,
    .(WriteData)    RD2,
    .(ReadData)     Memory_Read
);

DoutMux mux_2 (

    .(option0)  ALU_Result,
    .(option1)  Memory_Read,
    .(sel)      ResultSrc,
    .(dout)     Data_Out

);



always_comb begin


//Assigning all the debugging output

end


endmodule