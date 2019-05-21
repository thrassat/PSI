--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   11:03:29 05/10/2019
-- Design Name:   
-- Module Name:   /home/rassat/Bureau/4A/s2/projetsystinfo/proj_syst_info/br_test.vhd
-- Project Name:  proj_syst_info
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: BR
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
 
ENTITY br_test IS
END br_test;
 
ARCHITECTURE behavior OF br_test IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT BR
    PORT(
         aA : IN  std_logic_vector(3 downto 0);
         aB : IN  std_logic_vector(3 downto 0);
         aW : IN  std_logic_vector(3 downto 0);
         W : IN  std_logic;
         DATA : IN  std_logic_vector(15 downto 0);
         RST : IN  std_logic;
         CLK : IN  std_logic;
         QA : OUT  std_logic_vector(15 downto 0);
         QB : OUT  std_logic_vector(15 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal aA : std_logic_vector(3 downto 0) := (others => '0');
   signal aB : std_logic_vector(3 downto 0) := (others => '0');
   signal aW : std_logic_vector(3 downto 0) := (others => '0');
   signal W : std_logic := '0';
   signal DATA : std_logic_vector(15 downto 0) := (others => '0');
   signal RST : std_logic := '0';
   signal CLK : std_logic := '0';

 	--Outputs
   signal QA : std_logic_vector(15 downto 0);
   signal QB : std_logic_vector(15 downto 0);

   -- Clock period definitions
   constant CLK_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: BR PORT MAP (
          aA => aA,
          aB => aB,
          aW => aW,
          W => W,
          DATA => DATA,
          RST => RST,
          CLK => CLK,
          QA => QA,
          QB => QB
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
	   RST <= '1' ; 
      wait for CLK_period*10;
		
		-- write test 
		DATA <= x"BBBB" ; 
		W <= '1' ; 
		aW <= x"C" ; 
		
      wait for 2 ms ; 
		
		DATA <= x"AAAA" ; 
		W <= '1' ; 
		aW <= "0010" ; 
		
		wait for 2 ms ; 
		
		-- read test 
		W <= '0' ; 
		aA <= x"2" ; 
		aB <= x"C" ; 
		
		wait for 2 ms ;
		
		aA <= x"7" ; 
		wait for 2 ms ; 
		
      wait;
   end process;

END;
