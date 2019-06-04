#ifndef __TS_H__
#define __TS_H__

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define TAILLE 1024


typedef struct 
{
	char type [16];
	char name [16];
	int cste ;	//bool
	int init ;  //bool
	int deep ;
	int addr;

} symbol ;

symbol ts [TAILLE] ; //Tab symbole

void show_ts () ; 

int get_addr (char *elm) ;      //Get address from name, -5 si n'existe pas 

int get_addr_fi (int i) ;   	//Get address from index , implémenter comme si existe. 

int get_index (char *elm) ;  	//Get index from name

int insert (char *nom, int cons, int init2) ; //Insérer 1 elm dans le tab , renvoi -1 si celui-ci est déjà présent

int insert_tmp () ; //Insérer 1 var tmp dans le tab, renvoi l'index du tmp inséré 

int remove_elm (char *elm) ; 	//Enlever 1 elm du tab avec son nom

int get_last_addr () ; // Renvoi l'addr du dernier element de la pile et le supprime

int remove_tmp () ; //Enlever 1 tmp du tab (le dernier) (pop)

void clean_prof () ; // pop les lignes de la table des s qui deviennent obsolètes
					// Et decrémente prof
void inc_prof() ; //prof ++

//Mettre à jour le type de t
void set_int () ;	
void set_void () ;
void set_string () ;



#endif
