#!/bin/bash

ghdl -a AND_2.vhdl
ghdl -a OR_2.vhdl
ghdl -a bool.vhdl
ghdl -a test3.vhdl
ghdl -e test3
ghdl -r test3 --vcd=op.vcd
gtkwave op.vcd
