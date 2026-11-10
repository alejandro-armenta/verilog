# ====================================================================
# 1. Define the Core Clock
# ====================================================================
# Tightened: Creates a ~166.6 MHz clock with a 6.0ns period targeting your 'clk' input port.
create_clock -name sys_clk -period 6.0 [get_ports clk]

# ====================================================================
# 2. Clock Uncertainties & Margins
# ====================================================================
# Models clock jitter and layout skew (Matches the 0.20ns uncertainty seen in your OpenROAD log).
set_clock_uncertainty 0.2 [get_clocks sys_clk]

# Models a realistic rise/fall edge transition time for the clock path.
set_clock_transition 0.15 [get_clocks sys_clk]

# ====================================================================
# 3. Input Port Constraints (rst, en)
# ====================================================================
# Tightened: Reduced from 4.0 to 1.0 to reflect a tighter cycle. 
# Tells OpenROAD that external inputs arrive 1.0ns after the clock edge, 
# leaving 5.0ns for internal chip routing.
set_input_delay -clock sys_clk 1.0 [get_ports rst]
set_input_delay -clock sys_clk 1.0 [get_ports en]

# ====================================================================
# 4. Output Port Constraints (count)
# ====================================================================
# Tightened: Reduced from 4.0 to 1.0. 
# Reserves 1.0ns of setup time margin at the external pins for whatever 
# device is reading your 8-bit 'count' bus.
set_output_delay -clock sys_clk 1.0 [get_ports count[*]]

# ====================================================================
# 5. Environment & Electrical Loads
# ====================================================================
# Assumes standard input pins are driven by a weak/medium base buffer 
# cell (sky130_fd_sc_hd).
set_driving_cell -lib_cell sky130_fd_sc_hd__buf_1 -pin X [get_ports rst]
set_driving_cell -lib_cell sky130_fd_sc_hd__buf_1 -pin X [get_ports en]

# Simulates a standard 35 femtofarad capacitive load on each bit of the count bus.
set_load 0.035 [get_ports count[*]]
