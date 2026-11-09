# ====================================================================
# 5. GLOBAL & DETAILED ROUTING
# ====================================================================
puts "INFO: Starting Global Routing..."
# Plans the coarse, global routing topologies across available channels
global_route

puts "INFO: Starting Detailed Routing (TritonRoute)..."
# Traces exact physical metal tracks and drops vias matching Sky130 manufacturing rules.
# This stage uses multi-threading and can leverage your RTX 3060 compute capabilities.
detailed_route

# ====================================================================
# 6. PARASITIC EXTRACTION & SIGN-OFF REPORTING
# ====================================================================
puts "INFO: Extracting RC Parasitics..."
# Calculates physical wire resistances and capacitive loads based on final layouts
estimate_parasitics -global_routing

puts "INFO: Running Final Static Timing Analysis (STA) Sign-Off..."
# Prints your final true post-layout timing setup/hold slack reports
report_checks -path_delay min_max -fields {slew cap input line cell arrival costs}

# ====================================================================
# 7. EXPORT BLUEPRINTS FOR MANUFACTURING & LAYOUT SIMULATION
# ====================================================================
puts "INFO: Exporting final layout databases..."

# 1. Save physical layout file (GDS exchange database)
write_def ./outputs/counter_final.def

# 2. CRITICAL FOR SIMULATION: Export the post-layout gate-level netlist
# This netlist contains your counter logic + newly injected clock tree/IO buffers
write_verilog ./outputs/counter_post_layout.v

# 3. CRITICAL FOR SIMULATION: Export the timing delays file (Standard Delay Format)
# This maps the physical wire delays into numbers your simulator can read
write_sdf ./outputs/counter_layout.sdf

puts "===================================================================="
puts " OpenROAD Layout Flow Completed Successfully!"
puts " Final assets saved to ./outputs/"
puts "===================================================================="

# Re-open the GUI so you can see the finished, beautifully routed chip!
gui::show
