----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:26:01 05/07/2019 
-- Design Name: 
-- Module Name:    ALU - Behavioral 
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
use IEEE.numeric_std.all;
use ieee.std_logic_unsigned.all;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity ALU is
    Port ( A : in  STD_LOGIC_VECTOR (15 downto 0);
           B : in  STD_LOGIC_VECTOR (15 downto 0);
           S : out  STD_LOGIC_VECTOR (15 downto 0);
           OP : in  STD_LOGIC_VECTOR (3 downto 0);
           N : out  STD_LOGIC;
           O : out  STD_LOGIC;
           C : out  STD_LOGIC;
           Z : out  STD_LOGIC);
end ALU;

architecture Behavioral of ALU is
	signal Sadd :   STD_LOGIC_VECTOR (16 downto 0);
	signal Smul :  STD_LOGIC_VECTOR (31 downto 0);
	signal Sless :  STD_LOGIC_VECTOR (15 downto 0);
	--Sdiv : out  STD_LOGIC_VECTOR (16 downto 0);

	
begin
	
	
		-- Faire un bloc pour le choix du signal intermediaire 
	S <= Sadd (15 downto 0) when OP = x"1" else 
		  Sless (15 downto 0) when OP = x"3" else
		  Smul (15 downto 0) when OP = x"2" else
		  x"0000" ; 
		  
		  --Carry (juste pour addition)
	C <= Sadd(16) when OP = x"1" else
		'0';
			
			--Negatif (+/- le bit le plus a gauche, signé ou non signé, le programmeur utilisera ensuite l'information) 
	N <= Sadd(15) when OP = x"1" else    
		  Sless(15) when OP = x"3" else 
		  '0' ;
		  
		  -- Overflow (sur add , sous, et mul : change le bit de signe alors que ne devrait pas )  
	O <= '1' when (OP=x"1" AND A(15)='0' AND B(15)='0' AND Sadd(15)='1') -- positif + positif = negatif 
				  OR (OP=x"1" AND A(15)='1' AND B(15)='1' AND Sadd(15)='0') -- negatif + negatif = positif 
				  OR (OP=x"3" AND A(15)='0' AND B(15)='1' AND Sless(15)='1') --positif - negatif = negatif 
				  OR (OP=x"3" AND A(15)='1' AND B(15)='0' AND Sless(15)='0') 	-- negatif - positif = positif 
				  OR (OP=x"2" AND Smul(31 downto 16) /= x"0000")					-- res mul sur + de 16 bits 
				  else   '0' ;
				  
		  
		  -- Zero (res = 0 ) 
		 Z <= '1' when Sadd = x"0000" or Sless = x"0000" or Smul = x"0000" else 
				'0' ; 
		  
			--Addition 
	-- Pas forcément de when pour la ligne suivante, ne coute pas cher à calculer la valeur après a voir si utilisé
	Sadd <= ('0'&A) + ('0'&B) ;
 
	-- Soustraction  
	Sless <= A - B ;
	
	-- Multiplication ( 2 signaux de 16 bits sort 32 bits !!! attnetion) 
	Smul <= std_logic_vector(unsigned(A) * unsigned(B)) when OP=x"2" ;  -- faire en non signé et cast a la fin std logic 
	
end Behavioral;

