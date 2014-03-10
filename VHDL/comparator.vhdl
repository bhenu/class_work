library ieee;
use ieee.std_logic_1164.all;

--------------------------------------
-- AND gate with three inputs
entity COMPARATOR is
	port (a, b: in std_logic; c, d, e: out std_logic);
end COMPARATOR;

architecture behave of COMPARATOR is
begin
	process(a, b)
	begin
		if ((a xor b) = '0') then
			c <= '1';
		else
			if (not a xor b = '0') then
				d <= '1';
			else
				e <= '1';
			end if;
		end if;
	end process;
end behave;