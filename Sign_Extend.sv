module Sign_Extend #(
    parameter   DATA_WIDTH = 32
)(
    input logic [2:0]               ImmSel,
    input logic [DATA_WIDTH-1:7]    Imm,
    output logic [DATA_WIDTH-1:0]   ImmExt
);

//3 bit input to determine what Imm to use (see photo on OneNote)
// PC is also input here only for the auipc instruction (x[rd] = PC + upImm)

/*
000: 31:20, normal Imm for ALU
001: 31:12, upper Immidiate
010: 31:25, store Immidiate
100: Load Instructions
011: 30:21 and 19:12, jump store (see Lecture 6 slide 25)
111: branch instructions
*/
always_comb begin
    case (ImmSel)
    3'b000: ImmExt = {{20{Imm[31]}}, Imm[31:20]};
    3'b001: ImmExt = {Imm[31:12], {12{1'b0}}};
    3'b010: ImmExt = {{20{Imm[31]}}, Imm[31:25], Imm[11:7]};
    3'b100: ImmExt = {{20{Imm[31]}}, Imm[31:20]};
    3'b011: ImmExt = {{12{Imm[31]}}, Imm[19:12], Imm[20], Imm[30:21], {1'b0}};
    3'b111: ImmExt = {{20{Imm[31]}}, Imm[7], Imm[30:25], Imm[11:8], {1'b0}};
    default: ImmExt = {{20{Imm[31]}}, Imm[31:20]};
    endcase
end

endmodule
