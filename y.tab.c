/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "compilateurc.y" /* yacc.c:339  */

	#include "ts.h" 
	#include "ti.h"
	int yylex(void);
	void yyerror(char*) ;

#line 73 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 10 "compilateurc.y" /* yacc.c:355  */

	int i ;
	char* c ;

#line 184 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 201 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   129

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  49
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  95

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    37,    37,    39,    40,    42,    44,    45,    46,    48,
      49,    50,    52,    52,    56,    57,    58,    59,    60,    61,
      65,    67,    80,    82,    83,    85,    86,    89,    91,    94,
     104,   116,   127,   137,   148,   159,   171,   182,   193,   194,
     196,   203,   214,   220,   227,   224,   239,   241,   238,   262
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tIF", "tELSE", "tWHILE", "tPLUS",
  "tLESS", "tAFFECT", "tEQUIV", "tDIFF", "tSUP", "tINF", "tSUPEQ",
  "tINFEQ", "tMUL", "tDIV", "tPARO", "tPARF", "tACCO", "tACCF", "tPV",
  "tVIRG", "tVOID", "tRETURN", "tPRINTF", "tCONST", "tINT", "tSTRING",
  "tVAR", "tNB", "tS", "tERROR", "tIFX", "$accept", "start", "Fonctions",
  "Fonction", "Type", "Args", "Body", "$@1", "Content", "Afect", "Decla",
  "ListVars", "SuiteListVars", "Var", "Exp", "Value", "XIF", "If", "$@2",
  "While", "$@3", "$@4", "Printf", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288
};
# endif

#define YYPACT_NINF -36

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-36)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -5,   -36,   -36,   -36,     9,   -36,    -5,   -18,   -36,   -36,
      -4,    -5,     4,    17,    15,    33,    -5,   -36,   -36,   -36,
      11,    26,   -36,    36,    46,    32,    43,    11,    11,    11,
      11,    11,    -9,    38,    41,    28,    68,    62,    52,   -36,
     -36,   -36,   -36,   -36,   -36,    -9,   -36,   -36,    53,   -36,
      -9,    69,    75,    35,    -9,   -36,    32,   -36,    66,    -9,
      -9,    -9,    -9,    -9,    -9,    -9,    -9,    -9,   -36,    79,
      81,   -36,   -36,    92,    52,   -36,   107,   107,    92,    92,
      92,    92,    92,   115,   115,    33,   -36,   -36,   -36,    85,
      33,   -36,   -36,    33,   -36
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     6,     7,     8,     0,     2,     4,     0,     1,     3,
       0,    11,     0,     0,    10,     0,    11,    12,     5,     9,
      19,     0,    46,     0,     0,     0,     0,    19,    19,    19,
      19,    19,     0,     0,     0,     0,    28,     0,    24,    13,
      15,    14,    16,    17,    18,     0,    40,    41,     0,    38,
       0,     0,    41,     0,     0,    22,     0,    23,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    42,     0,
       0,    20,    21,    27,    26,    39,    31,    32,    33,    36,
      34,    37,    35,    29,    30,     0,    47,    49,    25,    43,
       0,    44,    48,     0,    45
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -36,   -36,    94,   -36,     1,    95,    24,   -36,   -25,   -36,
     -36,   -36,    39,    54,   -35,   -36,   -36,   -36,   -36,   -36,
     -36,   -36,   -36
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    25,    13,    18,    20,    26,    27,
      28,    37,    57,    38,    48,    49,    85,    29,    93,    30,
      33,    90,    31
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      53,     7,    40,    41,    42,    43,    44,     7,    45,     8,
      58,    10,    12,    11,    21,    69,    22,    12,     1,    73,
      46,    47,     2,     3,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    14,     1,    15,    23,    16,     2,     3,
      24,    59,    60,    32,    61,    45,    62,    63,    64,    65,
      66,    67,    17,    34,    35,    50,    72,    46,    52,    59,
      60,    36,    61,    39,    62,    63,    64,    65,    66,    67,
      51,    68,    59,    60,    56,    61,    54,    62,    63,    64,
      65,    66,    67,    55,    75,    59,    60,    70,    61,    91,
      62,    63,    64,    65,    66,    67,    71,    86,    59,    60,
       9,    61,    87,    62,    63,    64,    65,    66,    67,    89,
      74,    19,     0,    88,    92,     0,    61,    94,    62,    63,
      64,    65,    66,    67,    61,     0,    62,    63,    64,    65
};

static const yytype_int8 yycheck[] =
{
      35,     0,    27,    28,    29,    30,    31,     6,    17,     0,
      45,    29,    11,    17,     3,    50,     5,    16,    23,    54,
      29,    30,    27,    28,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    29,    23,    18,    25,    22,    27,    28,
      29,     6,     7,    17,     9,    17,    11,    12,    13,    14,
      15,    16,    19,    17,     8,    17,    21,    29,    30,     6,
       7,    29,     9,    20,    11,    12,    13,    14,    15,    16,
      29,    18,     6,     7,    22,     9,     8,    11,    12,    13,
      14,    15,    16,    21,    18,     6,     7,    18,     9,     4,
      11,    12,    13,    14,    15,    16,    21,    18,     6,     7,
       6,     9,    21,    11,    12,    13,    14,    15,    16,    85,
      56,    16,    -1,    74,    90,    -1,     9,    93,    11,    12,
      13,    14,    15,    16,     9,    -1,    11,    12,    13,    14
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    23,    27,    28,    35,    36,    37,    38,     0,    36,
      29,    17,    38,    39,    29,    18,    22,    19,    40,    39,
      41,     3,     5,    25,    29,    38,    42,    43,    44,    51,
      53,    56,    17,    54,    17,     8,    29,    45,    47,    20,
      42,    42,    42,    42,    42,    17,    29,    30,    48,    49,
      17,    29,    30,    48,     8,    21,    22,    46,    48,     6,
       7,     9,    11,    12,    13,    14,    15,    16,    18,    48,
      18,    21,    21,    48,    47,    18,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    50,    18,    21,    46,    40,
      55,     4,    40,    52,    40
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    34,    35,    36,    36,    37,    38,    38,    38,    39,
      39,    39,    41,    40,    42,    42,    42,    42,    42,    42,
      43,    43,    44,    45,    45,    46,    46,    47,    47,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      49,    49,    50,    51,    52,    51,    54,    55,    53,    56
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     6,     1,     1,     1,     4,
       2,     0,     0,     4,     2,     2,     2,     2,     2,     0,
       4,     4,     3,     2,     1,     3,     2,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       1,     1,     0,     6,     0,     9,     0,     0,     7,     5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 6:
#line 44 "compilateurc.y" /* yacc.c:1646  */
    { set_void() ; }
#line 1345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 45 "compilateurc.y" /* yacc.c:1646  */
    { set_int() ; }
#line 1351 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 46 "compilateurc.y" /* yacc.c:1646  */
    { set_string() ; }
#line 1357 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 52 "compilateurc.y" /* yacc.c:1646  */
    { inc_prof() ; }
#line 1363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 52 "compilateurc.y" /* yacc.c:1646  */
    {clean_prof() ; }
#line 1369 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 65 "compilateurc.y" /* yacc.c:1646  */
    { insert2("AFC",0,(yyvsp[-1].i)); // printf("AFC 0, %d\n", $1) ; 
								insert2("STORE",get_addr((yyvsp[-3].c)),0) ;}
#line 1376 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 89 "compilateurc.y" /* yacc.c:1646  */
    {remove_tmp() ; 
						insert((yyvsp[-2].c),0,1); }
#line 1383 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 91 "compilateurc.y" /* yacc.c:1646  */
    {insert((yyvsp[0].c),0,0); }
#line 1389 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 94 "compilateurc.y" /* yacc.c:1646  */
    { int ad1 = (yyvsp[-2].i); 
					int ad2 = (yyvsp[0].i) ; 
					insert2("LOAD",0,ad1) ; //printf("LOAD 0, %d\n",ad1) ; 
					insert2("LOAD",1,ad2) ; //printf("LOAD 1, %d\n",ad2) ;
					insert3("MUL",0,0,1) ; // printf("MUL 0,0,1") ;
					remove_tmp () ; //pop, remove add2
					insert2("STORE",ad1,0) ; //printf("STORE %d, 0\n", ad1) ;
					(yyval.i)= ad1 ;
					 }
#line 1403 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 104 "compilateurc.y" /* yacc.c:1646  */
    { int ad1 = (yyvsp[-2].i); 
					int ad2 = (yyvsp[0].i) ; 
					insert2("LOAD",0,ad1) ; //printf("LOAD 0, %d\n",ad1) ; 
					insert2("LOAD",1,ad2) ; //printf("LOAD 1, %d\n",ad2) ;
					insert3("DIV",0,0,1) ; // printf("DIV 0,0,1") ;
					remove_tmp () ; //pop, remove add2
					insert2("STORE",ad1,0) ; //printf("STORE %d, 0\n", ad1) ;
					(yyval.i)= ad1 ;
					}
#line 1417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 116 "compilateurc.y" /* yacc.c:1646  */
    { int ad1 = (yyvsp[-2].i); 
					int ad2 = (yyvsp[0].i) ; 
					insert2("LOAD",0,ad1) ; //printf("LOAD 0, %d\n",ad1) ; 
					insert2("LOAD",1,ad2) ; //printf("LOAD 1, %d\n",ad2) ;
					insert3("ADD",0,0,1) ; // printf("ADD 0,0,1") ;
					remove_tmp () ; //pop, remove add2
					insert2("STORE",ad1,0) ; //printf("STORE %d, 0\n", ad1) ;
					(yyval.i)= ad1 ; 
						 }
#line 1431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 127 "compilateurc.y" /* yacc.c:1646  */
    { int ad1 = (yyvsp[-2].i); 
					int ad2 = (yyvsp[0].i) ; 
					insert2("LOAD",0,ad1) ; //printf("LOAD 0, %d\n",ad1) ; 
					insert2("LOAD",1,ad2) ; //printf("LOAD 1, %d\n",ad2) ;
					insert3("SOU",0,0,1) ; // printf("SOU 0,0,1") ;
					remove_tmp () ; //pop, remove add2
					insert2("STORE",ad1,0) ; //printf("STORE %d, 0\n", ad1) ;
					(yyval.i)= ad1 ;
					 }
#line 1445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 137 "compilateurc.y" /* yacc.c:1646  */
    { int ad1 = (yyvsp[-2].i); 
					int ad2 = (yyvsp[0].i) ; 
					insert2("LOAD",1,ad1) ; //printf("LOAD 0, %d\n",ad1) ; 
					insert2("LOAD",2,ad2) ; //printf("LOAD 1, %d\n",ad2) ;
					insert3("EQU",0,1,2) ; // printf("SOU 0,0,1") ;
					remove_tmp () ; //pop, remove add2
					int tmp = insert_tmp() ; 
					insert2("STORE",get_addr_fi(tmp),0) ; //printf("STORE %d, 0\n", ad1) ;
					(yyval.i)= get_addr_fi(tmp) ;//remove_tmp () ;
					}
#line 1460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 148 "compilateurc.y" /* yacc.c:1646  */
    { int ad1 = (yyvsp[-2].i); 
				int ad2 = (yyvsp[0].i) ; 
				insert2("LOAD",1,ad1) ; //printf("LOAD 0, %d\n",ad1) ; 
				insert2("LOAD",2,ad2) ; //printf("LOAD 1, %d\n",ad2) ;
				insert3("INF",0,1,2) ; // printf("SOU 0,0,1") ;
				remove_tmp () ; //pop, remove add2
				int tmp = insert_tmp() ; 
				insert2("STORE",get_addr_fi(tmp),0) ; //printf("STORE %d, 0\n", ad1) ;
				(yyval.i)= get_addr_fi(tmp) ;//remove_tmp () ;
				}
#line 1475 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 159 "compilateurc.y" /* yacc.c:1646  */
    { int ad1 = (yyvsp[-2].i); 
				int ad2 = (yyvsp[0].i) ; 
				insert2("LOAD",1,ad1) ; //printf("LOAD 0, %d\n",ad1) ; 
				insert2("LOAD",2,ad2) ; //printf("LOAD 1, %d\n",ad2) ;
				insert3("INFE",0,1,2) ; // printf("SOU 0,0,1") ;
				remove_tmp () ; //pop, remove add2
				int tmp = insert_tmp() ; 
				insert2("STORE",get_addr_fi(tmp),0) ; //printf("STORE %d, 0\n", ad1) ;
				(yyval.i)= get_addr_fi(tmp) ;//remove_tmp () ;
				}
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 171 "compilateurc.y" /* yacc.c:1646  */
    { int ad1 = (yyvsp[-2].i); 
				int ad2 = (yyvsp[0].i) ; 
				insert2("LOAD",1,ad1) ; //printf("LOAD 0, %d\n",ad1) ; 
				insert2("LOAD",2,ad2) ; //printf("LOAD 1, %d\n",ad2) ;
				insert3("SUP",0,1,2) ; // printf("SOU 0,0,1") ;
				remove_tmp () ; //pop, remove add2
				int tmp = insert_tmp() ; 
				insert2("STORE",get_addr_fi(tmp),0) ; //printf("STORE %d, 0\n", ad1) ;
				(yyval.i)= get_addr_fi(tmp) ;//remove_tmp () ;
				}
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 182 "compilateurc.y" /* yacc.c:1646  */
    { int ad1 = (yyvsp[-2].i); 
				int ad2 = (yyvsp[0].i) ; 
				insert2("LOAD",1,ad1) ; //printf("LOAD 0, %d\n",ad1) ; 
				insert2("LOAD",2,ad2) ; //printf("LOAD 1, %d\n",ad2) ;
				insert3("SUPE",0,1,2) ; // printf("SOU 0,0,1") ;
				remove_tmp () ; //pop, remove add2
				int tmp = insert_tmp() ; 
				insert2("STORE",get_addr_fi(tmp),0) ; //printf("STORE %d, 0\n", ad1) ;
				(yyval.i)= get_addr_fi(tmp) ;//remove_tmp () ;
				}
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 193 "compilateurc.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i);}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 194 "compilateurc.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[-1].i); }
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 196 "compilateurc.y" /* yacc.c:1646  */
    {printf("id %s\n",(yyvsp[0].c));
				int addr = get_addr((yyvsp[0].c)) ; 
				/*OLD VERSION 	int tmp = insert_tmp() ; 
				insert2("LOAD",0,addr) ; //printf("LOAD 0, %d\n", addr) ; 
				insert2("STORE",get_addr_fi(tmp),0 ) ; //printf("STORE %d, 0\n", get_addr_fi(tmp)) ; */
				(yyval.i)=addr ;  }
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 203 "compilateurc.y" /* yacc.c:1646  */
    {printf("id %d\n",(yyvsp[0].i));
				int tmp = insert_tmp () ; 
				insert2("AFC",0,(yyvsp[0].i)) ; // printf("AFC 0, %d\n", $1) ; 
				insert2("STORE",get_addr_fi(tmp),0 ) ; //printf("STORE %d, 0\n", get_addr_fi(tmp)) ; 
			    int addr= get_addr_fi(tmp);
				(yyval.i)=addr ; }
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 214 "compilateurc.y" /* yacc.c:1646  */
    { //remove_tmp() ; 
		 // -1 est temporaire
		insert2("LOAD",1,get_last_addr());
		insert2("JMPC",-1,1) ;
	    (yyval.i) = get_last_ti()  ; }
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 222 "compilateurc.y" /* yacc.c:1646  */
    {set_ti((yyvsp[-1].i),"a",get_last_ti()+1); }
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 227 "compilateurc.y" /* yacc.c:1646  */
    {insert1("JMP",-1) ;  // saut a -1 si registre 1 à 0
				set_ti((yyvsp[-2].i),"a",get_last_ti()+1);   //Patch le If (le -1)
				(yyvsp[0].i) = get_last_ti() ;}
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 231 "compilateurc.y" /* yacc.c:1646  */
    {set_ti((yyvsp[-2].i),"a",get_last_ti()+1);}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 239 "compilateurc.y" /* yacc.c:1646  */
    {(yyvsp[0].i)=get_last_ti()+1; }
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 241 "compilateurc.y" /* yacc.c:1646  */
    { insert2("LOAD",1,get_last_addr());
								  insert2("JMPC",-1,1);  
								  (yyvsp[-2].i)=get_last_ti() ;}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 245 "compilateurc.y" /* yacc.c:1646  */
    {insert1("JMP",(yyvsp[-6].i));
				 set_ti((yyvsp[-4].i),"a",get_last_ti()+1); }
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 262 "compilateurc.y" /* yacc.c:1646  */
    {insert1("PRINT",get_addr((yyvsp[-2].c))); }
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1615 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 264 "compilateurc.y" /* yacc.c:1906  */
 

int main (void) { 
#ifdef YYDEBUG 
	yydebug=1 ; 
#endif 
	yyparse() ; 
	printf("FIN !!!!") ;
	export_tab() ;
} 

