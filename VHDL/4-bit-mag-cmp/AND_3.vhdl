-- Implementation of a three input AND gate
-- using behavioral model

library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity AND_3 is
	port(a, b, c: in std_logic;
			d: out std_logic);
end entity AND_3;

architecture behave of AND_3 is
	begin

	and_logic: process(a, b, c) is
		begin
			d <= a and b and c;
	end process and_logic;

end architecture behave;