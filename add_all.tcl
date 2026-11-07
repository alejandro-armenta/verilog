
# get the number of facilities 

set max_facs [gtkwave::getNumFacs]

set all_signals [list]

for {set i 0} {$i < $max_facs} {incr i} {
    lappend all_signals [gtkwave::getFacName $i]
}

# puts $all_signals

if {[llength $all_signals] > 0} {
    gtkwave::addSignalsFromList $all_signals
}

gtkwave::/Time/Zoom/Zoom_Full

# gtkwave::/View/Fullscreen

# wm attributes . -fullscreen 1

# gtkwave::/View/Maximize
