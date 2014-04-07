library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity JK_FF is
	port (	j, k, clk, clear, preset: in std_logic;
			q, qbar: out std_logic);
end JK_FF;

--------------------------------------

architecture behave of JK_FF is
	signal state: std_logic := '0';
begin

	main_logic: process(clk) is
	begin

		if clear = '1' then
			state <= '0';

		elsif preset = '1' then
			state <= '1';

		elsif falling_edge(clk) then
			if j = '1' and k = '0' then
				state <= '0';
			elsif j='0' and k = '1' then
				state <= '1';
			elsif j = '1' and k = '1' then
				state <= not state;
			end if ;				
		end if ;
	end process main_logic;

	q <= state;
	qbar <= not state;
	
end behave;

