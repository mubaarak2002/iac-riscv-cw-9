/*
This register is syncronous to a clock cycle, both the read and write outputs/inputs will only update on a 
positive clock edge. The read ports will not update asyncronously. a0 is the value of the most recently written
item, which is really the most recent output of the ALU, because as long as WEN = 1, the output of the ALU will equal
the most recently written value.
*/

module regFile #(

    //Not the Address and data widths are not equal
    parameter DATA_WIDTH = 32,
    parameter ADDRESS_WIDTH = 5

)(

    input logic                         clk,
    input logic                         WE3,
    input logic   [ADDRESS_WIDTH-1:0]   AD1,
    input logic   [ADDRESS_WIDTH-1:0]   AD2,
    input logic   [ADDRESS_WIDTH-1:0]   AD3,
    input logic   [DATA_WIDTH-1:0]      WD3,
    output logic  [DATA_WIDTH-1:0]      RD1,
    output logic  [DATA_WIDTH-1:0]      RD2,
    output logic  [DATA_WIDTH-1:0]      a0

);

logic [DATA_WIDTH-1:0] rom_array[2**ADDRESS_WIDTH-1:0];

always_ff @(posedge clk) begin

    RD1 <= rom_array[AD1];
    RD2 <= rom_array[AD2];
    a0 <= rom_array[AD3];
    if (WE3) rom_array[AD3] <= WD3;


end

endmodule
