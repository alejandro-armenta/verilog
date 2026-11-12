
module counter ();

  reg a, b, c;

  always @(*) begin

    if (a > b && a < c) begin
      counter = counter + 1;
    end

  end

endmodule

