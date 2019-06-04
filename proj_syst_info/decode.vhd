----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    08:37:01 05/14/2019 
-- Design Name: 
-- Module Name:    decode - Behavioral 
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
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity decode is
    Port ( ins_di : in  STD_LOGIC_VECTOR (31 downto 0);
           OP : out  STD_LOGIC_VECTOR (7 downto 0);
           A : out  STD_LOGIC_VECTOR (15 downto 0);
           B : out  STD_LOGIC_VECTOR (15 downto 0);
           C : out  STD_LOGIC_VECTOR (15 downto 0));
end decode;

architecture Behavioral of decode is

begin

	OP <= ins_di (31 downto 24) ;
	
	-- FAIRE VERIF NOS CAS 
	
	A  <= ins_di(23 downto 8) when ins_di (31 downto 24) = x"08" else -- STORE: A <-- A&B	
			x"00"&(ins_di (23 downto 16)) ;										-- LOAD (et autres): A <-- 0&A
			--8 bits dans le ins_di, on le complète donc par des 0 
	B  <= ins_di(15 downto 0) when (ins_di (31 downto 24) = x"06" or ins_di (31 downto 24)= x"07") else	-- LOAD : B <-- B&C
			x"00"&(ins_di(7 downto 0)) when ins_di (31 downto 24) = x"08" else 	 -- STORE: B <-- 0&C
			x"00"&(ins_di (15 downto 8)) ;													 
			
	C  <= (others => '0') when (ins_di (31 downto 24) = x"05" or ins_di (31 downto 24)=x"06" or ins_di (31 downto 24)=x"07" or ins_di (31 downto 24)=x"08") else
			x"00"&(ins_di (7 downto 0)) ;				
			-- STORE et LOAD: C <-- 0

end Behavioral;

