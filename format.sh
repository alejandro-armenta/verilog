# Define the path to the Verible formatting binary
VERIBLE_BIN="/home/alejandro-armenta/verible-v0.0-4296-g0f262651-linux-static-x86_64/verible-v0.0-4296-g0f262651/bin/verible-verilog-format"

find ./ -type f -name "*.v" -exec "$VERIBLE_BIN" --inplace {} +
