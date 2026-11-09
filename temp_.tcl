# ==========================================
# 2. FLOORPLANNING & POWER GRID CONFIGURATION
# ==========================================
initialize_floorplan -die_area {0 0 100 100} -core_area {10 10 90 90} -site unithd

# Establish global virtual nets for VDD and VSS
add_global_connection -net VDD -pin_pattern {^VDD$} -power
add_global_connection -net VSS -pin_pattern {^VSS$} -ground

# Setup routing grids and I/O boundaries
make_tracks
place_pins -hor_layers met3 -ver_layers met2 -annealing

# ----------------------------------------------------------
# FIXED NATIVE OPENROAD PDN COMMANDS
# ----------------------------------------------------------

# 1. Initialize the global power domain
set_voltage_domain -name CORE -power VDD -ground VSS

# 2. Define the main power grid template
define_pdn_grid -name std_cell_grid -voltage_domains CORE

# 3. FIX: Add Fine Horizontal Rails on met1 using the -followpins flag
add_pdn_stripe -grid std_cell_grid -layer met1 -width 0.48 -followpins

# 4. Add Thick Vertical Distribution Straps (Metal 4) across the chip
add_pdn_stripe -grid std_cell_grid -layer met4 -width 1.6 -pitch 27.0 -offset 13.5

# 5. Connect the Vertical Metal 4 Straps down to the Horizontal Metal 1 Rails
add_pdn_connect -grid std_cell_grid -layers {met1 met4}

# 6. Execute the geometric generation engine to paint the metal shapes
pdngen

# 7. Pause the script to visually verify the power bands
gui::show
