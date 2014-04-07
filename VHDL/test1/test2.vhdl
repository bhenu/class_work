-- Testbench file to test different components
-- writen in VHDL
--
-- Autor: Binayak Ghosh

library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity test2 is
end entity test2;

architecture behave of test2 is

	-- define the internal signals.
	signal d, clk, clear, preset: std_logic:= '0'; -- inputs
	signal q: std_logic; -- output signals

begin

	-- use FOUR_BIT_MAGNITUDE_COMPARATOR as component.
	dFF: entity work.D_FF(behave)
		port map (d, clk, clear, preset, q);

	-- begin the testing.
	main_part: process
	begin
		--give the inputs.
		wait for 4 ns;
		d <= '0';
		clear <= '0';
		preset <= '0';

		wait for 7 ns;

		wait for 1 ns;
		d <= '1';
		clear <= '0';
		preset <= '0';

		wait for 5 ns;
		d <= '0';
		clear <= '0';
		preset <= '1';

		wait for 5 ns;
		d <= '0';
		clear <= '0';
		preset <= '0';
		
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