library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity OR1 is
	port (a, b: in bit; c: out bit);
end OR1;

--------------------------------------

architecture dataflow of AND1 is
begin
	c <= a or b;
end dataflow;
