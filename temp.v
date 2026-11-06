// Modified initial block for Icarus Verilog + GTKWave
initial begin
  // These two lines create the waveform dump file for GTKWave
  $dumpfile("and_gate_waves.vcd");
  $dumpvars(0, and_gate_tb);

  // Display header in the simulator console
  $display("Time\t A \t B \t Y \t Expected");
  $display("-----------------------------------");

  // Test Cases (Same as before)
  a = 0;
  b = 0;
  #10;
  if (y !== 0) $display("ERROR: 0 & 0 expected 0, got %b", y);
  else $display("%0nt\t %b \t %b \t %b \t 0 (PASS)", $time, a, b, y);

  a = 0;
  b = 1;
  #10;
  if (y !== 0) $display("ERROR: 0 & 1 expected 0, got %b", y);
  else $display("%0nt\t %b \t %b \t %b \t 0 (PASS)", $time, a, b, y);

  a = 1;
  b = 0;
  #10;
  if (y !== 0) $display("ERROR: 1 & 0 expected 0, got %b", y);
  else $display("%0nt\t %b \t %b \t %b \t 0 (PASS)", $time, a, b, y);

  a = 1;
  b = 1;
  #10;
  if (y !== 1) $display("ERROR: 1 & 1 expected 1, got %b", y);
  else $display("%0nt\t %b \t %b \t %b \t 1 (PASS)", $time, a, b, y);

  $display("-----------------------------------");
  $display("Simulation complete.");
  $finish;
end
