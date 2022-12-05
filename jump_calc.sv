module jump_calc #(
    parameter   DATA_WIDTH = 32,
    parameter   PC_WIDTH = 16
)(
    input logic [PC_WIDTH-1:0]  PC,
    input logic [DATA_WIDTH-1:0]  Imm,
    output logic [PC_WIDTH-1:0] PC_Target
);

    assign PC_Target = PC + Imm[PC_WIDTH-1:0];

endmodule
