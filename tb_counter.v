`timescale 1ns / 1ps

module tb_counter;


  reg clk;
  reg rst;
  reg en;

  wire [7:0] count;

  counter dut (
      .clk(clk),
      .rst(rst),
      .en(en),
      .count(count)
  );

  initial begin

    clk = 0;

    forever begin
      #5 clk = ~clk;
    end

  end

  initial begin
    $monitor("", rst, en, count);
  end

  initial begin

    @(negedge clk);
    rst = 0;
    en  = 1;

    @(negedge clk);
    rst = 1;

    repeat (10) @(posedge clk);

    $finish;

  end

endmodule
