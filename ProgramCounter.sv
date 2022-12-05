module ProgramCounter#(
    //PC width
    parameter PC_WIDTH = 32,
    parameter DATA_WIDTH = 32
)(
    input logic     clk, rst,
    input logic     PCsrc,
    input logic     [DATA_WIDTH-1:0] ImmOp,
    output logic    [PC_WIDTH-1:0] PC
);

    //Adders. Uses combinational logic.
    logic [PC_WIDTH-1:0] inc_PC = PC + {{(DATA_WIDTH-3){1'b0}}, 3'b100};
    logic [PC_WIDTH-1:0] branch_PC = ImmOp + PC;
    logic [PC_WIDTH-1:0] next_PC;
    
    //multiplexer, uses combinational logic. Selects either a branch or PC + 4.
    always_comb begin
    if (PCsrc) next_PC = branch_PC;
    else next_PC = inc_PC;
    end
    
    //PC register. Synchronous with an asynchronous reset
    always_ff @(posedge clk, posedge rst)
        if (rst) PC <= {PC_WIDTH{1'b0}};
    else PC <= next_PC;

endmodule
