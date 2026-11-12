
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


  initial begin



  end

endmodule
