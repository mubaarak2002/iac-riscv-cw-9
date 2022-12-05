module jump_calc #(
    parameter   WIDTH = 32
)(
    input logic [WIDTH-1:0]  PC,
    input logic [WIDTH-1:0]  Imm,
    output logic [WIDTH-1:0] PC_Target
);

    assign PC_Target = PC + Imm;

endmodule
