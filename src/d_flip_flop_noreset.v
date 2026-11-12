
module d_flip_flop_noreset (
    clk,
    reset_counter
);

  // los dos son resets asincronos pero uno es negativo y este es positivo

  input clk;
  input reset_counter;

  reg [1:0] counter;

  reg [1:0] counter_next;

  // lo cambiaste para que fuera en forma de always

  always @(*) begin

    counter_next = counter;

    if (reset_counter) begin

      counter_next = 2'b00;

    end else if (counter == 2'b11) begin

      counter_next = 2'b00;

    end else begin

      counter_next = counter + 1'b1;

    end

  end

  always @(posedge clk) begin

    counter <= counter_next;

  end

endmodule

