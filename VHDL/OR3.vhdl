library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity OR3 is
	port (a, b: in std_logic; c: out std_logic);
end OR3;

--------------------------------------

architecture dataflow of OR3 is
begin
process(a,b)
	variable d:std_logic;	
	variable e:std_logic;
	begin      
		d := a nand a;
		e := b nand b;
		c <= d nand e;
end process;
end dataflow;