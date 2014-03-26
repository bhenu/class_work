-- Implementation of a 1 bit magnitude comparator
-- using structural modeling
--
-- Author: Binayak Ghosh <ghoshbinayak@gmail.com>

library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity ONE_BIT_COMPARATOR is
	port(a, b: in std_logic;
		c, d, e: out std_logic);
end entity ONE_BIT_COMPARATOR;

architecture behavioral of ONE_BIT_COMPARATOR is
		
	-- declare the internal signals
	signal 	not1_output, not2_output,
			and1_output, and2_output: std_logic;
begin		
	not1: entity work.NOT_1(behave)
		port map (a=> a, b=> not1_output);
	not2: entity work.NOT_1(behave)
		port map (a=> b, b=> not2_output);
	and1: entity work.AND_2(behave)
		port map (a=> not1_output, b=> b, c=>and1_output);
	and2: entity work.AND_2(behave)
		port map (a=> a, b=> not2_output, c=>and2_output);
	nor1: entity work.NOR_2(behave)
		port map (a=> and1_output, b=>and2_output, c=> d);
	
	c <= and1_output;
	e <= and2_output;

end architecture behavioral;