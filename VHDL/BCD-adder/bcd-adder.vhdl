-- Implementation of a BCD adder using 4-bit BPA
-- in structural model
-- 
-- Author: Binayak Ghosh <ghoshbinayak@gmail.com>

library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity BCD_ADDER is
	port(a0, a1, a2, a3, b0, b1, b2, b3, c0: in std_logic;
			s0, s1, s2, s3, cout: out std_logic);
end entity BCD_ADDER;

architecture structural of BCD_ADDER is
	
	signal x0, x1, x2, x3, c1, c2, k1, k2, k3: std_logic;

begin
	BPA1: entity work.BPA(structural)
		port map (a0, a1, a2, a3, b0, b1, b2, b3, c0, x0, x1, x2, x3, c1);
	BPA2: entity work.BPA(structural)
		port map (x0, x1, x2, x3, k1, c2, c2, k1, k1, s0, s1, s2, s3, OPEN);

	k1 <= '0';
	k2 <= x3 and x2;
	k3 <= x3 and x1;
	c2 <= c1 or k2 or k3;

	cout <= c2;
		
end architecture structural;