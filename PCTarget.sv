module PCTarget#(
    //PC width
    parameter PC_WIDTH = 16,
    parameter DATA_WIDTH = 32
)(
    input logic      [DATA_WIDTH-1:0] ImmExt,
    input logic      [PC_WIDTH-1:0] PC,
    output logic     [PC_WIDTH-1:0] PC_Target
);

    always_comb begin
        PC_Target = PC + ImmExt[PC_WIDTH-1:0];
    end

endmodule
