
// esta madre es parte de algo mas grande 

module gray_to_binary #(
    parameter POINTER = 6
) (
    gray_value,
    binary_value
);

  input [POINTER:0] gray_value;

  output [POINTER:0] binary_value;
  wire [POINTER:0] binary_value;

  // este es el ultimo
  assign binary_value[POINTER] = gray_value[POINTER];

  generate
    for (genvar i = 0; i < POINTER; i = i + 1) begin
      assign binary_value[i] = binary_value[i+1] ^ gray_value[i];
    end
  endgenerate

endmodule
