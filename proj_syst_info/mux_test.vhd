--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   10:52:29 05/13/2019
-- Design Name:   
-- Module Name:   /home/rassat/Bureau/4A/s2/projetsystinfo/proj_syst_info/mux_test.vhd
-- Project Name:  proj_syst_info
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: mux
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
 
ENTITY mux_test IS
END mux_test;
 
ARCHITECTURE behavior OF mux_test IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT mux 
	 generic (N:natural := 16) ; 
    Port ( i0 : in  STD_LOGIC_VECTOR (N-1 downto 0);
           i1 : in  STD_LOGIC_VECTOR (N-1 downto 0);
           sel : in  STD_LOGIC ; 
           S : out  STD_LOGIC_VECTOR (N-1 downto 0));
    END COMPONENT;
    

   --Inputs
   signal i0 : std_logic_vector(7 downto 0) := (others => '0');
   signal i1 : std_logic_vector(7 downto 0) := (others => '0');
   signal sel : std_logic := '0';

 	--Outputs
   signal S : std_logic_vector(7 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 

 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: mux generic map (N => 8) PORT MAP (
          i0 => i0,
          i1 => i1,
          sel => sel,
          S => S
        );

 
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

  
      -- insert stimulus here 

      wait;
   end process;

END;
