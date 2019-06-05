#include "ti.h"

	//Var globales
int index_ti=0 ; 	//Prochain index dispo ds tab


	//Insérer une instruction dans le tab
void insert3(char *operation, int ri, int rj, int rk){

		strcpy(ti[index_ti].op,operation) ;
		ti[index_ti].a = ri ;
		ti[index_ti].b =rj ;		
		ti[index_ti].c = rk ;
		index_ti ++ ; 
}
void insert2(char *operation, int ri, int rj){


		//Cas 1 : rA <-- ri, rC <-- rj 	(Pour rester conforme avec notre raisonnement en VHDL
		//Pr le JMPC, JMPF, STORE 
		if((strcmp(ti[index_ti].op,"JMPC")==0) || (strcmp(ti[index_ti].op,"JMPF")==0) || (strcmp(ti[index_ti].op,"STORE")==0)) {

			strcpy(ti[index_ti].op,operation) ;
			ti[index_ti].a = ri ;
			ti[index_ti].c =rj ;		
			index_ti ++ ; 
		}
		//Cas 2 : rA <-- ri, rB <-- rj 
		//Pr tt le reste, exp: LOAD,...
		else{
			strcpy(ti[index_ti].op,operation) ;
			ti[index_ti].a = ri ;
			ti[index_ti].b =rj ;		
			index_ti ++ ; 
		}
		show_ti() ; 
}
void insert1(char *operation, int ri){

		strcpy(ti[index_ti].op,operation) ;
		ti[index_ti].a =ri ;
		index_ti ++ ; 
}

	//Affiche la tab de symb
void show_ti(){
	for (int j=0; j<=index_ti+1; j++){	
		printf("| %s | %d | %d | %d |\n",ti[j].op, ti[j].a, ti[j].b, ti[j].c) ; 
	}
}

	//Index de la dernière instruction <==> memoire_instruction.len-1 (Pour le IF)
int  get_last_ti(){  

	return (index_ti-1) ; 
}

int set_ti(int ligne, char *param, int maj){
	
	int res = 1 ; 

	if (param="a"){
		ti[ligne].a=maj ;
		printf("[SET_TI] %d , %d ",ti[ligne].a,maj) ; 
	}
	else if (param="b"){
		ti[ligne].a=maj ;
		printf("[SET_TI]  %d , %d ",ti[ligne].b,maj) ; 
	}
	else if (param="c"){
		ti[ligne].c=maj ;
		printf("[SET_TI] %d , %d ",ti[ligne].c,maj) ; 
	}
	else{
		printf("Error set_ti, case =/= -1") ;
		res = -1 ;
	}
	return res ;
}


//Fonction pour recopier le tableau ds un fichier
void export_tab(){
		printf("EXPORT FILE!\n");
	FILE *f = fopen("compilated.s","w") ; 
	
	if (f == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}
	else { 
		for (int j=0; j<index_ti; j++){	

			if (j==0) fprintf(f,"%s ",ti[j].op) ; else fprintf(f,"\n%s ",ti[j].op)  ;
			
			// 2 cas : si a contient une adresse ou un registre 
			// Si une adresse 

			if ((strcmp(ti[j].op,"JMPC")==0) || (strcmp(ti[j].op,"JMP")==0) || (strcmp(ti[j].op,"JMPF")==0) || (strcmp(ti[j].op,"STORE")==0) || (strcmp(ti[j].op,"PRINT")==0)  ) { 
				/*	Conversion hexa non fonctionnelle : 
				char Res[4] ; 
				memcpy(Res,&ti[j].b,4) ; 							
				fprintf(f,"0x%s ",Res) ; */
				char nameReg[3] ;
				char res[3] = "@" ; 
				sprintf(nameReg,"%d",ti[j].a) ; 
				fprintf(f,"%s ",strcat(res,nameReg)) ; 
				//fprintf(f,"%d ",ti[j].a) ; 	OK sans @
			} 
			

			else { 
				char nameReg[3] ;
				char res[3] = "R" ; 
				sprintf(nameReg,"%d",ti[j].a) ; 
				fprintf(f,"%s ",strcat(res,nameReg)) ; 		
			} 
			//Condition sur B
		if ((strcmp(ti[j].op,"JMP")!=0) && (strcmp(ti[j].op,"PRINT")!=0)) {	//Il y une 2e opérande
			if (strcmp(ti[j].op,"LOAD")==0){	//C'est une adresse
			/*	Conversion hexa non fonctionnelle : 
				char Res[4] ; 
				memcpy(Res,&ti[j].b,4) ; 							
				fprintf(f,"0x%s ",Res) ; */

				//fprintf(f,"%d ",ti[j].b) ; OK sans @

				char nameReg[3] ;
				char res[3] = "@" ; 
				sprintf(nameReg,"%d",ti[j].b) ; 
				fprintf(f,"%s ",strcat(res,nameReg)) ; 

			}
			else if ((strcmp(ti[j].op,"AFC")==0) || (strcmp(ti[j].op,"JMPF")==0) )  {
				fprintf(f,"%d ",ti[j].b) ;
			 } 
			else{
				char nameReg[3] ;
				char res[3] = "R" ; 
				sprintf(nameReg,"%d",ti[j].b) ; 
				fprintf(f,"%s ",strcat(res,nameReg)) ; 
			}
			//fprintf(f,"%d\n",ti[j].b) ;
		}

			//Condition sur C
		if ((strcmp(ti[j].op,"AFC")!=0) && (strcmp(ti[j].op,"LOAD")!=0) && (strcmp(ti[j].op,"COP")!=0) && (strcmp(ti[j].op,"STORE")!=0) && (strcmp(ti[j].op,"JMPC")!=0) && (strcmp(ti[j].op,"JMPF")!=0) && (strcmp(ti[j].op,"JMP")!=0) &&(strcmp(ti[j].op,"PRINT")!=0) ){
			char nameReg[3] ;
				char res[3] = "R" ; 
				sprintf(nameReg,"%d",ti[j].c) ; 
				fprintf(f,"%s ",strcat(res,nameReg)) ; 
		}
		


}

	fclose(f) ; 


}
}


/*
void main(){
	//Tests
	
	insert3("ADD","R1","R2","R3") ;
	insert2("ADD","R1","R2") ;
	show_ti() ; */
 

