-- Implementation of a 1 bit magnitude comparator
-- using structural modeling
--
-- Author: Binayak Ghosh <ghoshbinayak@gmail.com>

library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity BOOL_EXP is
	port(a, b, c, d: in std_logic;
		f: out std_logic);
end entity BOOL_EXP;

architecture structural of BOOL_EXP is
		
	-- declare the internal signals
	signal 	ab, ad, cad: std_logic;
begin		
	and1: entity work.AND_2(behave)
		port map (a, b, ab);
	or1: entity work.OR_2(behave)
		port map (a, d, ad);
	and2: entity work.AND_2(behave)
		port map (ad, c, cad);	
	or2: entity work.OR_2(behave)
		port map (cad, ab, f);

end architecture structural;