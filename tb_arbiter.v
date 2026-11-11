module tb_arbiter;

  reg  clk;
  reg  rstb;

  reg  request0;
  reg  request1;
  reg  request2;
  reg  request3;

  reg  end_transaction0;
  reg  end_transaction1;
  reg  end_transaction2;
  reg  end_transaction3;

  wire grant0;
  wire grant1;
  wire grant2;
  wire grant3;

  arbiter a (

      .clk (clk),
      .rstb(rstb),

      .request0(request0),
      .request1(request1),
      .request2(request2),
      .request3(request3),

      .end_transaction0(end_transaction0),
      .end_transaction1(end_transaction1),
      .end_transaction2(end_transaction2),
      .end_transaction3(end_transaction3),

      .grant0(grant0),
      .grant1(grant1),
      .grant2(grant2),
      .grant3(grant3)

  );

  // initial begin
  //   $monitor();
  // end

  initial begin
    clk = 0;
    forever #10 clk = ~clk;
  end

  initial begin

    $dumpfile("simulation.vcd");
    $dumpvars(0, tb_arbiter);

    // clk=0,
    rstb = 0;

    request0 = 0;
    request1 = 0;
    request2 = 0;
    request3 = 0;

    end_transaction0 = 0;
    end_transaction1 = 0;
    end_transaction2 = 0;
    end_transaction3 = 0;

    @(posedge clk);
    @(posedge clk);

    rstb = 1;

    @(posedge clk);

    request0 = 1;

    repeat (5) @(posedge clk);

    end_transaction0 = 1;

    @(posedge clk);

    end_transaction0 = 0;
    request0 = 0;

    repeat (5) @(posedge clk);

    $finish;

  end

endmodule
