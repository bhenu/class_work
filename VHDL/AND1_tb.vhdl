entity AND1_tb is
end AND1_tb;

architecture behav of AND1_tb is
--  Declaration of the component that will be instantiated.
component AND1
  port (a, b: in bit; c: out bit);
end component;
--  Specifies which entity is bound with the component.
for AND1_0: AND1 use entity work.AND1;
signal a,b,c : bit;
begin
--  Component instantiation.
AND1_0: AND1 port map (a => a, b => b, c => c);

--  This process does the real job.
process
   type pattern_type is record
      --  The inputs of the AND1.
      a, b: bit;
      --  The expected outputs of the AND1.
      c : bit;
   end record;
   --  The patterns to apply.
   type pattern_array is array (natural range <>) of pattern_type;
   constant patterns : pattern_array :=
     (('0', '0', '0'),
      ('1', '0', '0'),
      ('0', '1', '0'),
      ('1', '1', '1'));
begin
   --  Check each pattern.
   for i in patterns'range loop
      --  Set the inputs.
      a <= patterns(i).a;
      b <= patterns(i).b;
      --  Wait for the results.
      wait for 1 ns;
      --  Check the outputs.
      assert c = patterns(i).c
         report "bad and value" severity error;
    end loop;
   assert false report "end of test" severity note;
   --  Wait forever; this will finish the simulation.
   wait;
end process;
end behav;