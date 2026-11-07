# Executables
YOSYS = yosys
VERILATOR = verilator
GTKWAVE = gtkwave

# Files
TOP_MODULE = counter
RTL_SRC = counter.v
SYNTH_SRC = counter_synth.v
TB_SRC = tb_counter.cpp

# Target cell definitions from Yosys installation path
# On Ubuntu/Debian, this is typically /usr/share/yosys/simlib.v
SIM_LIB = /usr/share/yosys/simlib.v

.PHONY: all synth sim wave clean

all: sim

# Step 1: Synthesize behavioral RTL into gate-level netlist using Yosys
synth: $(RTL_SRC)
	$(YOSYS) -p "read_verilog $(RTL_SRC); hierarchy -top $(TOP_MODULE); synth; write_verilog -noattr $(SYNTH_SRC)"

# Step 2: Compile gate-level netlist and C++ testbench using Verilator
# Then execute the generated binary to create the .vcd file
sim: synth $(TB_SRC)
	$(VERILATOR) --cc --exe --build -j 4 \
		--trace \
		-top-module $(TOP_MODULE) \
		$(SIM_LIB) $(SYNTH_SRC) $(TB_SRC)
	@echo "Executing Simulation..."
	./obj_dir/V$(TOP_MODULE)

# Step 3: Open the generated waveform file directly in GTKWave
wave: sim
	$(GTKWAVE) waveform.vcd &

clean:
	rm -rf obj_dir
	rm -f $(SYNTH_SRC)
	rm -f waveform.vcd
