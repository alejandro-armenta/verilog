# ==========================================
# 3. PLACEMENT & OPTIMIZATION
# ==========================================
# Perform global placement with a targeted cell density of 40%
# Offloaded to your RTX 3060 via the DREAMPlace/DPL engine backend
global_placement -density 0.40

# Optimize timing slack, drive strengths, and long-wire structures
estimate_parasitics -placement
buffer_ports

# Lock cells perfectly into their valid unithd row slot grids (Legalization)
detailed_placement

# Pause the script to visually inspect the placed gates
gui::show
