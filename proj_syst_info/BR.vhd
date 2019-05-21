----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    09:21:47 05/10/2019 
-- Design Name: 
-- Module Name:    BR - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity BR is
    Port ( aA : in  STD_LOGIC_VECTOR (3 downto 0);
           aB : in  STD_LOGIC_VECTOR (3 downto 0);
           aW : in  STD_LOGIC_VECTOR (3 downto 0);
           W : in  STD_LOGIC;
           DATA : in  STD_LOGIC_VECTOR (15 downto 0);
           RST : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           QA : out  STD_LOGIC_VECTOR (15 downto 0); --Pour les lectures
           QB : out  STD_LOGIC_VECTOR (15 downto 0));
end BR;

architecture Behavioral of BR is
-- array
type REGS is array (0 to 15) of std_logic_vector (15 downto 0);
-- regs : type array
signal breg : REGS ; 

begin	
   --Asynchrone: dès que condition change, le res change
	--1ere condi : Si écriture et lecture sur le même registre
	-- 2eme condi : lecture normale 
	QA <= DATA when (W='1' AND aA=aW) else 
			breg(to_integer(unsigned(aA))) ; 
	QB <= DATA when (W='1' AND aB=aW) else 
			breg(to_integer(unsigned(aB))); 
	

	process 
		begin 
			wait until CLK' event and CLK='1' ;
			-- diff entre if et when ? Comment accéder mem ? 
			--Reset
			if RST = '0' then 
				breg <= (others => (others => '0')) ; 	
			--Ecriture
			elsif W = '1' then 
				breg(to_integer(unsigned(aW))) <= DATA ; 
		
		   end if ;
			
	end process ; 
		
end Behavioral;

