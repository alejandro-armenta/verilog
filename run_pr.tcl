
set pdk_root $env(PDK_ROOT)

puts $pdk_root

# Read technology LEF
read_lef /usr/local/share/pdk/share/pdk/sky130A/libs.ref/sky130_fd_sc_hd/techlef/sky130_fd_sc_hd__nom.tlef

read_lef /usr/local/share/pdk/share/pdk/sky130A/libs.ref/sky130_fd_sc_hd/lef/sky130_fd_sc_hd.lef

read_liberty /usr/local/share/pdk/share/pdk/sky130A/libs.ref/sky130_fd_sc_hd/lib/sky130_fd_sc_hd__tt_025C_1v80.lib

read_verilog ./counter_synthesized.v

link_design counter

read_sdc counter.sdc

# this creates the area to create the chip

initialize_floorplan -die_area {0 0 100 100} -core_area {10 10 90 90} -site unithd

# all cells must be connected to the power and to the ground

add_global_connection -net VDD -pin_pattern {^VDD$} -power 
add_global_connection -net VSS -pin_pattern {^VSS$} -ground

# these are the tracks for connecting data

make_tracks

set_wire_rc -layer "met3"

# data is connected to met3 and met2

place_pins -hor_layer met3 -ver_layer met2 -annealing

set_voltage_domain -name CORE -power VDD -ground VSS

define_pdn_grid -name std_cell_grid -voltage_domain CORE

# power is connected to met1 and met4

add_pdn_stripe -grid std_cell_grid -layer met1 -width 0.48 -followpins 

add_pdn_stripe -grid std_cell_grid -layer met4 -width 1.6 -pitch 27.0 -offset 13.5

add_pdn_connect -grid std_cell_grid -layers {met1 met4}

pdngen

global_placement -density 0.40

estimate_parasitics -placement

buffer_ports

detailed_placement

clock_tree_synthesis -root_buf sky130_fd_sc_hd__clkbuf_4 -buf_list {sky130_fd_sc_hd__clkbuf_1 sky130_fd_sc_hd__clkbuf_2} -clk_nets {clk}

set_propagated_clock [all_clocks]

detailed_placement

global_route

detailed_route

estimate_parasitics -global_routing

report_checks -path_delay min_max -fields {slew cap input}

write_def ./outputs/counter_final.def

write_verilog ./outputs/counter_post_layout.v

write_sdf ./outputs/counter_layout.sdf
