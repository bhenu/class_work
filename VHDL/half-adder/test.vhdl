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
	signal a0, b0: std_logic; -- inputs
	signal s0, c0: std_logic; -- output signals

begin

	-- use FOUR_BIT_MAGNITUDE_COMPARATOR as component.
	halfadder: entity work.HALF_ADDER(behave)
		port map (a0, b0, s0, c0);

	-- begin the testing.
	main_part: process

		-- declare an array to hold the truth table
		type pattern_type is record
			--  The inputs of the halfadder.
			a0, b0: std_logic;
			--  The expected outputs of the halfadder.
			s0, c0: std_logic;
	    end record;

		--  The patterns to apply.
		type pattern_array is array (natural range <>) of pattern_type;
		
		-- specify the input signals
	  	constant patterns : pattern_array :=  (	('0', '0', '0', '0'),
	  											('0', '1', '1', '0'),
	  											('1', '0', '1', '0'),
	  											('1', '1', '0', '1'));

	begin
		--give the inputs.
		for i in patterns'range loop
			--  Set the inputs.
			a0 <= patterns(i).a0;
			b0 <= patterns(i).b0;

			--  Wait for the results.
			wait for 1 ns;

			-- check the output
			assert s0 = patterns(i).s0
				report "wrong output" severity error;

			assert c0 = patterns(i).c0
				report "wrong output" severity error;

		end loop; 

		-- testing complete
		assert false
			report "end of test" severity note;

		-- wait forever to end the simulation
		wait;

	end process main_part;
end architecture behave;