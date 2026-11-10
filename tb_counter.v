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
      #3 clk = ~clk;
    end

  end

  initial begin
    $sdf_annotate("./outputs/counter_layout.sdf", dut);
  end

  initial begin
    $monitor("%0t reset: %1b enable: %1b count: %3d", $time, rst, en, count);
  end

  initial begin

    // aqui dice a que archivo vas a meter las ondas y abajo dice que variables vas a meter 
    $dumpfile("post_layout_sim.vcd");
    $dumpvars(0, tb_counter);

    @(negedge clk);
    rst = 0;
    en  = 1;

    @(negedge clk);
    rst = 1;

    repeat (10) @(posedge clk);

    $finish;

  end

endmodule
