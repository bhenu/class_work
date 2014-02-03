library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity FullAdder is
	port (a, b, cin: in std_logic; sum, carry: out std_logic);
end FullAdder;

--------------------------------------

architecture dataflow of FullAdder is
begin
process(a,b, cin)
	variable d:std_logic;	
	variable e:std_logic;
	begin 
		d := a xor b;
		e := a and b;     
		sum <= cin xor d;
		carry <= e or (d and cin);
end process;
end dataflow;