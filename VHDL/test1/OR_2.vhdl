-- Implementation of a four input OR gate
-- using behavioral model

library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity OR_2 is
	port(a, b: in std_logic;
			c: out std_logic);
end entity OR_2;

architecture behave of OR_2 is
	begin

	or_logic: process(a, b) is
		begin
			c <= a or b;
	end process or_logic;

end architecture behave;