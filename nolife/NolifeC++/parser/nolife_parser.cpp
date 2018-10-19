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
#line 7 "nolife_parser.y" /* yacc.c:339  */


#include <iostream>
#include <string>

#include "astnode.hpp"
#include "astprognode.hpp"

ast::Base gASTRoot = ast::Base();

int errcount=0;
int yyerror(const char *s);

/*********************EXTERNAL DECLARATIONS***********************/

extern char* yytext;
extern FILE  *yyin;
extern int yylex();


#line 87 "nolife_parser.cpp" /* yacc.c:339  */

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
   by #include "nolife_parser.hpp".  */
#ifndef YY_YY_NOLIFE_PARSER_HPP_INCLUDED
# define YY_YY_NOLIFE_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 28 "nolife_parser.y" /* yacc.c:355  */

#include <string>
#include "astsymnode.hpp"

#line 122 "nolife_parser.cpp" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    O_AND = 1,
    O_ARRAY = 2,
    O_BEGIN = 3,
    O_CHARACTER = 5,
    O_DO = 6,
    O_ELSE = 7,
    O_END = 8,
    O_FLOAT = 9,
    O_FUNCTION = 10,
    O_IF = 11,
    O_INTEGER = 12,
    O_NOT = 13,
    O_OF = 14,
    O_OR = 15,
    O_PROCEDURE = 16,
    O_PROGRAM = 17,
    O_READ = 18,
    O_THEN = 19,
    O_VAR = 20,
    O_WHILE = 21,
    O_WRITE = 22,
    O_LBRACE = 23,
    O_RBRACE = 24,
    O_CONSTANT = 25,
    O_LE = 26,
    O_LT = 27,
    O_GE = 28,
    O_GT = 29,
    O_EQ = 30,
    O_NE = 31,
    O_ASSIGN = 32,
    O_COLON = 33,
    O_SEMICOLON = 34,
    O_COMMA = 35,
    O_LBRACKET = 36,
    O_RBRACKET = 37,
    O_LPAREN = 38,
    O_RPAREN = 39,
    O_DOTDOT = 40,
    O_PLUS = 41,
    O_TIMES = 42,
    O_IDENTIFER = 43,
    O_MOD = 44,
    O_RETURN = 45,
    O_CHAR = 46,
    O_STRING = 47,
    O_INT = 48,
    O_FLOATCON = 49,
    O_MINUS = 50,
    O_CASE = 51
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 33 "nolife_parser.y" /* yacc.c:355  */

    int integer;
    ast::Symbol* symbol;

#line 192 "nolife_parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_NOLIFE_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 209 "nolife_parser.cpp" /* yacc.c:358  */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   285

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  208

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   257

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     3,     4,     5,     2,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   104,   104,   107,   110,   113,   120,   124,   126,   131,
     133,   137,   139,   143,   145,   147,   151,   155,   157,   161,
     163,   167,   169,   173,   175,   177,   179,   183,   187,   189,
     193,   195,   197,   199,   201,   203,   205,   207,   211,   215,
     217,   221,   223,   225,   227,   229,   231,   233,   235,   239,
     244,   246,   250,   252,   254,   258,   262,   264,   268,   272,
     274,   278,   280,   284,   288,   290,   294,   296,   300,   302,
     304,   308,   310,   314,   316,   320,   322,   326,   328,   330,
     332,   334,   338,   340,   344,   346,   350,   352,   356,   358,
     360,   362,   364,   366,   370,   372,   376,   381,   385,   389,
     393,   395,   399,   403,   408,   412,   416
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "O_AND", "O_ARRAY", "O_BEGIN",
  "O_CHARACTER", "O_DO", "O_ELSE", "O_END", "O_FLOAT", "O_FUNCTION",
  "O_IF", "O_INTEGER", "O_NOT", "O_OF", "O_OR", "O_PROCEDURE", "O_PROGRAM",
  "O_READ", "O_THEN", "O_VAR", "O_WHILE", "O_WRITE", "O_LBRACE",
  "O_RBRACE", "O_CONSTANT", "O_LE", "O_LT", "O_GE", "O_GT", "O_EQ", "O_NE",
  "O_ASSIGN", "O_COLON", "O_SEMICOLON", "O_COMMA", "O_LBRACKET",
  "O_RBRACKET", "O_LPAREN", "O_RPAREN", "O_DOTDOT", "O_PLUS", "O_TIMES",
  "O_IDENTIFER", "O_MOD", "O_RETURN", "O_CHAR", "O_STRING", "O_INT",
  "O_FLOATCON", "O_MINUS", "O_CASE", "$accept", "program", "decls",
  "decl_list", "identifier_list", "type", "standard_type", "array_type",
  "dim", "subprogram_decls", "subprogram_decl", "subprogram_head",
  "arguments", "parameter_list", "stmt", "assignment", "if_stmt",
  "restricted_stmt", "while_stmt", "procedure_invocation", "i_o_stmt",
  "compound_stmt", "stmt_list", "return_stmt", "case_stmt", "cases",
  "case_element", "case_labels", "expr_list", "expr", "simple_expr",
  "add_expr", "mul_expr", "factor", "variable", "addop", "mulop", "relop",
  "logop", "identifier", "intnum", "char_const", "string_constant",
  "constant", "identifier_list_colon", "id_s", "semicln", "comma", "colon", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,     1,     2,     3,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51
};
# endif

#define YYPACT_NINF -129

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-129)))

#define YYTABLE_NINF -48

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      10,     5,    79,  -129,    93,    94,  -129,  -129,  -129,    52,
       5,     5,     5,   203,   203,    93,    29,  -129,   144,    48,
     144,    91,   144,   144,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,    23,  -129,  -129,   112,   -12,   -10,   105,     5,    74,
    -129,   266,   203,  -129,    93,  -129,  -129,   128,  -129,   219,
     144,  -129,  -129,  -129,  -129,   119,   253,   -16,   166,  -129,
    -129,  -129,  -129,     5,   100,   193,    81,   158,  -129,    52,
     144,   144,   215,  -129,     5,   104,   157,    93,  -129,   266,
    -129,     5,  -129,   125,  -129,  -129,  -129,    93,  -129,  -129,
    -129,  -129,  -129,   253,    30,  -129,  -129,   200,   219,  -129,
    -129,  -129,  -129,  -129,  -129,   219,  -129,  -129,   219,  -129,
    -129,   219,   126,   138,   205,  -129,    85,   140,    32,  -129,
      81,    15,  -129,   116,    81,     4,   266,   157,    93,  -129,
      93,  -129,    70,  -129,  -129,   144,  -129,   177,   191,   207,
     217,   223,   225,   226,   227,   253,   -16,   166,  -129,  -129,
     144,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,    50,  -129,   182,  -129,  -129,  -129,   144,  -129,
       5,  -129,    93,  -129,  -129,  -129,   198,   197,   204,   134,
      52,   210,  -129,   146,    52,   146,    81,   266,  -129,   232,
     199,   206,   200,  -129,   205,  -129,  -129,  -129,  -129,   157,
    -129,  -129,   242,   248,  -129,   200,   205,  -129
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    96,     0,     0,     1,   104,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     0,     0,
       0,     0,     0,     0,    56,    30,    31,    32,    33,    34,
      35,     0,    36,    37,     0,    82,     0,     0,     6,     0,
       9,     0,     0,     3,     0,     4,    20,     0,    22,     0,
       0,    98,   101,   100,    81,     0,    68,    71,    73,    75,
      77,    79,    78,     0,     0,     0,    58,     0,    55,     0,
       0,     0,     0,   106,     0,     0,     0,     0,    26,     0,
     105,     0,   102,     0,    15,    14,    13,     0,    11,    12,
       2,    19,    21,    70,     0,    94,    95,     0,     0,    88,
      89,    90,    91,    92,    93,     0,    84,    85,     0,    86,
      87,     0,     0,    82,     0,    99,     0,     0,     0,    57,
      38,     0,    50,     0,    66,     0,     0,     0,     0,    25,
       0,    10,     0,     7,    80,     0,    40,    30,     0,    32,
      33,    34,    35,    36,    37,    69,    72,    74,    76,    52,
       0,    41,    49,    42,    44,    43,    45,    46,    47,    53,
      54,    60,     0,    61,     0,    64,    83,    51,     0,    27,
       0,    28,     0,    24,     8,    97,     0,     0,     0,     0,
       0,     0,    59,     0,     0,     0,    67,     0,    23,     0,
       0,     0,     0,    39,     0,    62,    63,    65,    29,     0,
      17,    18,     0,     0,    16,     0,     0,    48
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -129,  -129,   244,  -129,  -129,   -64,   -73,  -129,  -129,   254,
       3,  -129,   224,  -129,    -3,   -92,  -129,   -45,   -74,    -2,
     -46,    -5,  -129,   -41,   -37,  -129,    88,  -129,  -129,    71,
     -33,   168,   167,   163,    -8,  -129,  -129,  -129,  -129,     9,
      87,  -128,  -129,  -105,   -36,  -129,    -1,   155,   -27
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    13,    38,    39,    87,    88,    89,   176,    14,
      15,    16,    75,   125,   136,    25,    26,   207,    27,    54,
      29,    30,    31,    32,    33,   162,   163,   164,   123,    55,
      56,    57,    58,    59,    60,   108,   111,   105,    98,    35,
     177,    61,   117,    62,    41,     5,     8,    81,    76
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,    34,    79,   128,   178,   137,    24,    28,    43,    45,
       4,    48,    82,   165,    46,   130,    93,    44,    95,    36,
      37,    40,   151,   139,    73,    71,   106,    72,     1,    74,
      69,    96,    68,    95,     9,   107,    78,    90,   126,     7,
     153,   161,    92,    91,   169,    44,    96,    40,   127,     3,
      12,   141,   138,   166,   172,   112,   143,     9,     7,   182,
     144,    34,   171,   201,    18,   145,   119,    28,   155,   152,
     134,    19,   113,   157,    20,    21,   129,   158,   165,     6,
     197,    52,    53,    40,    95,   183,   133,    63,    95,    34,
     131,    64,   142,    66,    67,   140,     3,    96,    22,     9,
     137,    96,   151,    95,    23,    10,    34,   114,    73,   156,
      80,    11,   154,   137,   151,    12,    96,    51,   139,   175,
     153,    94,    95,   198,   170,   159,   204,   173,     7,   174,
      65,   139,   153,     9,   187,    96,   116,    95,    73,    97,
       7,   120,   121,   124,    74,    70,   141,   202,   155,   203,
      96,   143,    80,   157,   192,   144,   167,   158,    49,   141,
     155,    95,   132,    84,   143,   157,   149,    85,   144,   158,
      86,   188,    34,   118,    96,    71,    34,   193,    28,    40,
     160,   196,    28,    50,    34,   -41,    34,   142,     3,   156,
     140,    51,   154,    52,    53,    52,    53,    34,    34,   180,
     142,   156,   193,   140,   154,     9,   179,    49,     9,   109,
       9,   110,   135,    95,    10,   -42,   184,   150,   185,    19,
      11,   181,    20,    21,    19,   -44,    96,    20,    21,    49,
     194,   -43,    50,   -45,   -46,   -47,   189,     3,   190,   186,
      51,   115,    52,    53,     3,   191,    22,   199,   175,     3,
     205,    22,    23,    51,    50,   122,   206,    23,    50,     3,
      47,    77,    51,     3,    52,    53,    51,    42,    52,    53,
      83,   195,    84,   146,   148,   147,    85,   200,   168,    86,
      99,   100,   101,   102,   103,   104
};

static const yytype_uint8 yycheck[] =
{
       5,     9,    38,    76,   132,    97,     9,     9,    13,    14,
       1,    16,    39,   118,    15,    79,    49,    14,     3,    10,
      11,    12,   114,    97,    34,    37,    42,    39,    18,    39,
      31,    16,     9,     3,     5,    51,    37,    42,    74,    35,
     114,     9,    47,    44,    40,    42,    16,    38,    75,    44,
      21,    97,    97,    38,   127,    63,    97,     5,    35,     9,
      97,    69,   126,   191,    12,    98,    69,    69,   114,   114,
      40,    19,    63,   114,    22,    23,    77,   114,   183,     0,
     185,    49,    50,    74,     3,    35,    87,    39,     3,    97,
      81,    20,    97,    22,    23,    97,    44,    16,    46,     5,
     192,    16,   194,     3,    52,    11,   114,     7,    34,   114,
      36,    17,   114,   205,   206,    21,    16,    47,   192,    49,
     194,    50,     3,   187,   125,    40,   199,   128,    35,   130,
      39,   205,   206,     5,   170,    16,    65,     3,    34,    20,
      35,    70,    71,    72,    39,    33,   192,   192,   194,   194,
      16,   192,    36,   194,    20,   192,    40,   194,    14,   205,
     206,     3,    37,     6,   205,   206,    40,    10,   205,   206,
      13,   172,   180,    15,    16,    37,   184,   180,   180,   170,
      40,   184,   184,    39,   192,     8,   194,   192,    44,   194,
     192,    47,   194,    49,    50,    49,    50,   205,   206,     8,
     205,   206,   205,   205,   206,     5,   135,    14,     5,    43,
       5,    45,    12,     3,    11,     8,    34,    12,    36,    19,
      17,   150,    22,    23,    19,     8,    16,    22,    23,    14,
      20,     8,    39,     8,     8,     8,    38,    44,    41,   168,
      47,    48,    49,    50,    44,    41,    46,    15,    49,    44,
       8,    46,    52,    47,    39,    40,     8,    52,    39,    44,
      16,    37,    47,    44,    49,    50,    47,    13,    49,    50,
       4,   183,     6,   105,   111,   108,    10,   190,   123,    13,
      27,    28,    29,    30,    31,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    54,    44,    92,    98,     0,    35,    99,     5,
      11,    17,    21,    55,    62,    63,    64,    74,    12,    19,
      22,    23,    46,    52,    67,    68,    69,    71,    72,    73,
      74,    75,    76,    77,    87,    92,    92,    92,    56,    57,
      92,    97,    62,    74,    63,    74,    99,    55,    74,    14,
      39,    47,    49,    50,    72,    82,    83,    84,    85,    86,
      87,    94,    96,    39,    82,    39,    82,    82,     9,    99,
      33,    37,    39,    34,    39,    65,   101,    65,    99,    97,
      36,   100,   101,     4,     6,    10,    13,    58,    59,    60,
      74,    99,    74,    83,    82,     3,    16,    20,    91,    27,
      28,    29,    30,    31,    32,    90,    42,    51,    88,    43,
      45,    89,    87,    92,     7,    48,    82,    95,    15,    67,
      82,    82,    40,    81,    82,    66,    97,   101,    59,    99,
      58,    92,    37,    99,    40,    12,    67,    68,    70,    71,
      72,    73,    74,    76,    77,    83,    84,    85,    86,    40,
      12,    68,    70,    71,    72,    73,    74,    76,    77,    40,
      40,     9,    78,    79,    80,    96,    38,    40,   100,    40,
      99,    58,    59,    99,    99,    49,    61,    93,    94,    82,
       8,    82,     9,    35,    34,    36,    82,    97,    99,    38,
      41,    41,    20,    67,    20,    79,    67,    96,    58,    15,
      93,    94,    70,    70,    59,     8,     8,    70
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    54,    54,    55,    56,    56,    57,
      57,    58,    58,    59,    59,    59,    60,    61,    61,    62,
      62,    63,    63,    64,    64,    64,    64,    65,    66,    66,
      67,    67,    67,    67,    67,    67,    67,    67,    68,    69,
      69,    70,    70,    70,    70,    70,    70,    70,    70,    71,
      72,    72,    73,    73,    73,    74,    75,    75,    76,    77,
      77,    78,    78,    79,    80,    80,    81,    81,    82,    82,
      82,    83,    83,    84,    84,    85,    85,    86,    86,    86,
      86,    86,    87,    87,    88,    88,    89,    89,    90,    90,
      90,    90,    90,    90,    91,    91,    92,    93,    94,    95,
      96,    96,    97,    98,    99,   100,   101
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     4,     3,     2,     3,     4,     1,
       3,     1,     1,     1,     1,     1,     6,     3,     3,     3,
       2,     3,     2,     6,     5,     4,     3,     3,     2,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     6,
       4,     1,     1,     1,     1,     1,     1,     1,     6,     4,
       3,     4,     4,     4,     4,     3,     1,     3,     2,     5,
       4,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       2,     1,     3,     1,     3,     1,     3,     1,     1,     1,
       3,     1,     1,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     1,     1
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
        case 2:
#line 104 "nolife_parser.y" /* yacc.c:1646  */
    {
        std::cout << "Done\n";
    }
#line 1451 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 107 "nolife_parser.y" /* yacc.c:1646  */
    { 
        std::cout << "Done\n";
    }
#line 1459 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 110 "nolife_parser.y" /* yacc.c:1646  */
    { 
        std::cout << "Done\n";
    }
#line 1467 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 113 "nolife_parser.y" /* yacc.c:1646  */
    { 
        std::cout << "Done\n";

        gASTRoot = ast::Program((yyvsp[-1].symbol), nullptr, nullptr);
    }
#line 1477 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 121 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "decls\n";}
#line 1483 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 125 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "decl_list\n";}
#line 1489 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 127 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "decl_list\n";}
#line 1495 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 132 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "identifier_list\n";}
#line 1501 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 134 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "identifier_list\n";}
#line 1507 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 138 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "type\n";}
#line 1513 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 140 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "type\n";}
#line 1519 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 144 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "standard_type\n";}
#line 1525 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 146 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "standard_type\n";}
#line 1531 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 148 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "standard_type\n";}
#line 1537 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 152 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "array_type\n";}
#line 1543 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 156 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "dim\n";}
#line 1549 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 158 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "dim\n";}
#line 1555 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 162 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "subprogram_decls\n";}
#line 1561 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 164 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "subprogram_decls\n";}
#line 1567 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 168 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "subprogram_decl\n";}
#line 1573 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 170 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "subprogram_decl\n";}
#line 1579 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 174 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "subprogram_head\n";}
#line 1585 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 176 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "subprogram_head\n";}
#line 1591 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 178 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "subprogram_head\n";}
#line 1597 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 180 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "subprogram_head\n";}
#line 1603 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 184 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "arguments\n";}
#line 1609 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 188 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "parameter_list\n";}
#line 1615 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 190 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "parameter_list\n";}
#line 1621 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 194 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "stmt\n";}
#line 1627 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 196 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "stmt\n";}
#line 1633 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 198 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "stmt\n";}
#line 1639 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 200 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "stmt\n";}
#line 1645 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 202 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "stmt\n";}
#line 1651 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 204 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "stmt\n";}
#line 1657 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 206 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "stmt\n";}
#line 1663 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 208 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "stmt\n";}
#line 1669 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 212 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "assignment\n";}
#line 1675 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 216 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "if_stmt\n";}
#line 1681 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 218 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "if_stmt\n";}
#line 1687 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 222 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "restricted_stmt\n";}
#line 1693 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 224 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "restricted_stmt\n";}
#line 1699 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 226 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "restricted_stmt\n";}
#line 1705 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 228 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "restricted_stmt\n";}
#line 1711 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 230 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "restricted_stmt\n";}
#line 1717 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 232 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "restricted_stmt\n";}
#line 1723 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 234 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "restricted_stmt\n";}
#line 1729 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 236 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "restricted_stmt\n";}
#line 1735 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 240 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "while_stmt\n";}
#line 1741 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 245 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "procedure_invocation\n";}
#line 1747 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 247 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "procedure_invocation\n";}
#line 1753 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 251 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "io_stmt\n";}
#line 1759 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 253 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "io_stmt\n";}
#line 1765 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 255 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "io_stmt\n";}
#line 1771 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 259 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "compound_stmt\n";}
#line 1777 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 263 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "stmt_list\n";}
#line 1783 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 265 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "stmt_list\n";}
#line 1789 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 269 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "return_stmt\n";}
#line 1795 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 273 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "case_stmt";}
#line 1801 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 275 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "case_stmt";}
#line 1807 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 279 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "cases\n";}
#line 1813 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 281 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "cases\n";}
#line 1819 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 285 "nolife_parser.y" /* yacc.c:1646  */
    {std::cout << "case_element\n";}
#line 1825 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 289 "nolife_parser.y" /* yacc.c:1646  */
    {std::cout << "case_element\n";}
#line 1831 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 291 "nolife_parser.y" /* yacc.c:1646  */
    {std::cout << "case_element\n";}
#line 1837 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 295 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "expr_list\n";}
#line 1843 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 297 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "expr_list\n";}
#line 1849 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 301 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "expr\n";}
#line 1855 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 303 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "expr\n";}
#line 1861 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 305 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "expr\n";}
#line 1867 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 309 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "simple_expr\n";}
#line 1873 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 311 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "simple_expr\n";}
#line 1879 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 315 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "add_expr\n";}
#line 1885 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 317 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "add_expr\n";}
#line 1891 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 321 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "mul_expr\n";}
#line 1897 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 323 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "mul_expr\n";}
#line 1903 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 327 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "factor\n";}
#line 1909 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 329 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "factor\n";}
#line 1915 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 331 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "factor\n";}
#line 1921 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 333 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "factor\n";}
#line 1927 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 335 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "factor\n";}
#line 1933 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 339 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "variable\n";}
#line 1939 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 341 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "variable\n";}
#line 1945 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 345 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "addop\n";}
#line 1951 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 347 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "addop\n";}
#line 1957 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 351 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "mulop\n";}
#line 1963 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 353 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "mulop\n";}
#line 1969 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 357 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "relop\n";}
#line 1975 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 359 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "relop\n";}
#line 1981 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 361 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "relop\n";}
#line 1987 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 363 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "relop\n";}
#line 1993 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 365 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "relop\n";}
#line 1999 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 367 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "relop\n";}
#line 2005 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 371 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "logop\n";}
#line 2011 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 373 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "logop\n";}
#line 2017 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 376 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "identifier\n";
    (yyval.symbol) = new ast::Symbol(yytext);
}
#line 2026 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 382 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "intnum\n";}
#line 2032 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 386 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "char_const\n";}
#line 2038 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 390 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "string_constant\n";}
#line 2044 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 394 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "constant\n";}
#line 2050 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 396 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "constant\n";}
#line 2056 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 399 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "identifier_list_colon\n";
}
#line 2064 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 403 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "id_s\n";
    (yyval.symbol) = (yyvsp[-1].symbol);
}
#line 2073 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 409 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "semicln\n";}
#line 2079 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 413 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "comma\n";}
#line 2085 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 417 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "colon\n";}
#line 2091 "nolife_parser.cpp" /* yacc.c:1646  */
    break;


#line 2095 "nolife_parser.cpp" /* yacc.c:1646  */
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
#line 419 "nolife_parser.y" /* yacc.c:1906  */


/********************C ROUTINES *********************************/
int yyerror(const char *s)
{
  std::cout << "Parse error: %s\n",s;
}

/******************END OF C ROUTINES**********************/










