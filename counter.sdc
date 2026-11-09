# ====================================================================
# 1. Define the Core Clock
# ====================================================================
# Creates a 50 MHz clock with a 20.0ns period targeting your 'clk' input port.
create_clock -name sys_clk -period 20.0 [get_ports clk]

# ====================================================================
# 2. Clock Uncertainties & Margins
# ====================================================================
# Models 5% clock jitter and layout skew (0.05 * 20.0ns = 1.0ns).
set_clock_uncertainty 0.2 [get_clocks sys_clk]

# Models a realistic rise/fall edge transition time for the clock path.
set_clock_transition 0.15 [get_clocks sys_clk]

# ====================================================================
# 3. Input Port Constraints (rst, en)
# ====================================================================
# Tells OpenROAD that 'rst' and 'en' transitions arrive up to 4.0ns 
# after the clock edge (leaving 16.0ns for internal chip routing).
set_input_delay -clock sys_clk 4.0 [get_ports rst]
set_input_delay -clock sys_clk 4.0 [get_ports en]

# ====================================================================
# 4. Output Port Constraints (count)
# ====================================================================
# Reserves 4.0ns of setup time margin at the external pins for whatever 
# device is reading your 8-bit 'count' bus.
set_output_delay -clock sys_clk 4.0 [get_ports count[*]]

# ====================================================================
# 5. Environment & Electrical Loads
# ====================================================================
# Assumes standard input pins are driven by a weak/medium base buffer 
# cell (adjust cell name if using a PDK other than sky130_fd_sc_hd).
set_driving_cell -lib_cell sky130_fd_sc_hd__buf_1 -pin X [get_ports rst]
set_driving_cell -lib_cell sky130_fd_sc_hd__buf_1 -pin X [get_ports en]

# Simulates a standard 35 femtofarad capacitive load on each bit of the count bus.
set_load 0.035 [get_ports count[*]]
