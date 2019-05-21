--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   10:05:15 05/13/2019
-- Design Name:   
-- Module Name:   /home/rassat/Bureau/4A/s2/projetsystinfo/proj_syst_info/instr_mem_test.vhd
-- Project Name:  proj_syst_info
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: Instr_Memory
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
 
ENTITY instr_mem_test IS
END instr_mem_test;
 
ARCHITECTURE behavior OF instr_mem_test IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Instr_Memory
    PORT(
         ADR : IN  std_logic_vector(7 downto 0);
         CLK : IN  std_logic;
         S : OUT  std_logic_vector(31 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal ADR : std_logic_vector(7 downto 0) := (others => '0');
   signal CLK : std_logic := '0';

 	--Outputs
   signal S : std_logic_vector(31 downto 0);

   -- Clock period definitions
   constant CLK_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: Instr_Memory PORT MAP (
          ADR => ADR,
          CLK => CLK,
          S => S
        );

   -- Clock process definitions
   CLK_process :process
   begin
		CLK <= '0';
		wait for CLK_period/2;
		CLK <= '1';
		wait for CLK_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	
		
      wait for CLK_period*10;

      -- cf data_mem_test , forcé valeur dans le tableau à l'indice 204 ! sort bien sur S
		ADR <= x"CC" ; 
		wait for 2 ms ; 
      wait;
   end process;

END;
