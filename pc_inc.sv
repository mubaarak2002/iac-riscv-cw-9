module pc_inc #(
    parameter WORD_WIDTH = 32
)(
    input logic  [WORD_WIDTH-1:0] PC,
    output logic [WORD_WIDTH-1:0] PC_new
);

    always_comb begin
        PC_new = PC + {{(29){1'b0}}, 3'b100};
    end

endmodule
