`timescale 1ns / 1ps

module counter_tb;
  reg clk;
  reg rst;
  reg en;
  wire [7:0] count;

  // 1. Instantiate your Post-Layout Netlist (Device Under Test)
  counter uut (
      .clk(clk),
      .rst(rst),
      .en(en),
      .count(count)
  );

  // 2. Load the physical timing delays from OpenROAD directly into the UUT
  initial begin
    $sdf_annotate("counter_layout.sdf", uut);
  end

  // 3. Generate a 50 MHz clock profile (20ns period)
  always #10 clk = ~clk;

  initial begin
    // Setup file dump parameters for GTKWave analysis
    $dumpfile("post_layout_sim.vcd");
    $dumpvars(0, counter_tb);

    // Initial system reset sequence
    clk = 0;
    en  = 0;
    rst = 0;  // Assert Active-Low Reset to clear 'X' states
    #40;
    rst = 1;  // Release Reset

    // Enable Counter increment loop
    #20 en = 1;
    #400;  // Let it count up

    $finish;
  end
endmodule
