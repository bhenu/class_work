library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity XOR1 is
	port (a, b: in bit; c: out bit);
end XOR1;

--------------------------------------

architecture dataflow of XOR1 is
begin
	c <= a xor b;
end dataflow;
