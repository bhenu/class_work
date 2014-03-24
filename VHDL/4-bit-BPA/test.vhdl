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
	signal a0, a1, a2, a3, a4, b0, b1, b2, b3, c0: std_logic; -- inputs
	signal s0, s1, s2, s3, cout: std_logic; -- output signals

begin

	-- use FOUR_BIT_MAGNITUDE_COMPARATOR as component.
	bpa: entity work.BPA(structural)
		port map (a0, a1, a2, a3, a4, b0, b1, b2, b3, c0, s0, s1, s2, s3, cout);

	-- begin the testing.
	main_part: process

		-- declare an array to hold the truth table
		type pattern_type is record
	              --  The inputs of the comparator.
	              a3, a2, a1, a0, b3, b2, b1, b0, c0: std_logic;
	              --  The expected outputs of the comparator.
	              s3, s2, s1, s0, cout: std_logic;
	    end record;

		--  The patterns to apply.
		type pattern_array is array (natural range <>) of pattern_type;
		
		-- specify the input signals
	  	constant patterns : pattern_array :=  (	('0', '1', '1', '0',
	  											'1', '0', '0', '0', '0',
	  											'1', '1', '1', '0', '0'),

	  											('1', '0', '0', '1',
	  											'1', '1', '1', '0', '0',
	  											'0', '1', '1', '1', '1'),

	  											('1', '0', '0', '1',
	  											'1', '1', '1', '0', '1',
	  											'1', '0', '0', '0', '1'));
	begin
		--give the inputs.
		for i in patterns'range loop
			--  Set the inputs.
			a0 <= patterns(i).a0;
			a1 <= patterns(i).a1;
			a2 <= patterns(i).a2;
			a3 <= patterns(i).a3;
			b0 <= patterns(i).b0;
			b1 <= patterns(i).b1;
			b2 <= patterns(i).b2;
			b3 <= patterns(i).b3;
			c0 <= patterns(i).c0;

			--  Wait for the results.
			wait for 1 ns;

			-- check the output
			assert s0 = patterns(i).s0
				report "wrong output" severity error;

			assert s1 = patterns(i).s1
				report "wrong output" severity error;

			assert s2 = patterns(i).s2
				report "wrong output" severity error;

			assert s3 = patterns(i).s3
				report "wrong output" severity error;

			assert cout = patterns(i).cout
				report "wrong output" severity error;

		end loop; 

		-- testing complete
		assert false
			report "end of test" severity note;

		-- wait forever to end the simulation
		wait;

	end process main_part;
end architecture behave;