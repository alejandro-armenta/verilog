
`timescale 1ns / 1ps

module tb_device_regs;

  reg [3:0] address;
  reg write_en;
  reg [7:0] data_in;
  reg read_en;
  reg clk;
  reg resetb;

  wire [7:0] read_data;

  device_regs device_regs0 (
      .address(address),
      .write_en(write_en),
      .data_in(data_in),
      .read_en(read_en),
      .clk(clk),
      .resetb(resetb),

      .read_data(read_data)
  );


  initial begin

    clk = 0;

    forever begin
      #5;
      clk = ~clk;
    end

  end

  task write_reg(input [3:0] addr, input [7:0] data);
    begin

      @(negedge clk);

      address  = addr;
      data_in  = data;
      write_en = 1'b1;
      read_en  = 1'b0;

      @(posedge clk);
      #1;
      write_en = 1'b0;

    end
  endtask

  task read_and_check(input [3:0] addr, input [7:0] expected);

    begin

      @(negedge clk);

      // estas leyendo de este address

      address  = addr;
      write_en = 1'b0;
      read_en  = 1'b1;

      @(posedge clk);
      #1;

      if (read_data == expected) begin
        $display("PASS Addr: %0d Read: %0h Expected: %0h", addr, read_data, expected);
      end else begin
        $display("FAIL Addr: %0d Read: %0h Expected: %0h", addr, read_data, expected);
      end

      read_en = 1'b0;

    end

  endtask


  initial begin

    $dumpfile("simulation.vcd");
    $dumpvars(0, tb_device_regs);

    resetb   = 1;
    address  = 4'b0000;
    write_en = 0;
    read_en  = 0;
    data_in  = 8'h00;

    #12 resetb = 0;
    #20 resetb = 1;

    #10;

    read_and_check(4'd0, 8'h00);

    read_and_check(4'd1, 8'h00);

    read_and_check(4'd2, 8'h00);

    read_and_check(4'd3, 8'h00);

    write_reg(4'd0, 8'hAA);

    write_reg(4'd1, 8'hBB);

    write_reg(4'd2, 8'hCC);

    write_reg(4'd3, 8'hDD);

    read_and_check(4'd0, 8'hAA);

    read_and_check(4'd1, 8'hBB);

    read_and_check(4'd2, 8'hCC);

    read_and_check(4'd3, 8'hDD);

    write_reg(4'd5, 8'h99);

    read_and_check(4'd5, 8'hDD);

    #10;

    resetb = 0;

    #15;

    resetb = 1;

    read_and_check(4'd0, 8'h00);

    $finish;

  end

endmodule
