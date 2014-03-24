-- Implementation of a four input AND gate
-- using behavioral model

library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity AND_4 is
	port(a, b, c, d: in std_logic;
			e: out std_logic);
end entity AND_4;

architecture behave of AND_4 is
	begin

	and_logic: process(a, b, c, d) is
		begin
			e <= a and b and c and d;
	end process and_logic;

end architecture behave;