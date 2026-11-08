
`default_nettype none

module counter (

    input wire clk,
    input wire rst,
    input wire en,

    output reg [7:0] count

);

  always @(posedge clk) begin

    if (!rst) begin
      count <= 8'b0;
    end else if (en) begin
      count <= count + 1;
    end

  end

endmodule

// en el 5 esta el posedge clk
// en el primer negedge clk es al 10
// posedge clk 0 1 0
