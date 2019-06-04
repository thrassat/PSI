----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:31:34 05/10/2019 
-- Design Name: 
-- Module Name:    Instr_Memory - Behavioral 
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

entity Instr_Memory is
    Port ( ADR : in  STD_LOGIC_VECTOR (7 downto 0);
           CLK : in  STD_LOGIC;
           S : out  STD_LOGIC_VECTOR (31 downto 0));
end Instr_Memory;

architecture Behavioral of Instr_Memory is

-- decla memoire instructions ? memi-- array
type REGS is array (0 to 255) of std_logic_vector (31 downto 0);

-- regs : type array
--signal memi : REGS := (0 => x"00000000", 1=> x"01010101", others => (others => '0')); 
signal memi : REGS := (0 => x"06000008", 	-- AFC R0 8
							  
							  1=> x"0604000E",	-- AFC R4 14
							  2=> x"0607000F",	-- AFC R7 15 
							  3=> x"060B0004",	-- AFC R11 4	
							  4=> x"01010004", 	-- ADD R1 R0 R4 (x16 dans r1 : 22 ) 
							  5=> x"08000807", 	-- STORE  @8 R7 // Ok on a  OF(15) à l'"adresse 8 de la memoire des données 
							  6=> x"020A0B01", 	-- MUL R10 R11 R1  ( 22 * 4 = 88 , 58 en hexa dans r10 )
							  7=> x"0302000B",	-- SUB R2 R0 R11 (8 -4 = 4 a mettre dans r2 )
							  8=> x"05030200", 	-- COP R3 R2 (r3 prend la valeur de 4)
							  9=> x"07050008" ,	-- LOAD R5 @8 // Ok on a bien 0F dans R5 
							  10=> x"0800240A", 	-- STORE  @36 R10
							  
							  
											--- RESULTATS ATTENDUS --- 
							  -- REGISTRES 					-- DATA MEMORY
							  -- R0 : x0008				@8 : x000F
							  -- R1 : x0016 				@36 : x0058
							  -- R2 : x0004
							  -- R3 : x0004 
							  -- R4 : x000E
							  -- R7 : x000F 
							  -- R8 : x000F  
							  -- R10 : x0058 
							  -- R11 : x0004 
							  others => (others => '0')); 

begin
	process 
		begin 
			wait until CLK' event and CLK='1' ;
				S <= memi(to_integer(unsigned(ADR))) ; 
		end process ; 


end Behavioral;

