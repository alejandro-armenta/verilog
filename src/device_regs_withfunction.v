
module device_regs_withfunction (
    address,
    write_en,
    data_in,
    read_en,
    read_data,
    clk,
    resetb
);

  input [3:0] address;
  input write_en;
  input [7:0] data_in;
  input read_en;
  output [7:0] read_data;
  input clk;
  input resetb;

  reg [7:0] reg0, reg1, reg2, reg3;

  reg [7:0] read_data;
  reg [7:0] read_data_next;


  // combinacional

  function [7:0] dev_reg_next;

    input write_en;

    input [3:0] address;
    input [3:0] reg_offset;

    input [7:0] data_in;
    input [7:0] dev_reg;

    begin

      dev_reg_next = ((address == reg_offset) && write_en) ? data_in : dev_reg;

    end

  endfunction

  wire [7:0] reg0_next = dev_reg_next(write_en, address, 4'b0000, data_in, reg0);

  wire [7:0] reg1_next = dev_reg_next(write_en, address, 4'b0001, data_in, reg1);

  wire [7:0] reg2_next = dev_reg_next(write_en, address, 4'b0010, data_in, reg2);

  wire [7:0] reg3_next = dev_reg_next(write_en, address, 4'b0011, data_in, reg3);

  always @(posedge clk or negedge resetb) begin

    if (!resetb) begin

      reg0 <= 'd0;
      reg1 <= 'd0;
      reg2 <= 'd0;
      reg3 <= 'd0;

      read_data <= 'd0;

    end else begin

      reg0 <= reg0_next;
      reg1 <= reg1_next;
      reg2 <= reg2_next;
      reg3 <= reg3_next;

      read_data <= read_data_next;

    end

  end

  always @(*) begin

    read_data_next = read_data;

    if (read_en) begin

      case (1'b1)

        (address == 4'b0000): read_data_next = reg0;
        (address == 4'b0001): read_data_next = reg1;
        (address == 4'b0010): read_data_next = reg2;
        (address == 4'b0011): read_data_next = reg3;

      endcase

    end

  end


endmodule
