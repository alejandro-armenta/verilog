module device_regs (
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

  wire reg0_match, reg1_match, reg2_match, reg3_match;

  reg  [7:0] reg0;
  wire [7:0] reg0_next;

  reg  [7:0] reg1;
  wire [7:0] reg1_next;

  reg  [7:0] reg2;
  wire [7:0] reg2_next;

  reg  [7:0] reg3;
  wire [7:0] reg3_next;

  assign reg0_match = (address == 4'b0000);
  assign reg1_match = (address == 4'b0001);
  assign reg2_match = (address == 4'b0010);
  assign reg3_match = (address == 4'b0011);

  assign reg0_next  = (reg0_match && write_en) ? data_in : reg0;
  assign reg1_next  = (reg1_match && write_en) ? data_in : reg1;
  assign reg2_next  = (reg2_match && write_en) ? data_in : reg2;
  assign reg3_next  = (reg3_match && write_en) ? data_in : reg3;


endmodule
