#!/bin/bash
ghdl -a halfadder.vhdl
ghdl -a fulladder.vhdl
ghdl -a bpa.vhdl
ghdl -a bcd-adder.vhdl

ghdl -a test.vhdl
ghdl -e test
ghdl -r test --vcd=op.vcd
# gtkwave op.vcd
