#ifndef __TI_H__
#define __TI_H__

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define TAILLE 1024

typedef struct 
{
	char op [6];
	int a  ;
	int b  ;
	int c  ;

} instruction ;

instruction ti [TAILLE] ; //Tab instruction

// char * changé en int pour les registres ! 

void insert3(char *operation, int ri, int rj, int rk) ;
void insert2(char *operation, int ri, int rj) ;
void insert1(char *operation, int ri) ;
void show_ti() ;
void export_tab() ; 
int  get_last_ti() ; //Index de la dernière instruction
int set_ti(int ligne, char *param, int maj) ;	//Mettre à jour un elm (param) d'une ligne d'asm (ligne)

#endif
