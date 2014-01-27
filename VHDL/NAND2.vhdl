library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity AND2 is
port(	a: in std_logic;
	b: in std_logic;
	c: out std_logic
);
end AND2;  

---------------------------------------

architecture behave of OR2 is
begin  
    process(a, b)
    begin
        if ((a='1') and (b='1')) then
	        c <= '0';
	    else
	        c <= '1';
	    end if;
    end process;
end behave;
