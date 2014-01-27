library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity NOR2 is
port(	a: in std_logic;
	b: in std_logic;
	c: out std_logic
);
end NOR2;  

---------------------------------------

architecture behave of NOR2 is
begin  
    process(a, b)
    begin
        if ((a='0') NOR (b='0')) then
	        c <= '1';
	    else
	        c <= '0';
	    end if;
    end process;
end behave;
