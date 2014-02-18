library ieee;
use ieee.std_logic_1164.all;

--------------------------------------
-- AND gate with three inputs
entity AND5 is
	port (a, b, c: in std_logic; d: out std_logic);
end AND5;

architecture behave of AND5 is
begin
	process(a,b,c)	
	variable e: std_logic;
	begin      
		e := a and b;
		d <= c and e;
	end process;
end behave;

-------------------------------------
-- OR gate with three inputs
library ieee;
use ieee.std_logic_1164.all;

entity OR5 is
	port (a, b, c, d: in std_logic; e: out std_logic);
end OR5;

architecture behave of OR5 is
begin
	process(a,b,c,d)
	begin
		e <= a or b or c or d;
	end process;
end behave;

-------------------------------------
-- describing the MUX
library ieee;
use ieee.std_logic_1164.all;

entity MUX1 is
	port (d0, d1, d2, d3, s0, s1: in std_logic; X: out std_logic);
end MUX1;

architecture struct of MUX1 is
	component NOT2
	  port (a: in std_logic; b: out std_logic);
	end component;
	--  Specifies which entity is bound with the component.
	for not0: NOT2 use entity work.NOT2;
	for not1: NOT2 use entity work.NOT2;
	signal s0_1, s1_1, a0, a1, a2, a3: std_logic;
begin
	not0: NOT2
			port map (s0, s0_1);
	not1: NOT2
			port map (s1, s1_1);
	and0: entity work.AND5(behave)
			port map (d0, s0, s1, a0);
	and1: entity work.AND5(behave)
			port map (d1, s0, s1_1, a1);
	and2: entity work.AND5(behave)
			port map (d2, s0_1, s1, a2);
	and3: entity work.AND5(behave)
			port map (d3, s0_1, s1_1, a3);
	or1: entity work.OR5(behave)
			port map(a0, a1, a2, a3, X);
end struct;


------------------------------------