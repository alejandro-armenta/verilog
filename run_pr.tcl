
set pdk_root $env(PDK_ROOT)

puts $pdk_root

# Read technology LEF
read_lef /usr/local/share/pdk/share/pdk/sky130A/libs.ref/sky130_fd_sc_hd/techlef/sky130_fd_sc_hd__nom.tlef

read_lef /usr/local/share/pdk/share/pdk/sky130A/libs.ref/sky130_fd_sc_hd/lef/sky130_fd_sc_hd.lef

read_liberty /usr/local/share/pdk/share/pdk/sky130A/libs.ref/sky130_fd_sc_hd/lib/sky130_fd_sc_hd__tt_025C_1v80.lib

read_verilog ./counter_synthesized.v

link_design counter
 

# read_lef $pdk_root/sky130A/libs.ref

# read_lef ./sky130_fd_sc_hd.tlef

# read_lef ./sky130_fd_sc_hd.lef

# read_liberty ./sky130_fd_sc_hd__tt_025C_1v80.lib

# read_verilog ./counter_synthesized.v

# link_design counter
