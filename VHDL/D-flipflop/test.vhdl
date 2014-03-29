-- Testbench file to test different components
-- writen in VHDL
--
-- Autor: Binayak Ghosh

library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity test is
end entity test;

architecture behave of test is

	-- define the internal signals.
	signal d, clk: std_logic:= '0'; -- inputs
	signal q: std_logic; -- output signals

begin

	-- use FOUR_BIT_MAGNITUDE_COMPARATOR as component.
	dFF: entity work.D_FF(behave)
		port map (d, clk, q);

	-- begin the testing.
	main_part: process
	begin
		--give the inputs.
		wait for 4 ns;
		d <= '1';
		wait for 7 ns;

		assert q = '1'
			report "wrong output" severity error;

		wait for 1 ns;
		d <= '0';

		assert q = '0'
			report "wrong output" severity error;
		
		assert false
			report "end of test" severity note;

		-- wait forever to end the simulation
		wait;

	end process main_part;

	-- Process for generating the clock
	clock_generator: process is
	begin
		wait for 5 ns;
		clk <= '1';
		wait for 5 ns;
		clk <= '0';
	end process clock_generator;

end architecture behave;