module PC_reg #(
    
    parameter DATA_WIDTH = 32

) (
    input logic                    clk, 
    //change back to one line once its working
    input logic                    rst,
    input logic  [DATA_WIDTH-1:0]  New_PC,
    output logic [DATA_WIDTH-1:0]  Current_PC 
);



always_ff @(posedge clk) begin

    //(rst) ? Current_PC <= 32'b0 : Current_PC <= New_PC;

    if (rst) Current_PC <= 32'b0;
    else Current_PC <= New_PC;

end
    
endmodule


