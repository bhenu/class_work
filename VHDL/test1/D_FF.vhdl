library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity D_FF is
	port (	d, clk: in std_logic;
			q, qbar: out std_logic);
end D_FF;

--------------------------------------

architecture behave of D_FF is
	signal state: std_logic := '0';
begin

	main_logic: process(clk) is
	begin
		if falling_edge(clk) then
			state <= d;				
		end if ;
	end process main_logic;

	q <= state;
	qbar <= not state;
	
end behave;




