-- Implementation of a 4 bit magnitude comparator
-- using structural model
-- (The circuit design is taken from Morris and Mano book pg: 150)
--
-- Author: Binayak Ghosh <ghoshbinayak@gmail.com>

library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity FOUR_BIT_MAGNITUDE_COMPARATOR is
	port(a0, a1, a2, a3, b0, b1, b2, b3: in std_logic;
		c, d, e: out std_logic);
end entity FOUR_BIT_MAGNITUDE_COMPARATOR;

architecture structural of FOUR_BIT_MAGNITUDE_COMPARATOR is
		
	-- declare the internal signals
	signal 	x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11: std_logic; -- outputs from the single bit comparators
	signal 	z0, z1, z2, z3, z4, z5, z6: std_logic; -- outputs from the and gates
	signal tmp1, tmp2: std_logic;

begin		
	cmp0: entity work.ONE_BIT_COMPARATOR(structural)
		port map (a0, b0, x0, x1, x2);
	cmp1: entity work.ONE_BIT_COMPARATOR(structural)
		port map (a1, b1, x3, x4, x5);
	cmp2: entity work.ONE_BIT_COMPARATOR(structural)
		port map (a2, b2, x6, x7, x8);
	cmp3: entity work.ONE_BIT_COMPARATOR(structural)
		port map (a3, b3, x9, x10, x11);
	and0: entity work.AND_2(behave)
		port map (x10, x6, z0);
	and1: entity work.AND_2(behave)
		port map (x10, x8, z1);
	and2: entity work.AND_3(behave)
		port map (x10, x7, x3, z2);
	and3: entity work.AND_3(behave)
		port map (x10, x7, x5, z3);
	and4: entity work.AND_4(behave)
		port map (x10, x7, x4, x0, z4);
	and5: entity work.AND_4(behave)
		port map (x10, x7, x4, x2, z5);
	and6: entity work.AND_4(behave)
		port map (x10, x7, x4, x1, z6);
	or0: entity work.OR_4(behave)
		port map (x9, z0, z2, z4, tmp1);
	or1: entity work.OR_4(behave)
		port map (z1, x11, z3, z5, tmp2);
		
	c <= tmp1;		
	d <= z6;
	e <= tmp2;
end architecture structural;