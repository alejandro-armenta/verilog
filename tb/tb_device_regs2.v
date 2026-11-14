
`timescale 1ns / 10ps

module testbench_top ();

  reg [3:0] address_tb;
  reg write_en_tb;
  reg [7:0] wrdata_tb;
  reg read_en_tb;
  reg clk_tb;
  reg resetb;

  wire [7:0] rd_data_tb;

  device_regs_withfunction device_regs_withfunciton_0 (
      .clk(clk_tb),
      .resetb(resetb),
      .address(address_tb),
      .write_en(write_en_tb),
      .read_en(read_en_tb),
      .data_in(wrdata_tb),
      .read_data(rd_data_tb)
  );


  // 100 mhz clk
  parameter CLK_TB_HALF_PERIOD = 5;
  parameter RESET_DASSERT_DLY = 100;

  parameter REG0_OFFSET = 4'b0000,REG1_OFFSET = 4'b0001,REG2_OFFSET = 4'b0010,REG3_OFFSET = 4'b0011;


  initial begin

    clk_tb = 1'b0;

    forever begin

      #CLK_TB_HALF_PERIOD;

      clk_tb = ~clk_tb;

    end

  end

  initial begin

    resetb = 1'b0;

    #RESET_DASSERT_DLY;

    resetb = 1'b1;

  end

  initial begin

    address_tb  = 'h0;
    write_en_tb = 'h0;
    wrdata_tb   = 1'b0;
    read_en_tb  = 1'b0;

  end

  task reg_write;

    input [3:0] address_in;
    input [7:0] data_in;

    begin

      @(posedge clk_tb);
      #1;

      address_tb = address_in;

      @(posedge clk_tb);
      #1;

      write_en_tb = 1'b1;
      wrdata_tb   = data_in;

      @(posedge clk_tb);
      #1;

      write_en_tb = 1'b0;
      address_tb  = 4'hF;
      wrdata_tb   = 8'h00;


    end


  endtask

  task reg_read;

    input [3:0] address_in;
    input [7:0] expected_data;

    begin

      @(posedge clk_tb);
      #1;

      address_tb = address_in;

      @(posedge clk_tb);
      #1;

      read_en_tb = 1'b1;

      @(posedge clk_tb);
      #1;

      read_en_tb = 1'b0;
      address_tb = 4'hF;

      @(posedge clk_tb);

      // check for x Z 0 1

      if (rd_data_tb === expected_data) begin
        $display("data matches: expected data: %h actual data: %h", expected_data, rd_data_tb);
      end else begin
        $display("ERROR: data mismatch: expected data: %h actual data: %h", expected_data,
                 rd_data_tb);
      end

    end
  endtask

  initial begin

    $dumpfile("simulation.vcd");
    $dumpvars(0, testbench_top);

    #1000;

    reg_write(REG0_OFFSET, 8'hA5);
    reg_read(REG0_OFFSET, 8'hA5);

    reg_write(REG1_OFFSET, 8'hA6);
    reg_read(REG1_OFFSET, 8'hA6);

    reg_write(REG2_OFFSET, 8'hA7);
    reg_read(REG2_OFFSET, 8'hA7);

    reg_write(REG3_OFFSET, 8'hA8);
    reg_read(REG3_OFFSET, 8'hA8);



    $finish;
  end

endmodule
