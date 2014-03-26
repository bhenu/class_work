-- Implementation of a half adder
-- using behavioral model
-- 
-- Author: Binayak Ghosh <ghoshbinayak@gmail.com>

library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity HALF_SUBTRACTOR is
	port(a, b: in std_logic;
			result, carry: out std_logic);
end entity HALF_SUBTRACTOR;

architecture behave of HALF_SUBTRACTOR is
	begin

	main_logic: process(a,b) is
		begin
			result <= a xor b;
			carry <= (not a) and b;
	end process main_logic;

end architecture behave;

-------------------------------------

architecture dataflow of HALF_SUBTRACTOR is
	begin
		result <= a xor b;
		carry <= (not a) and b;
end architecture dataflow;

-------------------------------------

architecture structural of HALF_SUBTRACTOR is
	
		signal anot: std_logic;

	begin

		xor1: entity work.XOR_2(behave)
			port map(a, b, result);
		not1: entity work.NOT_1(behave)
			port map (a, anot);
		and1: entity work.AND_2(behave)
			port map (anot, b, carry);

end architecture structural;