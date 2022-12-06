module instr_mem #(
    parameter ADDRESS_WIDTH=16, 
                DATA_WIDTH = 32
)(
    input logic [ADDRESS_WIDTH-1:0]     PC,
    output logic [DATA_WIDTH-1:0]    instr
);

    logic [7:0]  instrByte1;
    logic [7:0]  instrByte2;
    logic [7:0]  instrByte3;
    logic [7:0]  instrByte4;


logic [7:0]  rom_array   [2**ADDRESS_WIDTH-1:0];
//logic [DATA_WIDTH-1:0]  rom_array   [5:0];

initial begin
        $readmemh("instr.mem", rom_array);
end

always_comb begin 
    instrByte1 = rom_array[PC];
    instrByte2 = rom_array[PC+1];
    instrByte3 = rom_array[PC+2];
    instrByte4 = rom_array[PC+3];
    instr = {instrByte4, instrByte3, instrByte2, instrByte1};
end

endmodule
