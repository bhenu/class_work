library ieee;
use ieee.std_logic_1164.all;

--------------------------------

entity AND3_tb is
end AND3_tb;

architecture behav of AND3_tb is
--  Declaration of the component that will be instantiated.
component AND3
  port (a, b: in std_logic; c: out std_logic);
end component;
--  Specifies which entity is bound with the component.
for AND3_0: AND3 use entity work.AND3;
signal a,b,c : std_logic;
begin
--  Component instantiation.
AND3_0: AND3 port map (a => a, b => b, c => c);

--  This process does the real job.
process
   type pattern_type is record
      --  The inputs of the AND3.
      a, b: std_logic;
      --  The expected outputs of the AND3.
      c : std_logic;
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