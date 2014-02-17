library ieee;
use ieee.std_logic_1164.all;

--------------------------------

entity test is
end test;

architecture behav of test is
--  Declaration of the component that will be instantiated.
component MUX1
  port (d0, d1, d2, d3, s0, s1: in std_logic; X: out std_logic);
end component;
--  Specifies which entity is bound with the component.
for MUX1_0: MUX1 use entity work.MUX1;
signal d0, d1, d2, d3, s0, s1, X:  std_logic;
begin
--  Component instantiation.
MUX1_0: MUX1 port map (d0, d1, d2, d3, s0, s1, X);

--  This process does the real job.
process
   type pattern_type is record
      --  The inputs of the MUX1.
      d0: std_logic;      
      d1: std_logic;
      d2: std_logic;
      d3: std_logic;      
      s0: std_logic;
      s1: std_logic;
      --  The expected outputs of the MUX1.
      X: std_logic;
   end record;
   --  The patterns to apply.
   type pattern_array is array (natural range <>) of pattern_type;
   constant patterns : pattern_array :=
     (('0', '0', '0', '0', '0', '0', '0'),
      ('0', '0', '0', '1', '0', '0', '1'),
      ('0', '0', '0', '0', '0', '1', '0'),
      ('0', '0', '1', '0', '0', '1', '1'),
      ('0', '0', '0', '0', '1', '0', '0'),
      ('0', '1', '0', '0', '1', '0', '1'),
      ('0', '0', '0', '0', '1', '1', '0'),
      ('1', '0', '0', '0', '1', '1', '1'));
begin
   --  Check each pattern.
   for i in patterns'range loop
      --  Set the inputs.
      d0 <= patterns(i).d0;      
      d1 <= patterns(i).d1;          
      d2 <= patterns(i).d2;          
      d3 <= patterns(i).d3;          
      s0 <= patterns(i).s0;          
      s1 <= patterns(i).s1;
      --  Wait for the results.
      wait for 20 ns;
      --  Check the outputs.
      assert X = patterns(i).X
         report "bad nand value" severity error;
    end loop;
   assert false report "end of test" severity note;
   --  Wait forever; this will finish the simulation.
   wait;
end process;
end behav;