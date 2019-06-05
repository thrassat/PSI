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

Fonction : Type tVAR tPARO Args tPARF Body ; 

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
		 | Printf Content
		 | ;

/* Affectations et Déclarations */ 
//deja declaré
Afect : tVAR tAFFECT tNB tPV { insert2("AFC",0,$3); // printf("AFC 0, %d\n", $1) ; 
								insert2("STORE",get_addr($1),0) ;} ; 
		|tVAR tAFFECT Exp tPV; /* OLD VERSION { int ivar = get_addr($1) ; 
							  
							  insert2("LOAD",0,$3) ; 		//printf("LOAD 0, %d\n",$3) ;
							  insert2("STORE",ivar,0) ; 	//printf("STORE %d, 0\n", ivar) ;

							  remove_tmp () ; //pop, remove exp ;
							
 }*/ 
/*{  On recupere l'index de exp , on recupere sa valeur et on la store dans la ts pour tVAR } ; 
 /* a = b-c ; 
			Attentio, : on ajoute un nouvel élément alors que la var est déjà déclkaré,
 on ne fait rien car si on est ici la variable a forcément déjà été initialiser : */ 

Decla : Type ListVars tPV ; 

ListVars : Var SuiteListVars 
			| Var ; 

SuiteListVars : tVIRG Var SuiteListVars 
				| tVIRG Var ;

// Dans ce cas rien a été précédemment déclaré : insert !! 
Var : tVAR tAFFECT Exp {remove_tmp() ; 
						insert($1,0,1); } ;  
	  |tVAR {insert($1,0,0); } //pas initialisé


Exp : Exp tMUL Exp { int ad1 = $1; 
					int ad2 = $3 ; 
					insert2("LOAD",0,ad1) ; //printf("LOAD 0, %d\n",ad1) ; 
					insert2("LOAD",1,ad2) ; //printf("LOAD 1, %d\n",ad2) ;
					insert3("MUL",0,0,1) ; // printf("MUL 0,0,1") ;
					remove_tmp () ; //pop, remove add2
					insert2("STORE",ad1,0) ; //printf("STORE %d, 0\n", ad1) ;
					$$= ad1 ;
					 } 

	| Exp tDIV Exp  { int ad1 = $1; 
					int ad2 = $3 ; 
					insert2("LOAD",0,ad1) ; //printf("LOAD 0, %d\n",ad1) ; 
					insert2("LOAD",1,ad2) ; //printf("LOAD 1, %d\n",ad2) ;
					insert3("DIV",0,0,1) ; // printf("DIV 0,0,1") ;
					remove_tmp () ; //pop, remove add2
					insert2("STORE",ad1,0) ; //printf("STORE %d, 0\n", ad1) ;
					$$= ad1 ;
					} 



	| Exp tPLUS Exp { int ad1 = $1; 
					int ad2 = $3 ; 
					insert2("LOAD",0,ad1) ; //printf("LOAD 0, %d\n",ad1) ; 
					insert2("LOAD",1,ad2) ; //printf("LOAD 1, %d\n",ad2) ;
					insert3("ADD",0,0,1) ; // printf("ADD 0,0,1") ;
					remove_tmp () ; //pop, remove add2
					insert2("STORE",ad1,0) ; //printf("STORE %d, 0\n", ad1) ;
					$$= ad1 ; 
						 } 
						
	
	| Exp tLESS Exp { int ad1 = $1; 
					int ad2 = $3 ; 
					insert2("LOAD",0,ad1) ; //printf("LOAD 0, %d\n",ad1) ; 
					insert2("LOAD",1,ad2) ; //printf("LOAD 1, %d\n",ad2) ;
					insert3("SOU",0,0,1) ; // printf("SOU 0,0,1") ;
					remove_tmp () ; //pop, remove add2
					insert2("STORE",ad1,0) ; //printf("STORE %d, 0\n", ad1) ;
					$$= ad1 ;
					 } 

	| Exp tEQUIV Exp { int ad1 = $1; 
					int ad2 = $3 ; 
					insert2("LOAD",1,ad1) ; //printf("LOAD 0, %d\n",ad1) ; 
					insert2("LOAD",2,ad2) ; //printf("LOAD 1, %d\n",ad2) ;
					insert3("EQU",0,1,2) ; // printf("SOU 0,0,1") ;
					remove_tmp () ; //pop, remove add2
					int tmp = insert_tmp() ; 
					insert2("STORE",get_addr_fi(tmp),0) ; //printf("STORE %d, 0\n", ad1) ;
					$$= get_addr_fi(tmp) ;//remove_tmp () ;
					}

	| Exp tINF Exp { int ad1 = $1; 
				int ad2 = $3 ; 
				insert2("LOAD",1,ad1) ; //printf("LOAD 0, %d\n",ad1) ; 
				insert2("LOAD",2,ad2) ; //printf("LOAD 1, %d\n",ad2) ;
				insert3("INF",0,1,2) ; // printf("SOU 0,0,1") ;
				remove_tmp () ; //pop, remove add2
				int tmp = insert_tmp() ; 
				insert2("STORE",get_addr_fi(tmp),0) ; //printf("STORE %d, 0\n", ad1) ;
				$$= get_addr_fi(tmp) ;//remove_tmp () ;
				} 

	| Exp tINFEQ Exp { int ad1 = $1; 
				int ad2 = $3 ; 
				insert2("LOAD",1,ad1) ; //printf("LOAD 0, %d\n",ad1) ; 
				insert2("LOAD",2,ad2) ; //printf("LOAD 1, %d\n",ad2) ;
				insert3("INFE",0,1,2) ; // printf("SOU 0,0,1") ;
				remove_tmp () ; //pop, remove add2
				int tmp = insert_tmp() ; 
				insert2("STORE",get_addr_fi(tmp),0) ; //printf("STORE %d, 0\n", ad1) ;
				$$= get_addr_fi(tmp) ;//remove_tmp () ;
				} 

	
	| Exp tSUP Exp { int ad1 = $1; 
				int ad2 = $3 ; 
				insert2("LOAD",1,ad1) ; //printf("LOAD 0, %d\n",ad1) ; 
				insert2("LOAD",2,ad2) ; //printf("LOAD 1, %d\n",ad2) ;
				insert3("SUP",0,1,2) ; // printf("SOU 0,0,1") ;
				remove_tmp () ; //pop, remove add2
				int tmp = insert_tmp() ; 
				insert2("STORE",get_addr_fi(tmp),0) ; //printf("STORE %d, 0\n", ad1) ;
				$$= get_addr_fi(tmp) ;//remove_tmp () ;
				} 

	| Exp tSUPEQ Exp { int ad1 = $1; 
				int ad2 = $3 ; 
				insert2("LOAD",1,ad1) ; //printf("LOAD 0, %d\n",ad1) ; 
				insert2("LOAD",2,ad2) ; //printf("LOAD 1, %d\n",ad2) ;
				insert3("SUPE",0,1,2) ; // printf("SOU 0,0,1") ;
				remove_tmp () ; //pop, remove add2
				int tmp = insert_tmp() ; 
				insert2("STORE",get_addr_fi(tmp),0) ; //printf("STORE %d, 0\n", ad1) ;
				$$= get_addr_fi(tmp) ;//remove_tmp () ;
				}     

	| Value	{ $$ = $1;}; // Value remonte l'adresse du tVar ou du tmp du tNB					
	| tPARO Exp tPARF { $$ = $2; };               

Value : tVAR {printf("id %s\n",$1);
				int addr = get_addr($1) ; 
				/*OLD VERSION 	int tmp = insert_tmp() ; 
				insert2("LOAD",0,addr) ; //printf("LOAD 0, %d\n", addr) ; 
				insert2("STORE",get_addr_fi(tmp),0 ) ; //printf("STORE %d, 0\n", get_addr_fi(tmp)) ; */
				$$=addr ;  } 

		| tNB {printf("id %d\n",$1);
				int tmp = insert_tmp () ; 
				insert2("AFC",0,$1) ; // printf("AFC 0, %d\n", $1) ; 
				insert2("STORE",get_addr_fi(tmp),0 ) ; //printf("STORE %d, 0\n", get_addr_fi(tmp)) ; 
			    int addr= get_addr_fi(tmp);
				$$=addr ; } // Value prend la valeur de l'adresse du tmp .  
; 


/* IF */
// resolution du conflit shift reduce -> associer le else au if le plus proche!
XIF : { //remove_tmp() ; 
		 // -1 est temporaire
		insert2("LOAD",1,get_last_addr());
		insert2("JMPC",-1,1) ;
	    $$ = get_last_ti()  ; } ;

If : tIF tPARO Exp tPARF XIF
		Body %prec tIFX 	
			{set_ti($5,"a",get_last_ti()+1); }

	| tIF tPARO Exp tPARF XIF
			Body 
			tELSE 
				{insert1("JMP",-1) ;  // saut a -1 si registre 1 à 0
				set_ti($5,"a",get_last_ti()+1);   //Patch le If (le -1)
				$7 = get_last_ti() ;} 	    //Se repositionne juste av le Else
			Body 
				{set_ti($7,"a",get_last_ti()+1);}	//Patch le Else (le -1)
 ; 



/* WHILE   */

While : tWHILE 
			  {$1=get_last_ti()+1; }
		tPARO Exp tPARF
								{ insert2("LOAD",1,get_last_addr());
								  insert2("JMPC",-1,1);  
								  $3=get_last_ti() ;} 		// Nous avons eu du mal a retrouver quel fonctionnement doit avoir le JMPF conseillé ... Il nous a posé longtemps probleme pour le while, nous avons changer d'options dans les derniers moments
			Body 
				{insert1("JMP",$1);
				 set_ti($3,"a",get_last_ti()+1); }  ; 

/* Comparaisons */ 
/*
Comparaison :Exp OpComparaison Exp ; //La modification du tVar dans exp ne permet pas de recuperere le bon résultat directement dans 
/*OpComparaison : tEQUIV 
				|tDIFF 
				|tSUP 
				|tINF 
				|tSUPEQ 
				|tINFEQ ; */

/* Appel fonctions , apparement pas besoin*/ 

//Call : tVAR tPARO ListArgs tPARF tPV ; //1er jet a voir , list arg construire similaire a listevars)
// Assembleur a générer : PRINT R0 et stocker la combinaison dans R0 avant d'afficher si plus qu'un tVAR, si juste tVAR PRINT @tVAR et print allé chercher cette valeur dans les données dans l'interpreteur et l'afficher 
Printf : tPRINTF tPARO tVAR tPARF tPV  {insert1("PRINT",get_addr($3)); } ;

%% 

int main (void) { 
#ifdef YYDEBUG 
	yydebug=1 ; 
#endif 
	yyparse() ; 
	printf("FIN !!!!") ;
	export_tab() ;
} 

