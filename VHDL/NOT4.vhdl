library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity NOT4 is
	port (a: in std_logic; b: out std_logic);
end NOT4;

--------------------------------------

architecture dataflow of NOT4 is
begin
process(a)
	begin      
		b <= a nor a;
end process;
end dataflow;