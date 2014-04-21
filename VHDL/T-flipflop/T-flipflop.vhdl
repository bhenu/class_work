library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity T_FF is
	port (	t, clk: in std_logic;
			q: out std_logic);
end T_FF;

--------------------------------------

architecture behave of T_FF is
	signal state: std_logic := '0';
begin

	main_logic: process(clk) is
	begin      
		if falling_edge(clk) then
			if t = '1' then
				state <= not state;
			end if;			
		end if ;
	end process main_logic;

	q <= state;
	
end behave;