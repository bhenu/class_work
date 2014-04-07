-- Testbench file to test different components
-- writen in VHDL
--
-- Autor: Binayak Ghosh

library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity test1 is
end entity test1;

architecture behave of test1 is

	-- define the internal signals.
	signal j, k, clk, clear, preset: std_logic:= '0'; -- inputs
	signal q, qbar: std_logic; -- output signals

begin

	-- use FOUR_BIT_MAGNITUDE_COMPARATOR as component.
	JKFF: entity work.JK_FF(behave)
		port map (j, k, clk, clear, preset, q, qbar);

	-- begin the testing.
	main_part: process
	begin
		--give the inputs.
		preset <= '0';
		clear <= '0';
		wait for 5 ns;
		
		wait for 4 ns;
		j <= '1';
		
		wait for 7 ns;
		j <= '0';

		wait for 5 ns;
		preset <= '1';
		clear <= '0';

		wait for 6 ns;
		preset <= '0';
		clear <= '0';

		wait for 6 ns;
		preset <= '0';
		clear <= '1';

		wait for 5 ns;
		preset <= '0';
		clear <= '0';

		assert q = '1'
			report "wrong output" severity error;

		wait for 1 ns;
		k <= '1';

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