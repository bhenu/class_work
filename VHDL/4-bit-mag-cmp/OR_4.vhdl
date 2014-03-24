-- Implementation of a four input OR gate
-- using behavioral model

library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity OR_4 is
	port(a, b, c, d: in std_logic;
			e: out std_logic);
end entity OR_4;

architecture behave of OR_4 is
	begin

	and_logic: process(a, b,  c, d) is
		begin
			e <= a or b or c or d;
	end process and_logic;

end architecture behave;