module mux_3 #(
    parameter DATA_WIDTH = 32
)(
    input logic [DATA_WIDTH-1:0]  option0, option1, option2,
    input logic [1:0]             sel,
    output logic [DATA_WIDTH-1:0] dout
);

    always_comb begin
        case (sel)
        2'b00: dout = option0;
        2'b01: dout = option1;
        2'b10: dout = option2;
        2'b11: dout = option0;
        endcase
    end
        
endmodule
