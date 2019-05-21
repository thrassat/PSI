/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    tIF = 258,
    tELSE = 259,
    tWHILE = 260,
    tPLUS = 261,
    tLESS = 262,
    tAFFECT = 263,
    tEQUIV = 264,
    tDIFF = 265,
    tSUP = 266,
    tINF = 267,
    tSUPEQ = 268,
    tINFEQ = 269,
    tMUL = 270,
    tDIV = 271,
    tPARO = 272,
    tPARF = 273,
    tACCO = 274,
    tACCF = 275,
    tPV = 276,
    tVIRG = 277,
    tVOID = 278,
    tRETURN = 279,
    tPRINTF = 280,
    tCONST = 281,
    tINT = 282,
    tSTRING = 283,
    tVAR = 284,
    tNB = 285,
    tS = 286,
    tERROR = 287,
    tIFX = 288
  };
#endif
/* Tokens.  */
#define tIF 258
#define tELSE 259
#define tWHILE 260
#define tPLUS 261
#define tLESS 262
#define tAFFECT 263
#define tEQUIV 264
#define tDIFF 265
#define tSUP 266
#define tINF 267
#define tSUPEQ 268
#define tINFEQ 269
#define tMUL 270
#define tDIV 271
#define tPARO 272
#define tPARF 273
#define tACCO 274
#define tACCF 275
#define tPV 276
#define tVIRG 277
#define tVOID 278
#define tRETURN 279
#define tPRINTF 280
#define tCONST 281
#define tINT 282
#define tSTRING 283
#define tVAR 284
#define tNB 285
#define tS 286
#define tERROR 287
#define tIFX 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 12 "compilateurc.y" /* yacc.c:1909  */

	int i ;
	char* c ;

#line 125 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
