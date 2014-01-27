library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity NOT2 is
port(	a: in std_logic;
	b: out std_logic;
);
end NOT2;  

---------------------------------------

architecture behave of NOT2 is
begin  
    process(a)
    begin
        if ((a='1')) then
	        b <= '0';
	    else
	        b <= '1';
	    end if;
    end process;
end behave;
