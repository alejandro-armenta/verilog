`timescale 1ns / 1ps

module tb_device_regs;

  // Testbench signals
  reg  [3:0] address;
  reg        write_en;
  reg  [7:0] data_in;
  reg        read_en;
  wire [7:0] read_data;
  reg        clk;
  reg        resetb;

  // Instantiate the Device Under Test (DUT)
  device_regs uut (
      .address  (address),
      .write_en (write_en),
      .data_in  (data_in),
      .read_en  (read_en),
      .read_data(read_data),
      .clk      (clk),
      .resetb   (resetb)
  );

  // 100MHz Clock Generation (10ns period)
  always #5 clk = ~clk;

  // Task to write to a register
  task write_reg(input [3:0] addr, input [7:0] data);
    begin
      @(negedge clk);
      address  = addr;
      data_in  = data;
      write_en = 1'b1;
      read_en  = 1'b0;
      @(posedge clk);  // Data latches on posedge
      #1;
      write_en = 1'b0;
    end
  endtask

  // Task to read and verify a register
  task read_and_check(input [3:0] addr, input [7:0] expected);
    begin
      @(negedge clk);
      address  = addr;
      write_en = 1'b0;
      read_en  = 1'b1;
      @(posedge clk);  // read_data updates on posedge
      #1;
      if (read_data === expected) begin
        $display("[PASS] Addr %0d: Read 0x%0h (Expected 0x%0h)", addr, read_data, expected);
      end else begin
        $display("[FAIL] Addr %0d: Read 0x%0h (Expected 0x%0h)", addr, read_data, expected);
      end
      read_en = 1'b0;
    end
  endtask

  // Main test sequence
  initial begin
    // Dump waveforms for GTKWave / ModelSim / Vivado
    $dumpfile("tb_device_regs.vcd");
    $dumpvars(0, tb_device_regs);

    // Initialize signals
    clk      = 0;
    resetb   = 1;
    address  = 4'b0000;
    write_en = 0;
    read_en  = 0;
    data_in  = 8'h00;

    $display("--- Starting Simulation ---");

    // 1. Apply Active-Low Reset
    #12 resetb = 0;
    #20 resetb = 1;
    #10;

    // 2. Verify registers cleared after reset
    read_and_check(4'd0, 8'h00);
    read_and_check(4'd1, 8'h00);
    read_and_check(4'd2, 8'h00);
    read_and_check(4'd3, 8'h00);

    // 3. Write unique values to all 4 registers
    write_reg(4'd0, 8'hAA);
    write_reg(4'd1, 8'h55);
    write_reg(4'd2, 8'hF0);
    write_reg(4'd3, 8'h0F);

    // 4. Read back and verify values
    read_and_check(4'd0, 8'hAA);
    read_and_check(4'd1, 8'h55);
    read_and_check(4'd2, 8'hF0);
    read_and_check(4'd3, 8'h0F);

    // 5. Test out-of-bounds address (read_data should hold previous value 0x0F)
    write_reg(4'd5, 8'h99);
    read_and_check(4'd5, 8'h0F);

    // 6. Test mid-operation reset
    #10 resetb = 0;
    #15 resetb = 1;
    read_and_check(4'd0, 8'h00);

    $display("--- Simulation Complete ---");
    $finish;
  end

endmodule
