entity AND1 is
	port (a, b: in bit; c: out bit);
end AND1;

architecture behave of AND1 is
begin
	c <= a and b;
end behave;
