%{
#include "y.tab.h"
%}
%%
"if" 		{return tIF ;}
"else" 		{return tELSE ;}
"while" 	{return tWHILE ;}
"+" 		{return tPLUS ;}
"-" 		{return tLESS ;}
"=" 		{return tAFFECT ;}
"=="		 {return tEQUIV ;}
"!="		 {return tDIFF ;}
">" 		{return tSUP ;}
"<"		 	{return tINF ;}
">=" 		{return tSUPEQ ;}
"<=" 		{return tINFEQ ;}
"*" 		{return tMUL ;}
"/" 		{return tDIV ;}
"(" 		{return tPARO ;}
")" 		{return tPARF ;}
"{" 		{return tACCO ;}
"}" 		{return tACCF ;}
";" 		{return tPV ;}
"," 		{return tVIRG ;}
"void" 		{return tVOID ;}
"return" 		{return tRETURN ;}
"printf" 		{return tPRINTF ;}
"const" 		{return tCONST ;}
"int" 			{return tINT ;}
"string" 		{return tSTRING ;}
[" "| "\t" | "\n"] 		{}
[a-zA-Z][a-zA-Z0-9_]* 	{ yylval.c=strdup(yytext) ; return tVAR ;}
[a-zA-Z][a-zA-Z0-9_]* 	{ yylval.c=strdup(yytext) ; return tS ;}
[0-9]+ 					{ yylval.i=atoi(yytext) ; return tNB ;} 
[0-9]+e^-?[0-9]+ 		{ yylval.i=atoi(yytext) ; return tNB ;} 
. 						{return tERROR ;}

