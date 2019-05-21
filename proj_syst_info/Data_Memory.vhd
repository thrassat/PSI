----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:12:24 05/10/2019 
-- Design Name: 
-- Module Name:    Data_Memory - Behavioral 
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

entity Data_Memory is
    Port ( ADR : in  STD_LOGIC_VECTOR (7 downto 0);
           E : in  STD_LOGIC_VECTOR (15 downto 0);
           RW : in  STD_LOGIC;
           RST : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           S : out  STD_LOGIC_VECTOR (15 downto 0));
end Data_Memory;

architecture Behavioral of Data_Memory is

--memd ? 
-- array
type REGS is array (0 to 255) of std_logic_vector (15 downto 0);
-- regs : type array
signal memd : REGS ; 


begin

	process 
		begin 
			wait until CLK' event and CLK='1' ;
			
				 -- TAILLE de la mémoire de donnée ??? ARRAY a déclarer ??? 
				 
				if RST = '0' then 
						memd <= (others => (others => '0'))  ;--ini mem a 0 ;
				
				elsif RW = '0' then 
				--Ecriture 
					memd(to_integer(unsigned(ADR))) <= E ; 
				
				elsif RW = '1' then 
					--Lecture 
					S <= memd(to_integer(unsigned(ADR))) ; 
				
				end if ; 
				
				
				
			
		end process ; 	

end Behavioral;

