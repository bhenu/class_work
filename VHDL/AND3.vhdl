library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity AND3 is
	port (a, b: in std_logic; c: out std_logic);
end AND3;

--------------------------------------

architecture dataflow of AND3 is
begin
process(a,b)
	variable d:std_logic;
	begin      
		d := a nand b;
		c <= d nand d;
end process;
end dataflow;

