module ProgramCounter#(
    //PC width
    parameter PC_WIDTH = 16
)(
    input logic     clk, rst,
    input logic     [1:0] PCsrc,
    input logic     [PC_WIDTH-1:0] PC_Target,
    input logic     [31:0]         Return,
    output logic    [PC_WIDTH-1:0] PC,
    output logic    [PC_WIDTH-1:0] inc_PC
);

    logic [PC_WIDTH-1:0] branch_PC;
    logic [PC_WIDTH-1:0] next_PC;
    
    //Adders. Uses combinational logic.
    always_comb begin
        inc_PC = PC + {{(PC_WIDTH-3){1'b0}}, 3'b100};
        branch_PC = PC_Target;
    end

    //multiplexer, uses combinational logic. Selects either a branch or PC + 4.

    always_comb begin
        case (PCsrc)
        2'b00: next_PC = inc_PC;
        2'b01: next_PC = branch_PC;
        2'b10: next_PC = Return[PC_WIDTH-1:0];
        2'b11: next_PC = inc_PC;
        endcase
    end
    
    //PC register. Synchronous with an asynchronous reset
    always_ff @(posedge clk, posedge rst)
        if (rst) PC <= {PC_WIDTH{1'b0}};
        else PC <= next_PC;

endmodule
