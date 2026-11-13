
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



endmodule
