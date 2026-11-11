
module d_flip_flop (
    clk,
    rstb,
    a
);

  input clk;
  input rstb;
  input a;

  reg b, c;

  reg  [1:0] counter;
  wire [1:0] counter_next;

  // es igual que el otro ejemplo este se injecta instantaneamente y llega a la linea instantanemente solo lo frena el posedge clk

  // esto es combinacional 

  assign counter_next = (counter == 2'b11) ? 2'b00 : (counter + 1'b1);

  // esto es secuencial

  always @(posedge clk or negedge rstb) begin

    if (!rstb) begin

      b <= 0;
      c <= 0;
      counter <= 0;

    end else begin

      // este se pasa en dos ciclos

      b <= a;
      c <= b;

      counter <= counter_next;

    end

  end

endmodule



