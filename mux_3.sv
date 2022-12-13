module mux_3 #(
    parameter DATA_WIDTH = 32,
    parameter PC_WIDTH = 16
)(
    input logic [DATA_WIDTH-1:0]  ALU_result, ReadData,
    input logic [PC_WIDTH-1:0] PC,
    input logic [1:0]             sel,
    output logic [DATA_WIDTH-1:0] dout
);

    always_comb begin
        case (sel)
        2'b00: dout = ALU_result;
        2'b01: dout = ReadData;
        2'b10: dout = {{16{1'b0}}, PC};
        2'b11: dout = ALU_result;
        endcase
    end
        
endmodule
