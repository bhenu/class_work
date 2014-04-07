#!/bin/bash

ghdl -a D-flipflop.vhdl
ghdl -a test2.vhdl
ghdl -e test2
ghdl -r test2 --stop-time=50ns --vcd=op.vcd
gtkwave op.vcd
