module pc_inc #(
    paramater WORD_WIDTH = 32
)(
    input logic  [WORD_WIDTH-1:0] PC,
    output logic [WORD_WIDTH-1:0] PCnew
);

    always_comb begin
        PC_new = PC + 3'b100
    end

endmodule
