module pc_inc #(
    parameter PC_WIDTH = 16
)(
    input logic  [PC_WIDTH-1:0] PC,
    output logic [PC_WIDTH-1:0] PC_new
);

    always_comb begin
        PC_new = PC + {{(13){1'b0}}, 3'b100};
    end

endmodule
