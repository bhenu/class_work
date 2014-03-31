#!/bin/bash

ghdl -a AND_2.vhdl
ghdl -a NOR_2.vhdl
ghdl -a NOT_1.vhdl
ghdl -a comparator.vhdl
ghdl -a test.vhdl
ghdl -e test
ghdl -r test --vcd=op.vcd
# gtkwave op.vcd
