library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity NAND1 is
	port (a, b: in bit; c: out bit);
end NAND1;

--------------------------------------

architecture dataflow of NAND1 is
begin
	c <= a nand b;
end dataflow;
