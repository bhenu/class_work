#!/bin/bash
ghdl -a AND_2.vhdl
ghdl -a NOT_1.vhdl
ghdl -a XOR_2.vhdl
ghdl -a halfsubtractor.vhdl
ghdl -a test.vhdl
ghdl -e test
ghdl -r test --vcd=op.vcd
gtkwave op.vcd
