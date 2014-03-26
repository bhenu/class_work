-- Implementation of a 4 bit binary parallel adder
-- using structural model
-- 
-- Author: Binayak Ghosh <ghoshbinayak@gmail.com>

library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity BPA is
	port(a0, a1, a2, a3, b0, b1, b2, b3, c0: in std_logic;
			s0, s1, s2, s3, cout: out std_logic);
end entity BPA;

architecture structural of BPA is
	
	signal c1, c2, c3: std_logic;

	begin
	FA1: entity work.FULL_ADDER(structural)
		port map (a0, b0, c0, s0, c1);
	FA2: entity work.FULL_ADDER(structural)
		port map (a1, b1, c1, s1, c2);
	FA3: entity work.FULL_ADDER(structural)
		port map (a2, b2, c2, s2, c3);
	FA4: entity work.FULL_ADDER(structural)
		port map (a3, b3, c3, s3, cout);
		
end architecture structural;