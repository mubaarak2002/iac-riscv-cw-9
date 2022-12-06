module mux_2 #(
    parameter WORD_WIDTH = 32
)(
    input logic [WORD_WIDTH-1:0]  option0, option1,
    input logic                   sel,
    output logic [WORD_WIDTH-1:0] dout
);

    assign dout = sel ? option1 : option0;

endmodule
