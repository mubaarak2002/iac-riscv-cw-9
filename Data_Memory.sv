module Data_Memory #(
    parameter ADDRESS_WIDTH=16, 
                DATA_WIDTH = 32
)(
    input logic [DATA_WIDTH-1:0]     ALUresult,
    input logic                         clk, WEN,
    input logic [DATA_WIDTH-1:0]     WriteData,
    output logic [DATA_WIDTH-1:0]       ReadData
);


    logic [DATA_WIDTH-1:0]  rom_array   [2**ADDRESS_WIDTH-1:0];

    initial begin
        $readmemh("f1_tests.s.hex", rom_array);
    end;

    always_ff @(posedge clk) begin
        if (WEN) rom_array[ALUresult[ADDRESS_WIDTH-1:0]] <= WriteData;
        ReadData <= rom_array[ALUresult[ADDRESS_WIDTH-1:0]];
    end


endmodule
