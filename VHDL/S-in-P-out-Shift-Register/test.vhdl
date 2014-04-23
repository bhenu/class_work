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
	signal a, clear, clk: std_logic:= '0'; -- inputs
	signal q0, q1, q2, q3: std_logic; -- output signals

begin

	-- use FOUR_BIT_MAGNITUDE_COMPARATOR as component.
	rigester: entity work.serial_register(behave)
		port map (a, clk, clear, q0, q1, q2, q3);

	-- begin the testing.
	main_part: process
	begin
		clear <= '1';
		wait for 10 ns;
		clear <= '0';
		a <= '1';
		wait for 5 ns;
		a <= '0';
		wait for 35 ns;

		clear <= '1';


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