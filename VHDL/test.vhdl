library ieee;
use ieee.std_logic_1164.all;

--------------------------------

entity test is
end test;

architecture behav of test is
--  Declaration of the component that will be instantiated.
<<<<<<< HEAD
component MUX1
  port (d0, d1, d2, d3, s0, s1: in std_logic; X: out std_logic);
end component;
--  Specifies which entity is bound with the component.
for MUX1_0: MUX1 use entity work.MUX1;
signal d0, d1, d2, d3, s0, s1, X:  std_logic;
begin
--  Component instantiation.
MUX1_0: MUX1 port map (d0, d1, d2, d3, s0, s1, X);
=======
component ParallelAdder
  port (a0, a1, a2, a3, b0, b1, b2, b3: in std_logic;
       s0, s1, s2, s3, carry: out std_logic);
end component;
--  Specifies which entity is bound with the component.
for ParallelAdder_0: ParallelAdder use entity work.ParallelAdder;
signal a0, a1, a2, a3, b0, b1, b2, b3, s0, s1, s2, s3, carry: std_logic;
begin
--  Component instantiation.
ParallelAdder_0: ParallelAdder port map (
                     a0 => a0,
                     a1 => a1,
                     a2 => a2,
                     a3 => a3,
                     b0 => b0,
                     b1 => b1,
                     b2 => b2,
                     b3 => b3,
                     s0 => s0,
                     s1 => s1,
                     s2 => s2,
                     s3 => s3,
                     carry => carry
                     );
>>>>>>> github/master

--  This process does the real job.
process
   type pattern_type is record
<<<<<<< HEAD
      --  The inputs of the MUX1.
      d0: std_logic;      
      d1: std_logic;
      d2: std_logic;
      d3: std_logic;      
      s0: std_logic;
      s1: std_logic;
      --  The expected outputs of the MUX1.
      X: std_logic;
=======
      --  The inputs of the ParallelAdder.
      a0, a1, a2, a3, b0, b1, b2, b3: std_logic;
      -- The outputs of the ParallelAdder.
      s0, s1, s2, s3, carry: std_logic;
>>>>>>> github/master
   end record;
   --  The patterns to apply.
   type pattern_array is array (natural range <>) of pattern_type;
   constant patterns : pattern_array :=
<<<<<<< HEAD
     (('0', '0', '0', '0', '0', '0', '0'),
      ('0', '0', '0', '1', '0', '0', '1'),
      ('0', '0', '0', '0', '0', '1', '0'),
      ('0', '0', '1', '0', '0', '1', '1'),
      ('0', '0', '0', '0', '1', '0', '0'),
      ('0', '1', '0', '0', '1', '0', '1'),
      ('0', '0', '0', '0', '1', '1', '0'),
      ('1', '0', '0', '0', '1', '1', '1'));
=======
     (('0', '1', '0', '1', '1', '1', '1', '0', '1', '0', '0', '0', '1'),
      ('1', '0', '0', '1', '0', '0', '1', '0', '1', '0', '1', '1', '0')
      );
>>>>>>> github/master
begin
   --  Check each pattern.
   for i in patterns'range loop
      --  Set the inputs.
<<<<<<< HEAD
      d0 <= patterns(i).d0;      
      d1 <= patterns(i).d1;          
      d2 <= patterns(i).d2;          
      d3 <= patterns(i).d3;          
      s0 <= patterns(i).s0;          
      s1 <= patterns(i).s1;
=======
      a0 <= patterns(i).a0;
      a1 <= patterns(i).a1;
      a2 <= patterns(i).a2;
      a3 <= patterns(i).a3;
      b0 <= patterns(i).b0;
      b1 <= patterns(i).b1;
      b2 <= patterns(i).b2;
      b3 <= patterns(i).b3;
>>>>>>> github/master
      --  Wait for the results.
      wait for 20 ns;
      --  Check the outputs.
<<<<<<< HEAD
      assert X = patterns(i).X
         report "bad nand value" severity error;
=======
      assert s0 = patterns(i).s0
         report "bad ParallelAdder value" severity error;
      assert s1 = patterns(i).s1
         report "bad ParallelAdder value" severity error;
      assert s2 = patterns(i).s2
         report "bad ParallelAdder value" severity error;
      assert s3 = patterns(i).s3
         report "bad ParallelAdder value" severity error;      
      assert carry = patterns(i).carry
         report "bad ParallelAdder value" severity error;         
>>>>>>> github/master
    end loop;
   assert false report "end of test" severity note;
   --  Wait forever; this will finish the simulation.
   wait;
end process;
end behav;