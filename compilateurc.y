
// AFC : Load pour les valeurs directes 
%{
	#include "ts.h" 
	#include "ti.h"
	int yylex(void);
	void yyerror(char*) ;
%}

%token tIF tELSE tWHILE tPLUS tLESS tAFFECT tEQUIV tDIFF tSUP tINF tSUPEQ tINFEQ tMUL tDIV tPARO tPARF tACCO tACCF tPV tVIRG tVOID tRETURN tPRINTF tCONST tINT tSTRING tVAR tNB tS tERROR 

%union{
	int i ;
	char* c ;
}

	// Typer les tokens  
%type <c> tVAR			
%type <i> tNB 
%type <c> tS
%type <i> Exp
%type <i> Value 
%type <i> tIF
%type <i> If
%type <i> tELSE
%type <i> XIF
%type <i> tPARO
%type <i> tWHILE

%left tPLUS tLESS
%left tDIV tMUL

// Priorité du if (tIFX mon prioritaire que tELSE) 
%nonassoc tIFX
%nonassoc tELSE 


%%
start : Fonctions ;

Fonctions : Fonction Fonctions 
			| Fonction  ; 

Fonction : Type tVAR tPARO Args tPARF Body ; /* ici tVar pourrait être tMain pour la 1ere fct : on vire le token main, il faudra vérifie qu'on en a bien qu'un seul plus tard */

Type : tVOID { set_void() ; }
		| tINT { set_int() ; } 
		| tSTRING { set_string() ; }
 
Args : Type tVAR tVIRG Args  
		|Type tVAR  
		| ;
 
Body :  tACCO { inc_prof() ; } Content tACCF {clean_prof() ; } ;  // Fonction Pop des var obsoletes ici   ; 

/* BODY */ 

Content : Decla Content
		 | Afect Content
		 | If Content
		 | While Content
		 | ;

/* Affectations et Déclarations */ 

Afect : tVAR tAFFECT Exp tPV /* { int ivar = get_addr($1) ; 
							  
							  insert2("LOAD",0,$3) ; 		//printf("LOAD 0, %d\n",$3) ;
							  insert2("STORE",ivar,0) ; 	//printf("STORE %d, 0\n", ivar) ;
// probleme possible , inverser ivar et 0
							  remove_tmp () ; //pop, remove exp ;
							
 }*/  ; 
/*{  On recupere l'index de exp , on recupere sa valeur et on la store dans la ts pour tVAR } ;  /* a = b-c ; 
			Attentio, : on ajoute un nouvel élément alors que la var est déjà déclkaré, on ne fait rien car si on est ici la variable a forcément déjà été initialiser : */ 

Decla : Type ListVars tPV ; 

ListVars : Var SuiteListVars 
			| Var ; 

SuiteListVars : tVIRG Var SuiteListVars 
				| tVIRG Var ;

// Dans ce cas rien a été précédemment déclaré : insert !! 
Var : tVAR tAFFECT Exp {remove_tmp() ; 
						insert($1,0,1); } ;  // Trucs a faire en plus pour l'affect??ASM
	  |tVAR {insert($1,0,0); } //pas initialisé


Exp : Exp tMUL Exp { int ad1 = get_addr_fi($1); 
					int ad2 = get_addr_fi($3) ; 
					insert2("LOAD",0,ad1) ; //printf("LOAD 0, %d\n",ad1) ; 
					insert2("LOAD",1,ad2) ; //printf("LOAD 1, %d\n",ad2) ;
					insert3("MUL",0,0,1) ; // printf("MUL 0,0,1") ;
					remove_tmp () ; //pop, remove add2
					insert2("STORE",ad1,0) ; //printf("STORE %d, 0\n", ad1) ;
					$$= ad1 ;
					//remove_tmp () ;
					 } 

	| Exp tDIV Exp  { int ad1 = get_addr_fi($1); 
					int ad2 = get_addr_fi($3) ; 
					insert2("LOAD",0,ad1) ; //printf("LOAD 0, %d\n",ad1) ; 
					insert2("LOAD",1,ad2) ; //printf("LOAD 1, %d\n",ad2) ;
					insert3("DIV",0,0,1) ; // printf("DIV 0,0,1") ;
					remove_tmp () ; //pop, remove add2
					insert2("STORE",ad1,0) ; //printf("STORE %d, 0\n", ad1) ;
					$$= ad1 ;
					//remove_tmp () ; 
					} 



	| Exp tPLUS Exp { int ad1 = get_addr_fi($1); // c'est effectivement from index car Value est un index  (de son tmp)
					int ad2 = get_addr_fi($3) ; 
					insert2("LOAD",0,ad1) ; //printf("LOAD 0, %d\n",ad1) ; 
					insert2("LOAD",1,ad2) ; //printf("LOAD 1, %d\n",ad2) ;
					insert3("ADD",0,0,1) ; // printf("ADD 0,0,1") ;
					remove_tmp () ; //pop, remove add2
					insert2("STORE",ad1,0) ; //printf("STORE %d, 0\n", ad1) ;
					$$= ad1 ; //remove_tmp () ;
						 } 
						// En ASM la vraie ecriture de l'expression, géré ensuite sur value 
	
	| Exp tLESS Exp { int ad1 = get_addr_fi($1); 
					int ad2 = get_addr_fi($3) ; 
					insert2("LOAD",0,ad1) ; //printf("LOAD 0, %d\n",ad1) ; 
					insert2("LOAD",1,ad2) ; //printf("LOAD 1, %d\n",ad2) ;
					insert3("SOU",0,0,1) ; // printf("SOU 0,0,1") ;
					remove_tmp () ; //pop, remove add2
					insert2("STORE",ad1,0) ; //printf("STORE %d, 0\n", ad1) ;
					$$= ad1 ;//remove_tmp () ;
					 } 
                
	| Value	 // Value doit "transmettre l'index de value a exp ??? je pense 					
	| tPARO Exp tPARF { $$ = $2; };               

Value : tVAR {printf("id %s\n",$1);
				int addr = get_addr($1) ; 
				int tmp = insert_tmp() ; 
				insert2("LOAD",0,addr) ; //printf("LOAD 0, %d\n", addr) ; 
				insert2("STORE",get_addr_fi(tmp),0 ) ; //printf("STORE %d, 0\n", get_addr_fi(tmp)) ; 
				$$=tmp-1 ;  } 

		| tNB {printf("id %d\n",$1);
				int tmp = insert_tmp () ; 
				insert2("AFC",0,$1) ; // printf("AFC 0, %d\n", $1) ; 
				insert2("STORE",get_addr_fi(tmp),0 ) ; //printf("STORE %d, 0\n", get_addr_fi(tmp)) ; 
				$$=tmp ; } // Value prend la valeur de l'index de tmp .  
; 


/* IF */
// resolution du conflit shift reduce -> associer le else au if le plus proche!
XIF : { remove_tmp() ; 
		 // -1 est temporaire
		insert2("LOAD",1,get_last_addr());
		insert2("JMPC",-1,1) ;
	    $$ = get_last_ti()  ; } ;

If : tIF tPARO Comparaison tPARF XIF
		Body %prec tIFX 	
			{set_ti($5,"a",get_last_ti()); }

	| tIF tPARO Comparaison tPARF XIF
			Body 
			tELSE 
				{insert2("JMPC",-1,1) ;  // saut a -1 si registre 1 à 0
				set_ti($5,"a",get_last_ti());   //Patch le If (le -1)
				$7 = get_last_ti() ;} 	    //Se repositionne juste av le Else
			Body 
				{set_ti($7,"a",get_last_ti());}	//Patch le Else (le -1)
  ; 



/* WHILE   VERIF LES JUMPS .. ON AVAIT JUMPF suur l176 */

While : tWHILE 
			  {$1=get_last_ti(); }
		tPARO Comparaison tPARF
								{ insert2("LOAD",1,get_last_addr());
								  insert2("JMPF",1,0xFFFF); // jmp false si la 2eme valeur est diff de zéro( faux) , on jump a l'addresse de 1 qui a été load juste avant (patch avec le $3 de set_ti 
								  $3=get_last_ti()  ;} 		
			Body 
				{insert2("JMP",$1,1);
				 set_ti($3,"b",get_last_ti()); }  ; // a ou b a voir

/* Comparaisons */ 

Comparaison : Exp OpComparaison Exp ;

OpComparaison : tEQUIV 
				|tDIFF 
				|tSUP 
				|tINF 
				|tSUPEQ 
				|tINFEQ ;

/* Appel fonctions , apparement pas besoin*/ 

//Call : tVAR tPARO ListArgs tPARF tPV ; //1er jet a voir , list arg construire similaire a listevars)
 Printf : tPRINTF tPARO tVAR tPARF tPV ; 

%% 

int main (void) { 
#ifdef YYDEBUG 
	yydebug=1 ; 
#endif 
	yyparse() ; 
	printf("FIN !!!!") ;
	export_tab() ;
} 

