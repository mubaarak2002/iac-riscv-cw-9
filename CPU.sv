module CPU #(
    parameter ADDRESS_WIDTH = 5,
            DATA_WIDTH = 32,
            ALUCTRL_WIDTH = 4,
            PC_WIDTH = 16,
            INSTR_WIDTH = 32,
            OPCODEW = 7,
            IMMSELW = 3,
            BRCHCDEW = 3,
            ImmOp = 25
)(
    input logic                   clk,
    input logic                   rst,
    // input logic                   trigger,
    output logic [DATA_WIDTH-1:0] a0,
);

logic [PC_WIDTH-1:0] PC;
logic [PC_WIDTH-1:0] PC_new;
logic [PC_WIDTH-1:0] PC_target;
logic PCsrc;
logic zero;
logic Resultsrc;
logic MemWrite;
logic [DATA_WIDTH-1:0] MemWrAdd;
logic [ADDRESS_WIDTH-1:0] RA1;
logic [DATA_WIDTH-1:0] RD1;
logic [ADDRESS_WIDTH-1:0] RA2;
logic [DATA_WIDTH-1:0] RD2;
logic [ADDRESS_WIDTH-1:0] WA3;
logic [DATA_WIDTH-1:0] WD3;
logic WEn;
logic [INSTR_WIDTH-1:0] Instr;
logic [ALUCTRL_WIDTH-1:0] ALUctrl;
logic ALUsrc;
logic [IMMSELW-1:0] ImmSel;
logic [ImmOp-1:0] ImmOp;
logic [DATA_WIDTH-1:0] ImmExt;



endmodule