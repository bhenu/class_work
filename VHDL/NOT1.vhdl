library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity NOT1 is
	port (a: in bit; b: out bit);
end NOT1;

--------------------------------------

architecture dataflow of NOT1 is
begin
	b <= not a;
end dataflow;
