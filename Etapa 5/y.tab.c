/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

/**************************************
*    Mateus Luiz Salvi - 00229787     *
*             INF - UFRGS             *
**************************************/
#define YYDEBUG 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "hashtable.h"
#include "semantic.h"
#include "tacs.h"

int yyerror(char *s);
int yylex();
extern int getLineNumber(void);
extern int yydebug;
extern int SemanticErrors;

AstNode *ASTRoot;


#line 95 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    KW_INT = 258,
    KW_REAL = 259,
    KW_CHAR = 260,
    KW_BOOL = 261,
    KW_IF = 262,
    KW_THEN = 263,
    KW_ELSE = 264,
    KW_LOOP = 265,
    KW_INPUT = 266,
    KW_OUTPUT = 267,
    KW_RETURN = 268,
    OPERATOR_LE = 269,
    OPERATOR_GE = 270,
    OPERATOR_EQ = 271,
    OPERATOR_DIF = 272,
    TK_IDENTIFIER = 273,
    LIT_INT = 274,
    LIT_REAL = 275,
    LIT_CHAR = 276,
    LIT_STRING = 277,
    TOKEN_ERROR = 278
  };
#endif
/* Tokens.  */
#define KW_INT 258
#define KW_REAL 259
#define KW_CHAR 260
#define KW_BOOL 261
#define KW_IF 262
#define KW_THEN 263
#define KW_ELSE 264
#define KW_LOOP 265
#define KW_INPUT 266
#define KW_OUTPUT 267
#define KW_RETURN 268
#define OPERATOR_LE 269
#define OPERATOR_GE 270
#define OPERATOR_EQ 271
#define OPERATOR_DIF 272
#define TK_IDENTIFIER 273
#define LIT_INT 274
#define LIT_REAL 275
#define LIT_CHAR 276
#define LIT_STRING 277
#define TOKEN_ERROR 278

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "parser.y"

       AstNode *node;
       HashTableNode *symbol;

#line 198 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   314

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  124

#define YYUNDEFTOK  2
#define YYMAXUTOK   278


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    26,     2,
      35,    36,    31,    29,    41,    30,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    34,
      24,    33,    25,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,    27,    40,    28,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    81,    81,    96,    97,   100,   101,   102,   105,   106,
     107,   108,   111,   112,   115,   116,   117,   120,   123,   124,
     127,   128,   131,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   146,   147,   150,   151,   154,   155,   158,
     161,   162,   165,   166,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "KW_INT", "KW_REAL", "KW_CHAR",
  "KW_BOOL", "KW_IF", "KW_THEN", "KW_ELSE", "KW_LOOP", "KW_INPUT",
  "KW_OUTPUT", "KW_RETURN", "OPERATOR_LE", "OPERATOR_GE", "OPERATOR_EQ",
  "OPERATOR_DIF", "TK_IDENTIFIER", "LIT_INT", "LIT_REAL", "LIT_CHAR",
  "LIT_STRING", "TOKEN_ERROR", "'<'", "'>'", "'&'", "'|'", "'~'", "'+'",
  "'-'", "'*'", "'/'", "'='", "';'", "'('", "')'", "'['", "']'", "'{'",
  "'}'", "','", "$accept", "program", "declarations", "declaration",
  "type", "vectorInicialization", "literal", "block", "parameters",
  "parametersTail", "parameter", "command", "outputParameters",
  "outputParametersTail", "commandList", "functionCall", "expressionList",
  "expressionListTail", "expression", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,    60,    62,    38,   124,   126,    43,
      45,    42,    47,    61,    59,    40,    41,    91,    93,   123,
     125,    44
};
# endif

#define YYPACT_NINF (-108)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      85,  -108,  -108,  -108,  -108,     6,  -108,    85,    -9,  -108,
    -108,   -30,    55,    85,   176,  -108,  -108,  -108,   -20,    -3,
     -12,    12,     3,    44,   176,   176,  -108,  -108,   110,  -108,
    -108,    15,    85,  -108,    85,   176,   176,    99,   192,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,    55,    39,  -108,    12,    31,    35,    70,   129,  -108,
      29,    29,    29,    29,    29,    29,    99,    99,    18,    18,
    -108,  -108,    36,    55,    45,   170,   176,   -17,  -108,     5,
    -108,    39,    25,  -108,  -108,  -108,   176,  -108,  -108,  -108,
    -108,   176,    51,    59,    91,   238,   176,   176,  -108,  -108,
    -108,    70,   215,   170,  -108,  -108,  -108,  -108,   259,   148,
    -108,    30,    51,  -108,    65,    39,    94,  -108,   176,  -108,
      39,   280,  -108,  -108
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     8,     9,    10,    11,     0,     2,     4,     0,     1,
       3,     0,     0,    18,     0,    14,    15,    16,     0,     0,
       0,    20,     0,    62,     0,     0,    60,    58,     0,     5,
      22,     0,     0,    19,     0,    40,     0,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    12,    37,     6,    20,     0,     0,    42,     0,    57,
      56,    55,    54,    53,    49,    48,    50,    51,    44,    45,
      47,    46,     0,    12,     0,     0,     0,     0,    31,     0,
      30,    37,     0,    21,    59,    39,     0,    41,    61,     7,
      13,     0,    35,     0,    35,     0,     0,     0,    32,    38,
      17,    42,     0,     0,    34,    27,    33,    26,     0,     0,
      43,     0,    35,    29,     0,     0,    24,    36,     0,    25,
       0,     0,    23,    28
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -108,  -108,   102,  -108,    34,    37,   -10,    81,  -108,    60,
      87,  -107,    10,   -93,    52,  -108,  -108,    46,   -14
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    72,    26,    80,    20,    33,
      21,    81,    93,   104,    82,    27,    56,    87,    94
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      28,   106,    18,    12,   116,    13,     9,    14,   119,    11,
      37,    38,    74,   122,    29,    30,    96,    75,    76,   117,
      97,    57,    58,    77,    31,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    74,    34,    78,
     115,    73,    75,    76,    79,    98,    74,    19,    77,    49,
      50,    75,    76,    32,    52,    45,    46,    77,    47,    48,
      49,    50,    95,    73,    78,   100,    19,    84,    55,    79,
      89,    85,   101,    78,    15,    16,    17,   102,    79,    35,
      91,    36,   108,   109,    39,    40,    41,    42,     1,     2,
       3,     4,   103,   105,    43,    44,    45,    46,   118,    47,
      48,    49,    50,   120,   121,    39,    40,    41,    42,    10,
      90,    86,    53,   112,    83,    43,    44,    45,    46,    54,
      47,    48,    49,    50,    39,    40,    41,    42,    47,    48,
      49,    50,   103,    99,    43,    44,    45,    46,     0,    47,
      48,    49,    50,    39,    40,    41,    42,   110,    51,     0,
       0,     0,     0,    43,    44,    45,    46,     0,    47,    48,
      49,    50,    39,    40,    41,    42,     0,    88,     0,     0,
       0,     0,    43,    44,    45,    46,     0,    47,    48,    49,
      50,    22,     0,     0,     0,     0,   114,    22,    23,    15,
      16,    17,    92,     0,    23,    15,    16,    17,    24,     0,
       0,     0,     0,     0,    24,    25,    39,    40,    41,    42,
       0,    25,     0,     0,     0,     0,    43,    44,    45,    46,
       0,    47,    48,    49,    50,     0,     0,     0,    59,    39,
      40,    41,    42,     0,     0,     0,     0,     0,     0,    43,
      44,    45,    46,     0,    47,    48,    49,    50,     0,     0,
       0,   111,    39,    40,    41,    42,     0,     0,     0,     0,
       0,     0,    43,    44,    45,    46,     0,    47,    48,    49,
      50,     0,   107,    39,    40,    41,    42,     0,     0,     0,
       0,     0,     0,    43,    44,    45,    46,     0,    47,    48,
      49,    50,     0,   113,    39,    40,    41,    42,     0,     0,
       0,     0,     0,     0,    43,    44,    45,    46,     0,    47,
      48,    49,    50,     0,   123
};

static const yytype_int8 yycheck[] =
{
      14,    94,    12,    33,   111,    35,     0,    37,   115,    18,
      24,    25,     7,   120,    34,    18,    33,    12,    13,   112,
      37,    35,    36,    18,    36,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,     7,    35,    34,
      10,    51,    12,    13,    39,    40,     7,    13,    18,    31,
      32,    12,    13,    41,    39,    26,    27,    18,    29,    30,
      31,    32,    76,    73,    34,    40,    32,    36,    34,    39,
      34,    36,    86,    34,    19,    20,    21,    91,    39,    35,
      35,    37,    96,    97,    14,    15,    16,    17,     3,     4,
       5,     6,    41,    34,    24,    25,    26,    27,    33,    29,
      30,    31,    32,     9,   118,    14,    15,    16,    17,     7,
      73,    41,    31,   103,    54,    24,    25,    26,    27,    32,
      29,    30,    31,    32,    14,    15,    16,    17,    29,    30,
      31,    32,    41,    81,    24,    25,    26,    27,    -1,    29,
      30,    31,    32,    14,    15,    16,    17,   101,    38,    -1,
      -1,    -1,    -1,    24,    25,    26,    27,    -1,    29,    30,
      31,    32,    14,    15,    16,    17,    -1,    38,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,    -1,    29,    30,    31,
      32,    11,    -1,    -1,    -1,    -1,    38,    11,    18,    19,
      20,    21,    22,    -1,    18,    19,    20,    21,    28,    -1,
      -1,    -1,    -1,    -1,    28,    35,    14,    15,    16,    17,
      -1,    35,    -1,    -1,    -1,    -1,    24,    25,    26,    27,
      -1,    29,    30,    31,    32,    -1,    -1,    -1,    36,    14,
      15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    -1,    29,    30,    31,    32,    -1,    -1,
      -1,    36,    14,    15,    16,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,    -1,    29,    30,    31,
      32,    -1,    34,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    25,    26,    27,    -1,    29,    30,
      31,    32,    -1,    34,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,    -1,    29,
      30,    31,    32,    -1,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    43,    44,    45,    46,     0,
      44,    18,    33,    35,    37,    19,    20,    21,    48,    46,
      50,    52,    11,    18,    28,    35,    48,    57,    60,    34,
      18,    36,    41,    51,    35,    35,    37,    60,    60,    14,
      15,    16,    17,    24,    25,    26,    27,    29,    30,    31,
      32,    38,    39,    49,    52,    46,    58,    60,    60,    36,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    47,    48,     7,    12,    13,    18,    34,    39,
      49,    53,    56,    51,    36,    36,    41,    59,    38,    34,
      47,    35,    22,    54,    60,    60,    33,    37,    40,    56,
      40,    60,    60,    41,    55,    34,    55,    34,    60,    60,
      59,    36,    54,    34,    38,    10,    53,    55,    33,    53,
       9,    60,    53,    34
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    45,    46,    46,
      46,    46,    47,    47,    48,    48,    48,    49,    50,    50,
      51,    51,    52,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    54,    54,    55,    55,    56,    56,    57,
      58,    58,    59,    59,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     5,     6,     7,     1,     1,
       1,     1,     0,     2,     1,     1,     1,     3,     0,     2,
       0,     3,     2,     7,     5,     6,     3,     3,     7,     4,
       1,     1,     2,     2,     2,     0,     3,     0,     2,     4,
       0,     2,     0,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     3,     3,     1,     4,
       1,     4,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2:
#line 81 "parser.y"
                      { 
                        ASTRoot = (yyval.node);
                        fprintf(stderr, "\n-------------- PRINTING TREE --------------\n"); 
                        PrintTree(0, ASTRoot);
                        fprintf(stderr, "------------ END OF PRINT TREE ------------\n\n\n");
                        fprintf(stderr, "---------- ERRORS (IF APLICABLE) ----------\n");
                        CheckAndSetDeclarations(ASTRoot);
                        CheckUndeclared();
                        //CheckOperands(ASTRoot);
                        //CheckUsage(ASTRoot);
                        fprintf(stderr, "-------------- END OF ERRORS --------------\n\n");
                        TacPrintBackwards(GenerateCode(ASTRoot));
                      }
#line 1505 "y.tab.c"
    break;

  case 3:
#line 96 "parser.y"
                                       { (yyval.node) = CreateNode(AST_DECLIST, 0, (yyvsp[-1].node), (yyvsp[0].node), 0, 0); }
#line 1511 "y.tab.c"
    break;

  case 4:
#line 97 "parser.y"
              { (yyval.node) = 0; }
#line 1517 "y.tab.c"
    break;

  case 5:
#line 100 "parser.y"
                                                { (yyval.node) = CreateNode(AST_VARDEC, (yyvsp[-3].symbol), (yyvsp[-4].node), (yyvsp[-1].node), 0, 0); }
#line 1523 "y.tab.c"
    break;

  case 6:
#line 101 "parser.y"
                                                         { (yyval.node) = CreateNode(AST_FUNCDEC, (yyvsp[-4].symbol), (yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[0].node), 0); }
#line 1529 "y.tab.c"
    break;

  case 7:
#line 102 "parser.y"
                                                                            { (yyval.node) = CreateNode(AST_VECDEC, (yyvsp[-5].symbol), (yyvsp[-6].node), (yyvsp[-3].node), (yyvsp[-1].node), 0);}
#line 1535 "y.tab.c"
    break;

  case 8:
#line 105 "parser.y"
              { (yyval.node) = CreateNode(AST_TYPE_INT, 0, 0, 0, 0, 0); }
#line 1541 "y.tab.c"
    break;

  case 9:
#line 106 "parser.y"
              { (yyval.node) = CreateNode(AST_TYPE_REAL, 0, 0, 0, 0, 0); }
#line 1547 "y.tab.c"
    break;

  case 10:
#line 107 "parser.y"
              { (yyval.node) = CreateNode(AST_TYPE_CHAR, 0, 0, 0, 0, 0); }
#line 1553 "y.tab.c"
    break;

  case 11:
#line 108 "parser.y"
              { (yyval.node) = CreateNode(AST_TYPE_BOOL, 0, 0, 0, 0, 0); }
#line 1559 "y.tab.c"
    break;

  case 12:
#line 111 "parser.y"
                      { (yyval.node) = 0; }
#line 1565 "y.tab.c"
    break;

  case 13:
#line 112 "parser.y"
                                                   { (yyval.node) = CreateNode(AST_VECINIT, 0, (yyvsp[-1].node), (yyvsp[0].node), 0, 0); }
#line 1571 "y.tab.c"
    break;

  case 14:
#line 115 "parser.y"
                  { (yyval.node) = CreateNode(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0); }
#line 1577 "y.tab.c"
    break;

  case 15:
#line 116 "parser.y"
                  { (yyval.node) = CreateNode(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0); }
#line 1583 "y.tab.c"
    break;

  case 16:
#line 117 "parser.y"
                  { (yyval.node) = CreateNode(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0); }
#line 1589 "y.tab.c"
    break;

  case 17:
#line 120 "parser.y"
                           { (yyval.node) = CreateNode(AST_BLOCK, 0, (yyvsp[-1].node), 0, 0, 0); }
#line 1595 "y.tab.c"
    break;

  case 18:
#line 123 "parser.y"
            { (yyval.node) = 0; }
#line 1601 "y.tab.c"
    break;

  case 19:
#line 124 "parser.y"
                                     { (yyval.node) = CreateNode(AST_PARAMS, 0, (yyvsp[-1].node), (yyvsp[0].node), 0, 0); }
#line 1607 "y.tab.c"
    break;

  case 20:
#line 127 "parser.y"
                { (yyval.node) = 0; }
#line 1613 "y.tab.c"
    break;

  case 21:
#line 128 "parser.y"
                                             { (yyval.node) = CreateNode(AST_PARAMTAIL, 0, (yyvsp[-1].node), (yyvsp[0].node), 0, 0); }
#line 1619 "y.tab.c"
    break;

  case 22:
#line 131 "parser.y"
                               { (yyval.node) = CreateNode(AST_PARAM, (yyvsp[0].symbol), (yyvsp[-1].node), 0, 0, 0); }
#line 1625 "y.tab.c"
    break;

  case 23:
#line 134 "parser.y"
                                                          { (yyval.node) = CreateNode(AST_IFELSE, 0, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node), 0); }
#line 1631 "y.tab.c"
    break;

  case 24:
#line 135 "parser.y"
                                          { (yyval.node) = CreateNode(AST_IF, 0, (yyvsp[-2].node), (yyvsp[0].node), 0, 0); }
#line 1637 "y.tab.c"
    break;

  case 25:
#line 136 "parser.y"
                                                  { (yyval.node) = CreateNode(AST_IFLOOP, 0, (yyvsp[-3].node), (yyvsp[0].node), 0, 0); }
#line 1643 "y.tab.c"
    break;

  case 26:
#line 137 "parser.y"
                                  { (yyval.node) = CreateNode(AST_RETURN, 0, (yyvsp[-1].node), 0, 0, 0); }
#line 1649 "y.tab.c"
    break;

  case 27:
#line 138 "parser.y"
                                        { (yyval.node) = CreateNode(AST_OUTPUT, 0, (yyvsp[-1].node), 0, 0, 0); }
#line 1655 "y.tab.c"
    break;

  case 28:
#line 139 "parser.y"
                                                             { (yyval.node) = CreateNode(AST_VECATTRIB, (yyvsp[-6].symbol), (yyvsp[-4].node), (yyvsp[-1].node), 0, 0); }
#line 1661 "y.tab.c"
    break;

  case 29:
#line 140 "parser.y"
                                          { (yyval.node) = CreateNode(AST_ATTRIB, (yyvsp[-3].symbol), (yyvsp[-1].node), 0, 0, 0); }
#line 1667 "y.tab.c"
    break;

  case 30:
#line 141 "parser.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1673 "y.tab.c"
    break;

  case 31:
#line 142 "parser.y"
             { (yyval.node) = 0; }
#line 1679 "y.tab.c"
    break;

  case 32:
#line 143 "parser.y"
                 { (yyval.node) = CreateNode(AST_BLANKBLOCK, 0, 0, 0, 0, 0); }
#line 1685 "y.tab.c"
    break;

  case 33:
#line 146 "parser.y"
                                                  { (yyval.node) = CreateNode(AST_OUTPUTLIST, 0, (yyvsp[-1].node), (yyvsp[0].node), 0, 0); }
#line 1691 "y.tab.c"
    break;

  case 34:
#line 147 "parser.y"
                                                  { (yyval.node) = CreateNode(AST_OUTPUTLIST, 0, CreateNode(AST_SYMBOL, (yyvsp[-1].symbol), 0, 0, 0, 0), (yyvsp[0].node), 0, 0); }
#line 1697 "y.tab.c"
    break;

  case 35:
#line 150 "parser.y"
                      { (yyval.node) = 0; }
#line 1703 "y.tab.c"
    break;

  case 36:
#line 151 "parser.y"
                                                                { (yyval.node) = CreateNode(AST_OUTPUTTAIL, 0, (yyvsp[-1].node), (yyvsp[0].node), 0, 0); }
#line 1709 "y.tab.c"
    break;

  case 37:
#line 154 "parser.y"
             { (yyval.node) = 0; }
#line 1715 "y.tab.c"
    break;

  case 38:
#line 155 "parser.y"
                                 { (yyval.node) =  CreateNode(AST_CMDLIST, 0, (yyvsp[-1].node), (yyvsp[0].node), 0, 0); }
#line 1721 "y.tab.c"
    break;

  case 39:
#line 158 "parser.y"
                                                   { (yyval.node) = CreateNode(AST_FUNCALL, (yyvsp[-3].symbol), (yyvsp[-1].node), 0, 0, 0);}
#line 1727 "y.tab.c"
    break;

  case 40:
#line 161 "parser.y"
                { (yyval.node) = 0; }
#line 1733 "y.tab.c"
    break;

  case 41:
#line 162 "parser.y"
                                              { (yyval.node) = CreateNode(AST_EXPLIST, 0, (yyvsp[-1].node), (yyvsp[0].node), 0, 0); }
#line 1739 "y.tab.c"
    break;

  case 42:
#line 165 "parser.y"
                    { (yyval.node) = 0; }
#line 1745 "y.tab.c"
    break;

  case 43:
#line 166 "parser.y"
                                                      { (yyval.node) = CreateNode(AST_EXPLISTTAIL, 0, (yyvsp[-1].node), (yyvsp[0].node), 0, 0); }
#line 1751 "y.tab.c"
    break;

  case 44:
#line 168 "parser.y"
                                      { (yyval.node) = CreateNode(AST_ADD, 0, (yyvsp[-2].node), (yyvsp[0].node), 0, 0); }
#line 1757 "y.tab.c"
    break;

  case 45:
#line 169 "parser.y"
                                      { (yyval.node) = CreateNode(AST_SUB, 0, (yyvsp[-2].node), (yyvsp[0].node), 0, 0); }
#line 1763 "y.tab.c"
    break;

  case 46:
#line 170 "parser.y"
                                      { (yyval.node) = CreateNode(AST_DIV, 0, (yyvsp[-2].node), (yyvsp[0].node), 0, 0); }
#line 1769 "y.tab.c"
    break;

  case 47:
#line 171 "parser.y"
                                      { (yyval.node) = CreateNode(AST_MULT, 0, (yyvsp[-2].node), (yyvsp[0].node), 0, 0); }
#line 1775 "y.tab.c"
    break;

  case 48:
#line 172 "parser.y"
                                      { (yyval.node) = CreateNode(AST_GREATER, 0, (yyvsp[-2].node), (yyvsp[0].node), 0, 0); }
#line 1781 "y.tab.c"
    break;

  case 49:
#line 173 "parser.y"
                                      { (yyval.node) = CreateNode(AST_LESS, 0, (yyvsp[-2].node), (yyvsp[0].node), 0, 0); }
#line 1787 "y.tab.c"
    break;

  case 50:
#line 174 "parser.y"
                                      { (yyval.node) = CreateNode(AST_AND, 0, (yyvsp[-2].node), (yyvsp[0].node), 0, 0); }
#line 1793 "y.tab.c"
    break;

  case 51:
#line 175 "parser.y"
                                      { (yyval.node) = CreateNode(AST_OR, 0, (yyvsp[-2].node), (yyvsp[0].node), 0, 0); }
#line 1799 "y.tab.c"
    break;

  case 52:
#line 176 "parser.y"
                           { (yyval.node) = CreateNode(AST_NOT, 0, (yyvsp[0].node), 0, 0, 0); }
#line 1805 "y.tab.c"
    break;

  case 53:
#line 177 "parser.y"
                                               { (yyval.node) = CreateNode(AST_DIF, 0, (yyvsp[-2].node), (yyvsp[0].node), 0, 0); }
#line 1811 "y.tab.c"
    break;

  case 54:
#line 178 "parser.y"
                                              { (yyval.node) = CreateNode(AST_EQ, 0, (yyvsp[-2].node), (yyvsp[0].node), 0, 0); }
#line 1817 "y.tab.c"
    break;

  case 55:
#line 179 "parser.y"
                                              { (yyval.node) = CreateNode(AST_GE, 0, (yyvsp[-2].node), (yyvsp[0].node), 0, 0); }
#line 1823 "y.tab.c"
    break;

  case 56:
#line 180 "parser.y"
                                              { (yyval.node) = CreateNode(AST_LE, 0, (yyvsp[-2].node), (yyvsp[0].node), 0, 0); }
#line 1829 "y.tab.c"
    break;

  case 57:
#line 181 "parser.y"
                             { (yyval.node) = CreateNode(AST_PAREN, 0, (yyvsp[-1].node), 0, 0, 0); }
#line 1835 "y.tab.c"
    break;

  case 58:
#line 182 "parser.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 1841 "y.tab.c"
    break;

  case 59:
#line 183 "parser.y"
                                  { (yyval.node) = CreateNode(AST_INPUT, 0, (yyvsp[-1].node), 0, 0, 0); }
#line 1847 "y.tab.c"
    break;

  case 60:
#line 184 "parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1853 "y.tab.c"
    break;

  case 61:
#line 185 "parser.y"
                                             { (yyval.node) = CreateNode(AST_VEC, (yyvsp[-3].symbol), (yyvsp[-1].node), 0, 0, 0); }
#line 1859 "y.tab.c"
    break;

  case 62:
#line 186 "parser.y"
                          { (yyval.node) = CreateNode(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0); }
#line 1865 "y.tab.c"
    break;


#line 1869 "y.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 189 "parser.y"


int yyerror(char *error)
{
       fprintf(stderr, "Syntax error at line %d\n", getLineNumber());
       exit(3); //Syntax error.
}

AstNode* GetAST()
{
       return ASTRoot;
}