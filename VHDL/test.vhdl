library ieee;
use ieee.std_logic_1164.all;

--------------------------------

entity test is
end test;

architecture behav of test is
--  Declaration of the component that will be instantiated.
component HalfAdder
  port (a, b: in std_logic; sum, carry: out std_logic);
end component;
--  Specifies which entity is bound with the component.
for HalfAdder_0: HalfAdder use entity work.HalfAdder;
signal a, b, sum, carry: std_logic;
begin
--  Component instantiation.
HalfAdder_0: HalfAdder port map (a => a, b => b, sum => sum, carry => carry);

--  This process does the real job.
process
   type pattern_type is record
      --  The inputs of the HalfAdder.
      a, b: std_logic;
      --  The expected outputs of the HalfAdder.
      sum, carry : std_logic;
   end record;
   --  The patterns to apply.
   type pattern_array is array (natural range <>) of pattern_type;
   constant patterns : pattern_array :=
     (('0', '0', '0', '0'),
      ('1', '0', '1', '0'),
      ('0', '1', '1', '0'),
      ('1', '1', '0', '1'));
begin
   --  Check each pattern.
   for i in patterns'range loop
      --  Set the inputs.
      a <= patterns(i).a;
      b <= patterns(i).b;
      --  Wait for the results.
      wait for 1 ns;
      --  Check the outputs.
      assert sum = patterns(i).sum
         report "bad sum value" severity error;
      assert carry = patterns(i).carry
         report "bad carry value" severity error;
    end loop;
   assert false report "end of test" severity note;
   --  Wait forever; this will finish the simulation.
   wait;
end process;
end behav;