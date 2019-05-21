--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   08:43:38 05/14/2019
-- Design Name:   
-- Module Name:   /home/rassat/Bureau/4A/s2/projetsystinfo/proj_syst_info/decode_test.vhd
-- Project Name:  proj_syst_info
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: decode
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY decode_test IS
END decode_test;
 
ARCHITECTURE behavior OF decode_test IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT decode
    PORT(
         ins_di : IN  std_logic_vector(31 downto 0);
         OP : OUT  std_logic_vector(7 downto 0);
         A : OUT  std_logic_vector(15 downto 0);
         B : OUT  std_logic_vector(15 downto 0);
         C : OUT  std_logic_vector(15 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal ins_di : std_logic_vector(31 downto 0) := (others => '0');

 	--Outputs
   signal OP : std_logic_vector(7 downto 0);
   signal A : std_logic_vector(15 downto 0);
   signal B : std_logic_vector(15 downto 0);
   signal C : std_logic_vector(15 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 

 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: decode PORT MAP (
          ins_di => ins_di,
          OP => OP,
          A => A,
          B => B,
          C => C
        );

  
   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	
		ins_di <= x"FFAABBCC" ;


      wait;
   end process;

END;
