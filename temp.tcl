# ==========================================
# 1. INITIALIZE & READ DESIGN DATA
# ==========================================
if {![info exists env(PDK_ROOT)]} {
    puts "Error: Environmental variable PDK_ROOT is not set."
    exit 1
}
set pdk_root $env(PDK_ROOT)

# Read the technology and cell physical abstracts
read_lef $pdk_root/sky130A/libs.ref/sky130_fd_sc_hd/techlef/sky130_fd_sc_hd.tlef
read_lef $pdk_root/sky130A/libs.ref/sky130_fd_sc_hd/lef/sky130_fd_sc_hd.lef

# Read timing database
read_liberty $pdk_root/sky130A/libs.ref/sky130_fd_sc_hd/lib/sky130_fd_sc_hd__tt_025C_1v80.lib

# Read your synthesized gate-level netlist file (Update this path to your actual file)
read_verilog /path/to/your_synthesized_netlist.v

# Link the netlist together under your top module name
link_design counter

# Load your SDC file directly to apply constraints cleanly
read_sdc counter.sdc

# ==========================================
# 2. FLOORPLANNING
# ==========================================
# FIX: OpenROAD initialize_floorplan uses a 4-element list for bounds, -site must match LEF
initialize_floorplan -die_area {0 0 100 100} -core_area {10 10 90 90} -site unithd

# Inject the macro/IO power supply rails (VDD and VSS)
add_global_connection -net VDD -pin_pattern {^VDD$} -power
add_global_connection -net VSS -pin_pattern {^VSS$} -ground

# FIX: tracks must be initialized before pin placement so pins can snap to routing grids
make_tracks met1 -x_offset 0.17 -x_pitch 0.34 -y_offset 0.17 -y_pitch 0.34
make_tracks met2 -x_offset 0.23 -x_pitch 0.46 -y_offset 0.23 -y_pitch 0.46
make_tracks met3 -x_offset 0.34 -x_pitch 0.68 -y_offset 0.34 -y_pitch 0.68

# FIX: place_pins arguments corrected for standard OpenROAD syntax
place_pins -hor_layer met3 -ver_layer met2 -random

# MISSING STEP: Generate the power grid (PDN) structure before placing logic cells
pdngen

# ==========================================
# 3. PLACEMENT & OPTIMIZATION
# ==========================================
# Perform global placement
global_placement -density 0.40

# Optimize timing slack and logic mapping variations
estimate_parasitics -placement
buffer_ports

# Lock cells perfectly into their valid manufacturing slot grid rows
detailed_placement

# ==========================================
# 4. CLOCK TREE SYNTHESIS (CTS)
# ==========================================
# FIX: clock_tree_synthesis requires explicit -buf_list matching the sky130 target
clock_tree_synthesis -buf_list {sky130_fd_sc_hd__clkbuf_1 sky130_fd_sc_hd__clkbuf_2 sky130_fd_sc_hd__clkbuf_4}
set_propagated_clock [all_clocks]

# Refine row grid packing following buffer additions
detailed_placement

# ==========================================
# 5. GLOBAL & DETAILED ROUTING
# ==========================================
# Plan global signal wire paths across available channels
global_route

# FIX: detailed_route in OpenROAD does not accept a raw -output_drc flag.
# Output paths and parameters are handled via internal commands or OpenLane variables.
detailed_route

# ==========================================
# 6. EXPORT BLUEPRINTS & SIMULATION DATA
# ==========================================
# Save your completed layout back out to a standard DEF file
write_def ./counter_layout.def

# CRITICAL FOR SIMULATION: Export the post-layout gate netlist
write_verilog ./counter_post_layout.v

# CRITICAL FOR SIMULATION: Extract parasitics and write out the timing delays (SDF)
estimate_parasitics -global_routing
write_sdf ./counter_layout.sdf

puts "OpenROAD Layout Flow Successfully Completed!"
exit
