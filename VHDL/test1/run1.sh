#!/bin/bash

ghdl -a JK-flipflop.vhdl
ghdl -a test1.vhdl
ghdl -e test1
ghdl -r test1 --stop-time=50ns --vcd=op.vcd
gtkwave op.vcd
