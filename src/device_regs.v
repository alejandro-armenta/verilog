
module device_regs (
    address,
    write_en,
    data_in,
    read_en,
    read_data,
    clk,
    resetb
);

  // ////////////////////////////////////////////////////

  input [3:0] address;
  input write_en;
  input [7:0] data_in;
  input read_en;
  output [7:0] read_data;
  input clk;
  input resetb;

  // ////////////////////////////////////////////////////

  wire reg0_match, reg1_match, reg2_match, reg3_match;

  reg [7:0] reg0, reg1, reg2, reg3;

  wire [7:0] reg0_next;
  wire [7:0] reg1_next;
  wire [7:0] reg2_next;
  wire [7:0] reg3_next;

  // ////////////////////////////////////////////////////

  reg  [7:0] read_data;
  reg  [7:0] read_data_next;

  // ////////////////////////////////////////////////////

  assign reg0_match = (address == 4'b0000);
  assign reg1_match = (address == 4'b0001);
  assign reg2_match = (address == 4'b0010);
  assign reg3_match = (address == 4'b0011);

  // esto y esto es lo mismo

  assign reg0_next  = (reg0_match && write_en) ? data_in : reg0;
  assign reg1_next  = (reg1_match && write_en) ? data_in : reg1;
  assign reg2_next  = (reg2_match && write_en) ? data_in : reg2;
  assign reg3_next  = (reg3_match && write_en) ? data_in : reg3;


  always @(*) begin

    read_data_next = read_data;

    if (read_en) begin

      case (1'b1)

        reg0_match: read_data_next = reg0;
        reg1_match: read_data_next = reg1;
        reg2_match: read_data_next = reg2;
        reg3_match: read_data_next = reg3;

      endcase

    end

  end

  // ////////////////////////////////////////////////////

  // es un write sincrono

  always @(posedge clk or negedge resetb) begin

    if (!resetb) begin

      reg0 <= 0;
      reg1 <= 0;
      reg2 <= 0;
      reg3 <= 0;
      read_data <= 0;

    end else begin

      reg0 <= reg0_next;
      reg1 <= reg1_next;
      reg2 <= reg2_next;
      reg3 <= reg3_next;
      read_data <= read_data_next;

    end

  end


endmodule
