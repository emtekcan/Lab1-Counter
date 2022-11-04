module counter #(
    parameter WIDTH = 8
)(
    //interface signals
    input logic clk,                //clock
    input logic rst,                //reset
    input logic en,                 //counter enable
    output logic [WIDTH-1:0] count  //count output
);
int stopcounter = 0;

always_ff @ (posedge clk, posedge rst)

    if(rst) begin 
        count <= {WIDTH{1'b0}};
        stopcounter <= 0;
    end
    else begin
        if(stopcounter > 0) stopcounter <= (stopcounter - 1);
        else begin
            if(count == 9) begin
            stopcounter <= 2;
            count <= {WIDTH{1'b0}};
            end

            else count <= count + {{WIDTH-1{1'b0}}, en};
        end

    end

endmodule
