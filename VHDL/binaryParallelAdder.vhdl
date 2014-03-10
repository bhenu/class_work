library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity ParallelAdder is
	port (a0, a1, a2, a3, b0, b1, b2, b3: in std_logic;
		 s0, s1, s2, s3, carry: out std_logic);
end ParallelAdder;

--------------------------------------

architecture structural of ParallelAdder is
	-- full adder is included as a component
	component FullAdder
		port (a, b, cin: in std_logic; sum, carry: out std_logic);
	end component;
	-- associate the components
	for FA0: FullAdder use entity work.FullAdder;
	for FA1: FullAdder use entity work.FullAdder;
	for FA2: FullAdder use entity work.FullAdder;
	for FA3: FullAdder use entity work.FullAdder;
	-- declare the signals
	signal c0, c1, c2, c3: std_logic;
	signal var: std_logic:= '0';
begin
	FA0: FullAdder port map (
		a => a0,
		b => b0,
		cin => var,
		sum => s0,
		carry => c0);

	FA1: FullAdder port map (
		a => a1,
		b => b1,
		cin => c0,
		sum => s1,
		carry => c1);

	FA2: FullAdder port map (
		a => a2,
		b => b2,
		cin => c1,
		sum => s2,
		carry => c2);

	FA3: FullAdder port map (
		a => a3,
		b => b3,
		cin => c2,
		sum => s3,
		carry => c3);

	carry <= c3;
end structural;