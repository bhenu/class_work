library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity NOT3 is
	port (a: in std_logic; b: out std_logic);
end NOT3;

--------------------------------------

architecture dataflow of NOT3 is
begin
process(a)
	begin      
		b := a nand a;
end process;
end dataflow;