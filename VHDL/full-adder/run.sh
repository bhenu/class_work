#!/bin/bash

ghdl -a fulladder.vhdl
ghdl -a test.vhdl
ghdl -e test
ghdl -r test --vcd=op.vcd
gtkwave op.vcd
