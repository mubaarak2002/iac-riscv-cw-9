module reg_file #(
    parameter WORD_WIDTH = 32,
    parameter ADDRESS_WIDTH = 5
)(
    input logic                      clk,
    input logic  [ADDRESS_WIDTH-1:0] RA1, 
    input logic  [ADDRESS_WIDTH-1:0] RA2,
    input logic  [ADDRESS_WIDTH-1:0] WA3,
    input logic  [WORD_WIDTH-1:0]    WD3,
    input logic                      WEN,
    output logic [WORD_WIDTH-1:0]    RD1,
    output logic [WORD_WIDTH-1:0]    RD2
);

    logic [WORD_WIDTH-1:0] rom_array[2**ADDRESS_WIDTH-1:0];

always_ff @(posedge clk) 
begin
    if(WEN) rom_array[WA3] <= WD3;
    RD1 <= rom_array[RA1];
    RD2 <= rom_array[RA2];
end

endmodule
