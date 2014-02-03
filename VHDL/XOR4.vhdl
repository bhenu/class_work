library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity XOR4 is
	port (a, b: in std_logic; c: out std_logic);
end XOR4;

--------------------------------------

architecture dataflow of XOR4 is
begin
process(a,b)
	variable d:std_logic;	
	variable e:std_logic;		
	variable f:std_logic;
	begin      
		d := a nand b;
		e := a nand d;
		f := d nand b;
		c <= e nand f;
end process;
end dataflow;