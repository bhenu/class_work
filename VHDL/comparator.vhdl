library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity COMPARATOR is
port(	a,b: in std_logic;
	c, d, e: out std_logic
);
end COMPARATOR;  

---------------------------------------

architecture behave of COMPARATOR is
begin  
    c <= a xor b;
    d <= a;
    e <= not a;
end behave;