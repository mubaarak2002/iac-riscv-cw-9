module cpu #(
    parameter ADDRESS_WIDTH = 5,
    parameter DATA_WIDTH = 32,
    parameter INSTR_WIDTH = 32,
    //remove if I forget to remove this <3 - Omar
    //parameter ADDRESS_WIDTH = 32,
    parameter PC_WIDTH = 32,
    parameter ALUCTRL_WIDTH = 4,
    parameter IMMSRC_WIDTH = 3,
    parameter IMMOP_WIDTH = 25


) (

    input logic                   clk, 
    input logic                   rst,

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
    output logic [DATA_WIDTH-1:0]           MemAddr_Out,
    output logic [DATA_WIDTH-1:0]           MemData_Out,

    //All ALU elements (not including system out)
    output logic                        ZERO_Out,

    //All the Decode Elements
    output logic [ADDRESS_WIDTH-1:0]    RA1_Out,
    output logic [ADDRESS_WIDTH-1:0]    RA2_Out,
    output logic                        PCsrc_Out,
    output logic                        Resultsrc_Out,
    output logic                        MemWrite_Out,
    output logic [ALUCTRL_WIDTH-1:0]    ALUctrl_Out,
    output logic                        ALUsrc_Out,
    output logic [IMMSRC_WIDTH-1:0]     Immsrc_Out,
    output logic                        RegWrite_Out,
    output logic [IMMOP_WIDTH-1:0]      ImmOp_Out,
    output logic [PC_WIDTH-1:0]         Decode_PC_Out,
    output logic [ADDRESS_WIDTH-1:0]    WrAddr_Out,

    //system output
    output logic [DATA_WIDTH-1:0]       Data_Out

    
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
logic [IMMSRC_WIDTH-1:0] ImmSel;
logic [IMMOP_WIDTH-1:0] ImmOp;
logic [DATA_WIDTH-1:0] ImmExt;
logic [DATA_WIDTH-1:0] ALU_OP2;
logic [DATA_WIDTH-1:0] ALU_Result;
logic [DATA_WIDTH-1:0] DOut;
logic [DATA_WIDTH-1:0] Memory_Read;



//all the internal signals:
//all are labled with the format <beginningConnection>_<endConnection>

//All are done with internal signals, such that the outputs can be assigned in the combinational loops



mux_2 PC_Mux (

    .option0  (PC_new),
    .option1  (PC_target),
    .sel      (PCsrc),
    .dout     (PC_to_PCreg)

);

PC_reg PCreg (

    .clk          (clk),
    .rst          (rst),
    .New_PC       (PC_Next_Cycle),
    .Current_PC   (PC_to_PCreg)

);

instr_mem PCMem (

    .PC       (PC_Next_Cycle),
    .instr    (Instr)

);

pc_inc PCInc (

    .PC       (PC_Next_Cycle),
    .PC_new   (PC_new)

);

Decode Decoder (

    .Instruction  (Instr),
    .ZERO         (zero),
    .PC_next      (PC_new),
    .ALUctrl      (ALUctrl),
    .ALUsrc       (ALUsrc),
    .ResultSrc    (Resultsrc),
    .RdAdd1       (RA1),
    .RdAdd2       (RA2),
    .WrAddr       (WA3),
    .RegWrite     (WEn),
    .MemWrite     (MemWrite),
    .ImmOp        (ImmOp),
    .Immsrc       (ImmSel),
    .PC           (PC_to_Extend),
    .PCSrc        (PCsrc)

);

reg_file RegFile (

    .clk      (clk),
    .RA1      (RA1),
    .RA2      (RA2),
    .WA3      (WA3),
    .WD3      (DOut),
    .WEN      (WEn),
    .RD1      (RD1),
    .RD2      (RD2)


);

Sign_Extend SignExt (

    .ImmSel   (ImmSel),
    .Imm      (ImmOp),
    .ImmExt   (ImmExt)

);

mux_2 ALUMux (

    .option0  (RD2),
    .option1  (ImmExt),
    .sel      (ALUsrc),
    .dout     (ALU_OP2)

);

ALU ALU (

    .ALUCtrl  (ALUctrl),
    .ALUop1   (RD1),
    .ALUop2   (ALU_OP2),
    .SUM      (ALU_Result),
    .ZERO     (zero)

);

Data_Memory MemFile (
    .ALUresult    (Data_Out),
    .clk          (clk),
    .WEN           (MemWrite),
    .WriteData    (RD2),
    .ReadData     (Memory_Read)
);

mux_2 DoutMux (

    .option0  (ALU_Result),
    .option1  (Memory_Read),
    .sel      (Resultsrc),
    .dout     (DOut)

);



always_comb begin


//Assigning all the debugging output
assign ImmExt_Out = ImmExt;
assign PC_Out = PC;
assign PC_Target_Out = PC_target;
assign Instruction_Out = Instr;
assign PC_new_Out = PC_new;
assign RD1_Out = RD1;
assign RD2_Out = RD2;
assign MemAddr_Out = MemWrAdd;
assign MemData_Out = Memory_Read;
assign ZERO_Out = zero;
assign RA1_Out = RA1;
assign RA2_Out = RA2;
assign PCsrc_Out = PCsrc;
assign Resultsrc_Out = Resultsrc;
assign MemWrite_Out = MemWrite;
assign ALUctrl_Out = ALUctrl;
assign ALUsrc_Out = ALUsrc;
assign Immsrc_Out = ImmSel;
assign RegWrite_Out = WEn;
assign ImmOp_Out = ImmOp;
assign Decode_PC_Out = PC_to_PCreg;
assign WrAddr_Out = WA3;
assign Data_Out = DOut;


end


endmodule

