-- Implementation of a single input NOT gate
-- using behavioral model

library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity NOT_1 is
	port(a: in std_logic;
		b: out std_logic);
end entity NOT_1;

architecture behave of NOT_1 is
	begin

	not_logic: process(a) is
		begin
			b <= not a;
	end process not_logic;

end architecture behave;