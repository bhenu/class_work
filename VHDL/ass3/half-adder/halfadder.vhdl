-- Implementation of a half adder
-- using behavioral model
-- 
-- Author: Binayak Ghosh <ghoshbinayak@gmail.com>

library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity HALF_ADDER is
	port(a, b: in std_logic;
			sum, carry: out std_logic);
end entity HALF_ADDER;

architecture behave of HALF_ADDER is
	begin

	main_logic: process(a,b) is
		begin
			sum <= a xor b;
			carry <= a and b;
	end process main_logic;

end architecture behave;