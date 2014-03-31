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
	signal input_1, input_2, less_than, equal_to, greater_than: std_logic;

begin

	-- use AND_2 as component.
	one_bit_comparator: entity work.ONE_BIT_COMPARATOR(behavioral)
		port map (a=>input_1, b=> input_2, c=>less_than, d=> equal_to, e=>greater_than);

	-- begin the testing.
	main_part: process

		-- declare an array to hold the truth table
		type pattern_type is record
	              --  The inputs of the adder.
	              input_1, input_2: std_logic;
	              --  The expected outputs of the adder.
	              less_than, equal_to, greater_than : std_logic;
	           end record;

		--  The patterns to apply.
		type pattern_array is array (natural range <>) of pattern_type;
		
		-- specify the input signals
	  	constant patterns : pattern_array :=  (('0', '0', '0', '1', '0'),
										      ('0', '1', '1', '0', '0'),
										      ('1', '0', '0', '0', '1'),
										      ('1', '1', '0', '1', '0'));

	begin
		--give the inputs.
		for i in patterns'range loop
			--  Set the inputs.
			input_1 <= patterns(i).input_1;
			input_2 <= patterns(i).input_2;

			--  Wait for the results.
			wait for 1 ns;

			-- check the output
			assert less_than = patterns(i).less_than
				report "wrong output on condition" severity error;

			assert equal_to = patterns(i).equal_to
				report "wrong output on condition" severity error;

			assert greater_than = patterns(i).greater_than
				report "wrong output on condition" severity error;

		end loop; 

		-- testing complete
		assert false
			report "end of test" severity note;

		-- wait forever to end the simulation
		wait;

	end process main_part;
end architecture behave;