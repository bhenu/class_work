#!/bin/bash

ghdl -a AND_2.vhdl
ghdl -a AND_3.vhdl
ghdl -a AND_4.vhdl
ghdl -a OR_4.vhdl
ghdl -a NOT_1.vhdl
ghdl -a NOR_2.vhdl
ghdl -a comparator.vhdl
ghdl -a 4-bit-mag-cmptr.vhdl
ghdl -a test.vhdl
ghdl -e test
ghdl -r test --vcd=op.vcd
gtkwave op.vcd
