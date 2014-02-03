library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity HalfAdder is
	port (a, b: in std_logic; sum, carry: out std_logic);
end HalfAdder;

--------------------------------------

architecture dataflow of HalfAdder is
begin
process(a,b)
	begin      
		sum <= a xor b;
		carry <= a and b;
end process;
end dataflow;