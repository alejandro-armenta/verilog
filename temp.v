`timescale 1ns / 1ps

module tb_arbiter;

  // Inputs to the UUT (Unit Under Test)
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

  // Outputs from the UUT
  wire grant0;
  wire grant1;
  wire grant2;
  wire grant3;

  // Instantiate the Unit Under Test (UUT)
  arbiter uut (
      .clk(clk),
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

  // Clock generation (50MHz -> 20ns period)
  always begin
    #10 clk = ~clk;
  end

  // Test sequence
  initial begin
    // Initialize all inputs
    clk = 0;
    rstb = 0;
    request0 = 0;
    request1 = 0;
    request2 = 0;
    request3 = 0;
    end_transaction0 = 0;
    end_transaction1 = 0;
    end_transaction2 = 0;
    end_transaction3 = 0;

    // --- Scenario 1: Reset Sequence ---
    $display("[TB] Applying Reset...");
    #25;
    rstb = 1;  // Release reset out of clock edge
    $display("[TB] Reset Released. FSM should be in IDLE with serv_hist pointing to bit 3.");
    @(posedge clk);
    #1;

    // --- Scenario 2: Single Request (Master 0) ---
    // serv_hist[3] is active. If request0 happens, it should get granted.
    $display("[TB] Requesting Master 0...");
    request0 = 1;

    @(posedge clk);  // Moves to GRANT state
    #1;
    request0 = 0;  // De-assert request once granted (simulating a standard protocol)

    #40;  // Let it hold the grant for a couple of cycles
    $display("[TB] Ending Master 0 transaction. History should update to bit 0.");
    end_transaction0 = 1;

    @(posedge clk);  // Moves back to IDLE
    #1;
    end_transaction0 = 0;
    @(posedge clk);
    #1;

    // --- Scenario 3: Multiple Simultaneous Requests ---
    // History now points to serv_hist[0] because Master 0 was served last.
    // According to your IDLE case for serv_hist[0], priority order is: M1 -> M2 -> M3 -> M0
    $display("[TB] Simulating simultaneous requests from Master 0 and Master 2...");
    request0 = 1;
    request2 = 1;

    @(posedge clk);  // FSM evaluates. Master 2 should win over Master 0 based on priority order.
    #1;
    request0 = 0;
    request2 = 0;

    #40;
    $display("[TB] Ending Master 2 transaction. History should update to bit 2.");
    end_transaction2 = 1;

    @(posedge clk);  // Moves back to IDLE
    #1;
    end_transaction2 = 0;
    @(posedge clk);
    #1;

    // --- Scenario 4: No Requests ---
    $display("[TB] No requests active. Checking if FSM remains stable in IDLE.");
    #40;

    // End simulation
    $display("[TB] Simulation finished successfully.");
    $finish;
  end

  // Monitor changes in terminal window
  initial begin
    $monitor("Time=%0t | rstb=%b | Req={%b,%b,%b,%b} | Grant={%b,%b,%b,%b} | End={%b,%b,%b,%b}",
             $time, rstb, request0, request1, request2, request3, grant0, grant1, grant2, grant3,
             end_transaction0, end_transaction1, end_transaction2, end_transaction3);
  end

endmodule
