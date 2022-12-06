module instr_mem #(
    parameter ADDRESS_WIDTH=16, 
                DATA_WIDTH = 32
)(
    input logic [ADDRESS_WIDTH-1:0]     ALUresult,
    input logic                         clk, WE,
    input logic [ADDRESS_WIDTH-1:0]     WriteData,
    output logic [DATA_WIDTH-1:0]       ReadData
);


    logic [DATA_WIDTH-1:0]  rom_array   [2**ADDRESS_WIDTH-1:0];

    initial begin
        $readmemh("instr.mem", rom_array);
    end;

    always_ff @(posedge clk) 
        if (WEN) rom_array[ALUresult] = WriteData;

    always_comb
        ReadData = rom_array[ALUresult];

endmodule
