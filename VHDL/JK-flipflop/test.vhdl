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
	signal j, k, clk: std_logic:= '0'; -- inputs
	signal q, qbar: std_logic; -- output signals

begin

	-- use FOUR_BIT_MAGNITUDE_COMPARATOR as component.
	JKFF: entity work.JK_FF(behave)
		port map (j, k, clk, q, qbar);

	-- begin the testing.
	main_part: process


	begin
		
		wait for 2 ns; --give some time offset.

		--give the inputs.
		wait for 30 ns;
		j <= '1';
		k <= '0';
			
		wait for 30 ns;
		assert q = '1'
			report "wrong output" severity error;

		k <= '0';
		j <= '0';

		wait for 30 ns;
		assert q = '1'
			report "wrong output" severity error;

		k <= '1';
		j <= '0';
		wait for 30 ns;
		assert q = '0'
			report "wrong output" severity error;

		k <= '0';
		j <= '0';

		wait for 30 ns;
		assert q = '0'
			report "wrong output" severity error;

		j <= '1';
		k <= '1';
		wait for 50 ns;
		assert q = '1'
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