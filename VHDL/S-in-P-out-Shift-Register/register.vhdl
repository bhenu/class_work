-- implementation of a 4bit Serial in Parallel out Shift Register
-- Author Binayak Ghosh <ghoshbinayak@gmail.com>

library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity serial_register is
	port (	a, clk, clear: in std_logic;
			q0, q1, q2, q3: out std_logic);
end serial_register;

--------------------------------------

architecture behave of serial_register is
	signal x0, x1, x2, x3: std_logic := '0';
begin
	main_logic: process(clk, clear) is
	begin      
		if clear = '1' then
			x0 <= '0';
			x1 <= '0';
			x2 <= '0';
			x3 <= '0';

		elsif falling_edge(clk) then
			x3 <= x2;
			x2 <= x1;
			x1 <= x0;
			x0 <= a;
		end if ;
	end process main_logic;
	
	q0 <= x0;
	q1 <= x1;
	q2 <= x2;
	q3 <= x3;

end behave;