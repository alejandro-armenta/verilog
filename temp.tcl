# ==========================================
# 1. INITIALIZE & READ DESIGN DATA
# ==========================================
# Ensure PDK_ROOT environmental variable is properly loaded
if {![info exists env(PDK_ROOT)]} {
    puts "Error: Environmental variable PDK_ROOT is not set."
    exit 1
}
set pdk_root $env(PDK_ROOT)

# Read the technology and cell physical abstracts from open_pdks pathing
read_lef $pdk_root/sky130A/libs.ref/sky130_fd_sc_hd/techlef/sky130_fd_sc_hd.tlef
read_lef $pdk_root/sky130A/libs.ref/sky130_fd_sc_hd/lef/sky130_fd_sc_hd.lef

# Read your timing database
read_liberty $pdk_root/sky130A/libs.ref/sky130_fd_sc_hd/lib/sky130_fd_sc_hd__tt_025C_1v80.lib

# Read the synthesized gate-level netlist file you generated with Yosys
# (Update this path to your actual verilog netlist location)
read_verilog /path/to/your_synthesized_netlist.v

# Link the netlist together under your top module name
link_design counter

# Define your design constraint clock period (10.0ns = 100MHz)
create_clock -name clk -period 10.0 [get_ports clk]

# ==========================================
# 2. FLOORPLANNING
# ==========================================
# FIX: OpenROAD initialize_floorplan uses -site, but -die_area and -core_area 
# expect a 4-element list bounding box structure.
initialize_floorplan -die_area {0 0 100 100} -core_area {10 10 90 90} -site unithd

# Inject the macro/IO power supply rails (VDD and VSS)
add_global_connection -net VDD -pin_pattern {^VDD$} -power
add_global_connection -net VSS -pin_pattern {^VSS$} -ground

# Automatically arrange the I/O pins (clk, rst, en, count) along the die edges
# FIX: place_pins requires a defined routing layer string configuration 
place_pins -hor_layer met3 -ver_layer met2 -random

# FIX: make_tracks requires specifying the routing layers or using -pdk to pull 
# track definitions automatically from the loaded LEF.
make_tracks

# ==========================================
# 3. PLACEMENT & OPTIMIZATION
# ==========================================
# Perform global placement with a targeted cell density of 40%
global_placement -density 0.40

# Optimize timing slack and logic mapping variations
estimate_parasitics -placement
buffer_ports

# Lock cells perfectly into their valid manufacturing slot grid rows
detailed_placement

# ==========================================
# 4. CLOCK TREE SYNTHESIS (CTS)
# ==========================================
# Synthesize the clock network using Sky130 clock buffers
# FIX: clock_tree_synthesis uses -buf_list. Ensure cells exist in sky130_fd_sc_hd
clock_tree_synthesis -buf_list {sky130_fd_sc_hd__clkbuf_1 sky130_fd_sc_hd__clkbuf_2} -root_buf sky130_fd_sc_hd__clkbuf_4
set_propagated_clock [all_clocks]

# Refine row grid packing following buffer additions
detailed_placement

# ==========================================
# 5. GLOBAL & DETAILED ROUTING
# ==========================================
# Plan global signal wire paths across available channels
global_route

# Direct TritonRoute to execute the fine detailed metal layouts
# FIX: TritonRoute detailed_route engine flags must specify output paths properly.
detailed_route -output_drc drc_reports.rpt

# ==========================================
# 6. EXPORT BLUEPRINTS
# ==========================================
# Save your completed layout back out to a standard DEF exchange database file
write_def ./counter_layout.def

puts "OpenROAD Layout Flow Successfully Completed!"
exit
