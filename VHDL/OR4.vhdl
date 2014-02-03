library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity OR4 is
	port (a, b: in std_logic; c: out std_logic);
end OR4;

--------------------------------------

architecture dataflow of OR4 is
begin
process(a,b)
	variable d:std_logic;	
	begin      
		d := a nor b;
		c <= d nand d;
end process;
end dataflow;