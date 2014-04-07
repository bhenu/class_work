-- Testbench file to test different components
-- writen in VHDL
--
-- Autor: Binayak Ghosh

library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity test3 is
end entity test3;

architecture behave of test3 is

	-- define the internal signals.
	signal a, b, c, d, f: std_logic;

begin

	-- use AND_2 as component.
	one_bit_comparator: entity work.BOOL_EXP(structural)
		port map ( a, b, c, d, f);

	-- begin the testing.
	main_part: process

		-- declare an array to hold the truth table
		type pattern_type is record
	              --  The inputs of the adder.
	              a, b, c, d: std_logic;
	              --  The expected outputs of the adder.
	              f : std_logic;
	           end record;

		--  The patterns to apply.
		type pattern_array is array (natural range <>) of pattern_type;
		
		-- specify the input signals
	  	constant patterns : pattern_array := (('0', '0', '0', '0', '0'),
										      ('0', '0', '0', '1', '0'),
										      ('0', '0', '1', '0', '0'),
										      ('0', '0', '1', '1', '0'),
										      ('0', '1', '0', '0', '0'),
										      ('0', '1', '0', '1', '0'),
										      ('0', '1', '1', '0', '0'),
										      ('0', '1', '1', '1', '0'),
										      ('1', '0', '0', '0', '0'),
										      ('1', '0', '0', '1', '0'),
										      ('1', '0', '1', '0', '0'),
										      ('1', '0', '1', '1', '0'),
										      ('1', '1', '0', '0', '0'),
										      ('1', '1', '0', '1', '0'),
										      ('1', '1', '1', '0', '0'),
										      ('1', '1', '1', '1', '0'));

	begin
		--give the inputs.
		for i in patterns'range loop
			--  Set the inputs.
			a <= patterns(i).a;
			b <= patterns(i).b;
			c <= patterns(i).c;
			d <= patterns(i).d;

			--  Wait for the results.
			wait for 1 ns;

			assert f = patterns(i).f
				report "wrong output on condition" severity error;

		end loop; 

		-- testing complete
		assert false
			report "end of test" severity note;

		-- wait forever to end the simulation
		wait;

	end process main_part;
end architecture behave;