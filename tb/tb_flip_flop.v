module tb_flip_flop;

  reg clk;
  reg rstb;
  reg a;

  d_flip_flop d_flip_flop0 (
      .clk(clk),
      .rstb(rstb),
      .a(a)
  );

  initial begin
    clk = 0;
    forever #10 clk = ~clk;
  end

  initial begin
    $dumpfile("simulation.vcd");
    $dumpvars(0, tb_flip_flop);

    @(posedge clk);
    @(posedge clk);

    rstb = 0;
    a = 0;

    @(posedge clk);
    @(posedge clk);

    #1;

    rstb = 1;
    a = 1;

    repeat (5) @(posedge clk);

    $finish;

  end

endmodule
