module no_reset;

  reg clk;
  reg reset_counter;

  d_flip_flop_noreset a (
      .clk(clk),
      .reset_counter(reset_counter)
  );

  initial begin

    clk = 0;

    forever begin
      #10 clk = ~clk;
    end

  end

  initial begin

    $dumpfile("simulation.vcd");
    $dumpvars(0, no_reset);

    reset_counter = 0;

    @(posedge clk);

    reset_counter = 1;

    @(posedge clk);

    reset_counter = 0;

    @(posedge clk);

    repeat (4) @(posedge clk);

    @(posedge clk);

    reset_counter = 1;

    @(posedge clk);

    reset_counter = 0;

    repeat (4) @(posedge clk);

    $finish;

  end


endmodule
