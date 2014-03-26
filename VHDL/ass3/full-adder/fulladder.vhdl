-- Implementation of a full adder
-- using structural model
-- 
-- Author: Binayak Ghosh <ghoshbinayak@gmail.com>

library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity FULL_ADDER is
	port(a, b, cin: in std_logic;
			sum, carry: out std_logic);
end entity FULL_ADDER;

architecture behave of FULL_ADDER is
	
	signal sum1, carry1, carry2: std_logic;

	begin
	HA1: entity work.HALF_ADDER(behave)
		port map (a, b, sum1, carry1);
	HA2: entity work.HALF_ADDER(behave)
		port map (sum1, cin, sum, carry2);
		
	carry <= carry1 or carry2;

end architecture behave;