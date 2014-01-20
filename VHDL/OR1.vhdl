--------------------------------------
-- OR gate (ESD book figure 2.3)
--
-- two descriptions provided
--------------------------------------

library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity OR1 is
port(	a: in std_logic;
	b: in std_logic;
	c: out std_logic
);
end OR1;  

---------------------------------------

architecture OR_arch of OR1 is
begin
    
    process(a, b)
    begin
        -- compare to truth table
        if ((a='0') and (b='0')) then
	    c <= '0';
	else
	    c <= '1';
	end if;
    end process;

end OR_arch;

