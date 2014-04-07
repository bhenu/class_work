library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity D_FF is
	port (	d, clk, clear, preset: in std_logic;
			q: out std_logic);
end D_FF;

--------------------------------------

architecture behave of D_FF is
	signal state: std_logic := '0';
begin

	main_logic: process(clk, clear, preset) is
	begin
		if clear = '1' then 
			state <= '0';
		elsif preset = '1' then
			state <= '1';
		elsif falling_edge(clk) then
			state <= d;				
		end if ;
	end process main_logic;

	q <= state;
	
end behave;

