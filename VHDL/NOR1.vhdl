library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity NOR1 is
	port (a, b: in bit; c: out bit);
end NOR1;

--------------------------------------

architecture dataflow of NOR1 is
begin
	c <= a nor b;
end dataflow;
