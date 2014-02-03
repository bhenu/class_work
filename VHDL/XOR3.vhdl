library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity XOR3 is
	port (a, b: in std_logic; c: out std_logic);
end XOR3;

--------------------------------------

architecture dataflow of XOR3 is
begin
process(a,b)
	variable d:std_logic;	
	variable e:std_logic;		
	variable f:std_logic;
	begin      
		d := a nor b;
		e := a nor d;
		f := d nor b;
		c <= e nor f;
end process;
end dataflow;