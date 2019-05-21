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
signal memi : REGS := (0 => x"00000000", 1=> x"01010101", others => (others => '0')); 

begin
	process 
		begin 
			wait until CLK' event and CLK='1' ;
				S <= memi(to_integer(unsigned(ADR))) ; 
		end process ; 


end Behavioral;

