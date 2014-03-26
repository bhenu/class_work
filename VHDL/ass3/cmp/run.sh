#!/bin/bash

if [ $# -eq 0 ]
  then
    printf "error: no file specified.\nUsage: run.sh <file name>\n"
else
	ghdl -a $1
	ghdl -a test.vhdl
	ghdl -e test
	ghdl -r test --vcd=op.vcd
	gtkwave op.vcd
fi