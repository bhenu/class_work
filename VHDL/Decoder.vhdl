library ieee;
use ieee.std_logic_1164.all;

--------------------------------------

entity Decoder is
	port (A0, A1: in std_logic; D0, D1, D2, D3: out std_logic);
end Decoder;

--------------------------------------

architecture dataflow of Decoder is
begin
process(A0,A1)
	begin 
		D0 <= (not A0) and (not A1);
		D1 <= A0 and (not A1);
		D2 <= (not A0) and A1;
		D3 <= A0 and A1;
end process;
end dataflow;