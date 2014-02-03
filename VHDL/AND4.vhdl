library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity AND4 is
	port (a, b: in std_logic; c: out std_logic);
end AND4;

--------------------------------------

architecture dataflow of AND4 is
begin
process(a,b)
	variable d:std_logic;	
	variable e:std_logic;
	begin      
		d := a nor a;
		e := b nor b;
		c <= d nor
end process;
end dataflow;