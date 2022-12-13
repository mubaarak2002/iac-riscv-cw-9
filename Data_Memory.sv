module Data_Memory #(
    parameter ADDRESS_WIDTH=20, 
                DATA_WIDTH = 32
)(
    input logic [DATA_WIDTH-1:0]     ALUresult,
    input logic                         clk, WEN,
    input logic [DATA_WIDTH-1:0]     WriteData,
    output logic [DATA_WIDTH-1:0]       ReadData
);

    logic [DATA_WIDTH-1:0]  ram_array   [2**ADDRESS_WIDTH-1:0];
    logic [ADDRESS_WIDTH-1:0] addr;

    initial begin
        $readmemh("sine.mem", ram_array, 65536);
    end

    always_ff @(posedge clk) begin
        if (WEN) ram_array[addr] <= WriteData;
    end

    always_comb begin
        addr = ALUresult[ADDRESS_WIDTH-1:0];
        ReadData = ram_array[addr];
    end


endmodule
