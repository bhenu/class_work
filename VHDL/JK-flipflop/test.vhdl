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

		-- declare an array to hold the truth table
		-- type pattern_type is record
		-- 	--  The inputs of the JKFF.
		-- 	j, k: std_logic;
		-- 	--  The expected outputs of the JKFF.
		-- 	q, qbar: std_logic;
	 --    end record;

		-- --  The patterns to apply.
		-- type pattern_array is array (natural range <>) of pattern_type;
		
		-- -- specify the input signals
	 --  	constant patterns : pattern_array :=  (	('1', '1', '1', '0'),
	 --  											('0', '1', '0', '1'),	  											
	 --  											('0', '0', '0', '1'),
	 --  											('1', '0', '1', '0'),
	 --  											('0', '0', '1', '0'),
	 --  											('1', '1', '0', '1'));

	begin
		--give the inputs.

		wait for 5 ns;
		
		wait for 4 ns;
		j <= '1';
		wait for 7 ns;
		j <= '0';

		assert q = '1'
			report "wrong output" severity error;

		wait for 1 ns;
		k <= '1';

		assert q = '1'
			report "wrong output" severity error;
		

		-- for i in patterns'range loop
		-- 	--  Set the inputs.
		-- 	j <= patterns(i).j;
		-- 	k <= patterns(i).k;

		-- 	--  Wait for the results.
		-- 	wait for 7 ns;

		-- 	-- check the output
		-- 	assert q = patterns(i).q
		-- 		report "wrong output" severity error;

		-- 	assert qbar = patterns(i).qbar
		-- 		report "wrong output" severity error;

		-- end loop; 

		-- testing complete
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