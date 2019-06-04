----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:25:30 05/13/2019 
-- Design Name: 
-- Module Name:    MicroProc - Behavioral 
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

entity MicroProc is
	generic (N:natural := 8) ;
	Port ( 
		CLK : in std_logic ; 
		RST : in std_logic ; 
		EN  : in std_logic)  ;
		--IP  : in std_logic_vector (N-1 downto 0)) ; 
end MicroProc;

architecture Behavioral of MicroProc is

	-- -- -- 	C O M P O N E N T S 	-- -- --
	
	
	--IP  -- on a enlevé LOAD/Din (pas besoin d'ecrire un enetree sur la sortie) et SENS (pas besoin de décrementer) 
	
	component IP 
		Port (CLK : in  STD_LOGIC;
           RST : in  STD_LOGIC;
           EN : in  STD_LOGIC;
           Dout : out  STD_LOGIC_VECTOR (7 downto 0));
	end component ; 

	--Mémoire d'instructions

	component Instr_Memory 
			 Port ( ADR : in  STD_LOGIC_VECTOR (7 downto 0);
					  CLK : in  STD_LOGIC;
					  S : out  STD_LOGIC_VECTOR (31 downto 0));
	end component;
	
	-- Decode
	component decode     Port ( ins_di : in  STD_LOGIC_VECTOR (31 downto 0);
           OP : out  STD_LOGIC_VECTOR (7 downto 0);
           A : out  STD_LOGIC_VECTOR (15 downto 0);
           B : out  STD_LOGIC_VECTOR (15 downto 0);
           C : out  STD_LOGIC_VECTOR (15 downto 0));
	end component;


	--Pipeline
	component Pipeline 
		 generic (N:natural;  nop:natural) ; 	
		 Port ( OPi : in  STD_LOGIC_VECTOR (nop-1 downto 0);
				  Ai : in  STD_LOGIC_VECTOR (N-1 downto 0);
				  Bi : in  STD_LOGIC_VECTOR (N-1 downto 0);
				  Ci : in  STD_LOGIC_VECTOR (N-1 downto 0);
				  CLK : in  STD_LOGIC;
				  OPo : out  STD_LOGIC_VECTOR (nop-1 downto 0);
				  Ao : out  STD_LOGIC_VECTOR (N-1 downto 0);
				  Bo : out  STD_LOGIC_VECTOR (N-1 downto 0);
				  Co : out  STD_LOGIC_VECTOR (N-1 downto 0));
	end component;
	
		--BR
	component BR 
    Port ( aA : in  STD_LOGIC_VECTOR (3 downto 0);
           aB : in  STD_LOGIC_VECTOR (3 downto 0);
           aW : in  STD_LOGIC_VECTOR (3 downto 0);
           W : in  STD_LOGIC;
           DATA : in  STD_LOGIC_VECTOR (15 downto 0);
           RST : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           QA : out  STD_LOGIC_VECTOR (15 downto 0); --Pour les lectures
           QB : out  STD_LOGIC_VECTOR (15 downto 0));
	end component;
	

	--ALU (LI/DI)
	component ALU 
			Port ( A : in  STD_LOGIC_VECTOR (15 downto 0);
					 B : in  STD_LOGIC_VECTOR (15 downto 0);
					 S : out  STD_LOGIC_VECTOR (15 downto 0);
					 OP : in  STD_LOGIC_VECTOR (3 downto 0);
					 N : out  STD_LOGIC;
					 O : out  STD_LOGIC;
					 C : out  STD_LOGIC;
					 Z : out  STD_LOGIC);
	end component;
	

	-- Mémoire de données
	component Data_Memory 
    Port ( ADR : in  STD_LOGIC_VECTOR (7 downto 0);
           E : in  STD_LOGIC_VECTOR (15 downto 0);
           RW : in  STD_LOGIC;
           RST : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           S : out  STD_LOGIC_VECTOR (15 downto 0));
	end component ;
		
	--MUX
	component mux 
	 generic (N : natural);
    Port ( i0 : in  STD_LOGIC_VECTOR (N-1 downto 0);
           i1 : in  STD_LOGIC_VECTOR (N-1 downto 0);
           sel : in  STD_LOGIC;
           S : out  STD_LOGIC_VECTOR (N-1 downto 0));
	end component;
	
	

		-- -- -- 	S I G N A U X 	 -- -- --

  -- Index Instruction Memory signal (CPT)
  signal ip_out : std_logic_vector (7 downto 0) ;
  
  -- Instruction Memory 
  signal instr_mem_out : std_logic_vector (31 downto 0) ; 
  
  --Decode
	signal dec_op_out : std_logic_vector (7 downto 0) ; 
	signal dec_a_out : std_logic_vector (15 downto 0) ; 
	signal dec_b_out : std_logic_vector (15 downto 0) ; 
	signal dec_c_out : std_logic_vector (15 downto 0) ; 
	
  
  -- Pipeline LI/DI
  signal piplidi_op_out : std_logic_vector (7 downto 0) ; 
  signal piplidi_a_out : std_logic_vector (15 downto 0) ; 
  signal piplidi_b_out : std_logic_vector (15 downto 0) ; 
  signal piplidi_c_out : std_logic_vector (15 downto 0) ; 
  
  -- Banc registre : 
  signal br_qa_out : std_logic_vector (15 downto 0) ; 
  signal br_qb_out : std_logic_vector (15 downto 0) ; 
  signal wchoice : std_logic ; 

	--mux1 
	signal mux1_out : std_logic_vector (15 downto 0) ; 
	signal choice1 : std_logic ; 
	
	  -- Pipeline DI/EX
  signal pipdiex_op_out : std_logic_vector (7 downto 0) ; 
  signal pipdiex_a_out : std_logic_vector (15 downto 0) ; 
  signal pipdiex_b_out : std_logic_vector (15 downto 0) ; 
  signal pipdiex_c_out : std_logic_vector (15 downto 0) ;
  
  -- ALU 
  signal alu_out : std_logic_vector (15 downto 0) ;
  signal ctrl_alu : std_logic_vector (3 downto 0 ) ; 
  
  --mux2 :
	signal mux2_out : std_logic_vector (15 downto 0) ; 
	signal choice2 : std_logic ; 
	
	--Pipeline ex/mem 
  signal pipexmem_op_out : std_logic_vector (7 downto 0) ; 
  signal pipexmem_a_out : std_logic_vector (15 downto 0) ; 
  signal pipexmem_b_out : std_logic_vector (15 downto 0) ; 
  
  --mux4
  signal choice5 : std_logic ;
  signal mux4_out : std_logic_vector(15 downto 0) ;

  -- Data Memory 
  signal data_mem_out : std_logic_vector (15 downto 0) ;
  signal choice3 : std_logic ; 
  
  --mux3
  signal choice4 : std_logic ;
  signal mux3_out : std_logic_vector(15 downto 0) ;
  	--Pipeline mem/re 
  signal pipmemre_op_out : std_logic_vector (7 downto 0) ; 
  signal pipmemre_a_out : std_logic_vector (15 downto 0) ; 
  signal pipmemre_b_out : std_logic_vector (15 downto 0) ; 

  
  --Constant signal :
  constant cst_in : std_logic_vector (15 downto 0) := (others => '0') ; 
  
  -- Test signal : 
  signal test_signal : std_logic_vector (31 downto 0) ; 
	  
	  

begin
 
  -- instanciation via port map de chaque entite !
  
  -- IP (Compteur 8 bits pr parcourir la mém de données)
	inst_point : IP port map ( CLK => CLK , RST => RST , EN => EN , Dout => ip_out)  ; 
  
  -- INSTRUCTION MEMORY : Adresse d'entree ?? a donner et affecter dans notre memoire d'instruction
  -- sera donner ensuite par l'instruction pointer : un compteur 8 bits  comme td 
  -- sinon nous, sauter cette étape et directement entrée les 32 bits a tester voulu sur le decodeur
  
   instr_mem : Instr_Memory port map (ADR => ip_out, CLK => CLK, S => instr_mem_out) ; 
  
  -- decodeur : Pour ceux qui concatene des 8 bits sur 16 a voir dans le composant 
  
	decod : decode port map (ins_di => instr_mem_out, OP => dec_op_out, A => dec_a_out, B => dec_b_out, C => dec_c_out) ;  
  
  -- PIPELINE LI/DI : 
	pip_li_di : Pipeline generic map ( N => 16, nop => 8) port map (OPi => dec_op_out , Ai => dec_a_out, Bi => dec_b_out, Ci => dec_c_out, CLK => CLK, 
																			OPo => piplidi_op_out, Ao => piplidi_a_out, Bo => piplidi_b_out, Co => piplidi_c_out) ;
  
  -- BR : 
	wchoice <= '0' when (pipmemre_op_out = x"08" OR pipmemre_op_out = x"0E" OR pipmemre_op_out = x"0F") else --Store et Jumps, il n'y a que eux qui ne font pas d'ecriture
				 '1' ; 				 
				 
				  
	banc_registre : BR port map ( aA => piplidi_b_out(3 downto 0), aB => piplidi_c_out(3 downto 0) , 
											aW =>pipmemre_a_out (3 downto 0), W => wchoice , DATA =>pipmemre_b_out, RST => RST, 
											CLK =>CLK , QA => br_qa_out , QB => br_qb_out) ;  --br_qb_out vaut rien // rst_br est a 1 (inactif) 
  
  -- mux1 : on choisit le signal b 'pur' si AFC ou LOAD. Pour STore, B va chercher le contenu du registre.
	choice1 <= '0' when (piplidi_op_out = x"06" or piplidi_op_out = x"07") else
				'1' ; 
  
	mux1 : mux generic map (N => 16) port map (i0 => piplidi_b_out, i1 => br_qa_out  , sel => choice1 , S => mux1_out ) ; 
	
	--Pipeline DI/EX :
	pip_di_ex : Pipeline generic map (N => 16, nop => 8) port map(OPi => piplidi_op_out, Ai => piplidi_a_out , Bi => mux1_out , Ci => br_qb_out, CLK => CLK, 
												 OPo => pipdiex_op_out, Ao => pipdiex_a_out , Bo => pipdiex_b_out , Co => pipdiex_c_out ) ;
  
  -- ALU (Flag plus tard ) 
			
	alu1 : ALU port map ( A => pipdiex_b_out, B => pipdiex_c_out, OP => pipdiex_op_out(3 downto 0) ,  S => alu_out ) ; 
  
  -- mux2 // on choisit la sortie de l'alu si add, mul ou sous 
	choice2 <= '1' when (pipdiex_op_out=x"01" or pipdiex_op_out=x"02" or pipdiex_op_out=x"03") else 
				 '0'	; 
	mux2 : mux generic map (N => 16) port map (i0 => pipdiex_b_out, i1 => alu_out, sel => choice2, S => mux2_out ) ; 
  
  -- Pipeline ex/mem ( Faire un autre pipeline avec une sortie en moins ?? port map doit tout affecté ?? ) 
	pip_ex_mem : Pipeline generic map (N => 16, nop => 8) port map (OPi => pipdiex_op_out, Ai => pipdiex_a_out , Bi => mux2_out , Ci => cst_in , CLK => CLK, 
										    OPo => pipexmem_op_out, Ao => pipexmem_a_out , Bo => pipexmem_b_out , Co => open) ;
	
	-- mux4	 //STORE ou pas
	choice5 <= '1' when (pipexmem_op_out = x"07") else	-- Si 1: Prends  B pour le LOAD
				  '0' ;												-- Si 0: Prends  A pour le STORE
	mux4 : mux generic map (N => 16) port map (i0 => pipexmem_a_out, i1 => pipexmem_b_out, sel =>choice5 , S => mux4_out ) ;	
	
	-- Data Memory 
				-- RW lecture a 1 
	choice3 <= '0' when pipexmem_op_out=x"08" else --store
					'1' ;  --load et autres
	data_mem : Data_Memory port map (ADR => mux4_out (7 downto 0), E => pipexmem_b_out , RW => choice3 , RST => RST, CLK => CLK, S => data_mem_out )  ; 
	
	--mux3
	choice4 <= '1' when pipexmem_op_out=x"07" else --load
					'0' ; 
	mux3 : mux generic map (N => 16) port map ( i0 => pipexmem_b_out, i1 => data_mem_out , sel => choice4, S => mux3_out  ) ; 
	 
	-- Pipeline mem/re 
	pip_mem_re : Pipeline generic map (N => 16, nop => 8) port map (OPi => pipexmem_op_out, Ai => pipexmem_a_out , Bi => mux3_out , Ci => cst_in , CLK => CLK, 
										    OPo => pipmemre_op_out, Ao => pipmemre_a_out , Bo => pipmemre_b_out , Co => open) ;
											 
		
		--- NORMALEMENT CHEMIN OK , ON PEUT LES FAIRE LES TESTS !											
		

end Behavioral;

