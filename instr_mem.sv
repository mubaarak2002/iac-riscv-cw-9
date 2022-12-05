module instr_mem #(
    parameter ADDRESS_WIDTH=16, 
                DATA_WIDTH = 32
)(
    input logic [ADDRESS_WIDTH-1:0]     PC,
    output logic [DATA_WIDTH-1:0]    instr
);


logic [DATA_WIDTH-1:0]  rom_array   [2**ADDRESS_WIDTH-1:0];

initial begin
        $readmemh("instr.mem", rom_array);
end;

always_comb begin 
    instr = rom_array[PC];
end

endmodule
