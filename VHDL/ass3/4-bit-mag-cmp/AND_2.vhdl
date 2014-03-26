-- Implementation of a two input AND gate
-- using behavioral model

library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity AND_2 is
	port(a, b: in std_logic;
			c: out std_logic);
end entity AND_2;

architecture behave of AND_2 is
	begin

	and_logic: process(a,b) is
		begin
			c <= a and b;
	end process and_logic;

end architecture behave;