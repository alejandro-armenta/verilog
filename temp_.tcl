# ====================================================================
# 4. CLOCK TREE SYNTHESIS (CTS) & TIMING ANALYSES
# ====================================================================
# Select standard clock buffers from your sky130_fd_sc_hd PDK cell library
set_wire_rc -signal -layer met2
set_wire_rc -clock  -layer met3

# Synthesize the clock branches cleanly
clock_tree_synthesis -root_buf sky130_fd_sc_hd__clkbuf_4 \
                     -buf_list {sky130_fd_sc_hd__clkbuf_1 sky130_fd_sc_hd__clkbuf_2} \
                     -clk_nets {clk}

# Transition the analyzer to evaluate actual physical buffer tree delays
set_propagated_clock [all_clocks]

# Run a quick legalized placement adjustment to fix slots after adding clock buffers
detailed_placement

# Pause the tool to let us check the updated timing or cell properties in the GUI
gui::show
