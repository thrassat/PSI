#include "ts.h"

	//Var globales

int size=0 ;
int index_ts=0 ; 	//Prochain index dispo ds tab
int addr_m=0;	//Prochaine addr memoire disp
char *t ; // le type 
int prof = 0 ; 


	//Affiche la tab de symb
void show_ts(){
	for (int j=0; j<index_ts; j++){	
		printf("| %s | %s | %i | %i | %d | %d |\n",ts[j].type, ts[j].name, ts[j].cste, ts[j].init, ts	[j].deep, ts[j].addr) ; 
		printf(" ") ; 
	}
}


	//Savoir si un elm existe + get addr
int get_addr (char *elm){ // addr de la var ou -1 si non  présente 
	
	int trouve = 0 ;
	int i = 0 ; 
	int res = -5 ; //si non trouvé
	while (trouve==0 && i<index_ts) {  // Voir eventuellement pour allé que jusqua index si bien toujours le prochaine case dispo ds ts 
		printf("[Get_addr]Comparaison de tVAR %s et l'elm %s\n",elm,ts[i].name) ; 
		if (strcmp(ts[i].name,elm) == 0) {  // elles sont egales 
			res = ts[i].addr ; 		        // addr trouvé
			trouve=1 ; 
		}  
		else { 
			i++ ; 
		} 

	}   
	return res ; 
}

	//Get address from index
int get_addr_fi(int i){

	printf ( " INDEX tvar %s d'index  %d %d \n\n" , ts[i].name, i,index_ts ) ; 
	int res = -9 ;
	if (i < index_ts){
		res = ts[i].addr ;
	}
	return res ;

}


	//Savoir si un elm existe + get index
int get_index (char *elm){ // index de la var ou -1 si non  présente 
	
	int trouve = 0 ;
	int i = 0 ; 
	int res = -8 ; //si non trouvé
	while (trouve==0 && i<index_ts) {  
		if (strcmp(ts[i].name,elm) == 0) {  // elles sont egales 
			res = i ; 		        // addr trouvé
			trouve=1 ; 
		}  
		else { 
			i++ ; 
		} 

	}   
	return res ; 
}


	//Insérer 1 elm dans le tab
int insert (char *nom, int cons, int init2){

	int res = -7 ;

	//Show ts before
	printf("[Function : Insert, show the ts before] \n") ;	
	show_ts() ;
 
	//Elm non existant donc on peut l'insérer
	if (get_addr(nom) == -5){


		strcpy(ts[index_ts].type,t) ;
		strcpy(ts[index_ts].name, nom);
		ts[index_ts].cste = cons;
		ts[index_ts].init = init2;
		ts[index_ts].deep = prof ;

		ts[index_ts].addr = addr_m ; //Prend la dernière addr disp
		printf("[Insert: Insersion of %s succed]\n",nom) ;

		if (strcmp(t,"int")==0) { 
			addr_m +=2 ; 
		} 
		else if (strcmp(t,"string")==0) {	// 
			//strlen(str2)	: On ne connait pas la taille de la chaine de char		
			addr_m +=4 ; 	
		}
		else {
			printf ("[Unknown type]") ;
			addr_m +=2 ; 	
		}
		index_ts ++ ; 
		res=0 ;	
	}

	else  printf("[Insert: %s already exists]\n",nom) ; //On ne pt pas insérer 
	//Show after	
	show_ts () ; 
	return res ;

}

	//Insérer 1 var tmp dans le tab
int insert_tmp (){

	//Show ts before
	printf("[Function : Insert_tmp, show the ts before] \n") ;	
	show_ts() ;

	strcpy(ts[index_ts].type,t) ;
	strcpy(ts[index_ts].name, "tmp");
	ts[index_ts].deep = prof ;
	ts[index_ts].addr = addr_m ; //Prend la dernière addr disp
	printf("[Insert_tmp: Insersion of tmp variable succed]\n") ;

	
	if (strcmp(t,"int")==0) { 
		addr_m +=2 ; 
	} 
	else if (strcmp(t,"string")==0) {	//En fait c un pt sur string  et pas un tab char	
		addr_m +=4 ; 	
	}
	else {
		printf ("[Insert_tmp: Unknown type]") ; 
		addr_m +=2 ; 	
	}
	index_ts ++ ;
	//Show 
	show_ts() ; 
	 // On renvoi l'adresse d
	return index_ts - 1 ;

}

	//Test si bon type ??


	//Enlever 1 elm du tab avec son nom , rajout test de type et bouger addr_m ?  
int remove_elm (char *elm){ //elm <==> le nom de l'elm


	int res = -1 ;
	 //Elm non existant donc on ne peut pas le retirer
	if (get_addr(elm) == -1) printf("[Remove: %s doesn't exist\n",elm) ; 

	else {
		printf("[Remove: %s exists]\n",elm) ;
		res = get_addr(elm) ;  //L'addr de l'elm à enlever

		strcpy(ts[res].type,"null") ;
		strcpy(ts[res].name, "null");
		ts[res].cste = -1;
		ts[res].init = -1;
		ts[res].deep = -1 ;

		ts[res].addr = -1 ; //l'adress qu'il avait ne lui appartient plus
		printf("[Remove: Removing of %s succed]\n",elm) ;
		show_ts() ;
	}
	return res ; 

}


int get_last_addr () {  // A voir si jamais on doit bouger addr_m
	
	int ad ;
	char *type ;  
	index_ts-- ; 
	
	type= ts[index_ts].type ; 
	ad = ts[index_ts].addr ;  

	strcpy(ts[index_ts].name, "null");
	ts[index_ts].cste = -1;
	ts[index_ts].init = -1;
	ts[index_ts].deep = -1 ;
	

	if (strcmp(type,"int")==0) { 
		addr_m -=2 ; 
	} 
	else if (strcmp(type,"string")==0) {		
		addr_m -=4 ; 	
	}
	else {
		printf ("[Insert_tmp: Unknown type]") ; 
		addr_m -=2; 	
	}

	ts[index_ts].addr = -1 ;
	strcpy(ts[index_ts].type,"null") ; 

	return ad ; 
	
} 

	//Enlever 1 tmp du tab (le dernier) , rajout test de type et bouger addr_m ? 
int remove_tmp (){ //elm <==> le nom de l'elm

		
	//Show ts before
	printf("[Function : Remove_tmp, show the ts]") ;	
	show_ts() ;


	int res = -6 ;
	char *type ;
	index_ts = index_ts - 1 ;	//On se place sur le dernier elm

	//On vérifie si le dernier elm est bien un tmp
	if (strcmp(ts[index_ts].name,"tmp")==0){	
		printf("[Remove_tmp: The last symbol is a tmp\n") ; 
		
		type = ts[index_ts].type ; 
		strcpy(ts[index_ts].type,"null") ;
		strcpy(ts[index_ts].name, "null");
		ts[index_ts].deep = -1 ;
		ts[index_ts].addr = -1 ; //l'adress qu'il avait ne lui appartient plus
		
		if (strcmp(type,"int")==0) { 
				addr_m -=2 ; 
			} 
		else if (strcmp(type,"string")==0) {		
				addr_m -=4 ; 	
			}
		else {
				printf ("[Remove_tmp: Unknown type]") ; 
				addr_m -=2 ; 	
			}

			
		printf("[Remove_tmp: Removing of the last tmp succed]\n") ;
		show_ts() ;
		res=0 ;
	}
	else { //Il y a une erreur car le dernier elm n'est pas un tmp
		printf("[Remove_tmp: Removing of the last tmp not succed]\n") ;
	    index_ts = index_ts++ ;
		show_ts() ;
	}
	return res ; 

}

	//Enlever le dernier elm qlq soit son type
int remove_lastElm (){ 

		
	//Show ts before
	printf("[Function : clean_tab, show the ts]\n") ;	
	show_ts() ;
	index_ts = index_ts - 1 ;
	int res = -1 ;
	char *type ;
	//Recup le type de ce denrier elm pr savoir cb d'octets diminuer l'addr mem
	if (strcmp(ts[index_ts].name,"tmp")!=0){	
		printf("[Remove_lastElm: The last symbol is a variable \n") ; 
		type = ts[index_ts].type ; 
		strcpy(ts[index_ts].type,"null") ;
		strcpy(ts[index_ts].name, "null");
		ts[index_ts].deep = -1 ;
		ts[index_ts].addr = -1 ; //l'adress qu'il avait ne lui appartient plus
	
		if (strcmp(type,"int")==0) { 
				addr_m -=2 ; 
			} 
		else if (strcmp(type,"string")==0) {		
				addr_m -=4 ; 	
			}
		else {
				printf ("[: Unknown type]") ; 
				addr_m -=2 ; 	
			}

		
		printf("[Remove_lastElm: Removing of the last variable succed]\n") ;
		show_ts() ;
	}
	else { 
		printf("[Remove_lastElm: Removing of the last variable not succed]\n") ;
	    index_ts = index_ts++ ;
		show_ts() ;

	} 
	return res ;
}



	
void clean_prof () { 
	printf(" call clean_prof %d %d",prof,ts[index_ts - 1].deep ) ; 
	int i = index_ts - 1 ; 
	//int fini = 1 ; //true  
	
	while (ts[i].deep==prof) { 
		if (strcmp(ts[i].name,"tmp")==0) {
			remove_tmp () ; 
		}
		else{
			remove_lastElm() ; 
		}

		i-- ; 
	}

	prof -- ;

		
}

void set_int (){
	t= "int" ; //bon recopiage ?
}
void set_void (){
	t= "void" ; //bon recopiage ?
}
void set_string (){
	t= "string" ; //bon recopiage ?
}

void inc_prof(){
	prof ++ ;
}




/*int main (){ //Test 

	insert("var", 0, 1) ;		

	insert("var2", 0,1) ;
	insert("var3", 0, 1) ;
	remove_elm("var2") ;
	insert_tmp(0) ;
	insert_tmp(1) ;
	remove_tmp() ;

	
}*/

