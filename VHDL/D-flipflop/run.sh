#!/bin/bash

ghdl -a D-flipflop.vhdl
ghdl -a test.vhdl
ghdl -e test
ghdl -r test --stop-time=50ns --vcd=op.vcd
gtkwave op.vcd
