module Sign_Extend (


) (

//3 bit input to determine what Imm to use (see photo on OneNote)
// PC is also input here only for the auipc instruction (x[rd] = PC + upImm)

/*

000: 31:20, normal Imm for ALU
001: 31:12, upper Immidiate
010: 31:25, store Immidiate
100: Load Instructions
011: 30:21 and 19:12, jump store (see Lecture 6 slide 25)




*/



);

endmodule