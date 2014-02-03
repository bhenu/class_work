
library ieee;				
use ieee.std_logic_1164.all;
use work.all;

--------------------------------------
entity AND3 is
port(input1: in std_logic;
	input2: in std_logic;
	output1: out std_logic
	);
end AND3;

architecture struct of AND3 is

    component NAND2 is		-- as entity of NAND2
    port(   a:	in std_logic;
    	    b:	in std_logic;
            c:	out std_logic
    );
    end component;
    signal wire1: std_logic;
    signal wire2: std_logic;		-- signal just like wire
begin

    -- use sign "=>" to clarify the pin mapping

    Gate1: NAND2 port map (a=>input1, b=>input2, c=>wire1);
    Gate2: NAND2 port map (a=>wire1, b=>wire1, c=>output1);

end struct;