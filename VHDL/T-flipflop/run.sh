#!/bin/bash

ghdl -a T-flipflop.vhdl
ghdl -a test.vhdl
ghdl -e test
ghdl -r test --stop-time=150ns --vcd=op.vcd
gtkwave op.vcd
