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
#include <memory>

#include "astnode.hpp"
#include "astprognode.hpp"
#include "astparamnode.hpp"
#include "astsymnode.hpp"
#include "astdeclnode.hpp"
#include "astcompoundstmtnode.hpp"
#include "astassignnode.hpp"

ast::Base gASTRoot = ast::Base();

int errcount=0;
int yyerror(const char *s);

/*********************EXTERNAL DECLARATIONS***********************/

extern char* yytext;
extern FILE  *yyin;
extern int yylex();


#line 93 "nolife_parser.cpp" /* yacc.c:339  */

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
#line 34 "nolife_parser.y" /* yacc.c:355  */

#include <string>
#include <vector>
#include "astsymnode.hpp"
#include "asttypenode.hpp"
#include "astdeclnode.hpp"
#include "astprocnode.hpp"

#include "astbinarynode.hpp"
#include "aststmtnode.hpp"
#include "astcompoundstmtnode.hpp"
#include "astassignnode.hpp"
#include "astexpressionnode.hpp"
#include "astcallnode.hpp"
#include "astvariablenode.hpp"
#include "astarrayaccessnode.hpp"
#include "astconstantnode.hpp"
#include "astreturnnode.hpp"

#line 143 "nolife_parser.cpp" /* yacc.c:355  */

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
#line 54 "nolife_parser.y" /* yacc.c:355  */

    int integer;
    ast::Symbol* symbol;
    ast::Type* type;
    ast::Declaration* declaration;
    ast::Statement* statement;
    ast::CompoundStatement* compoundstatement;
    ast::Assignment* assignment;
    ast::Expression* expression;
    ast::Call* call;
    ast::Variable* variable;
    ast::Constant* constant;
    ast::Return* rtrn;

    std::vector<ast::Type*>* typeList;
    std::vector<ast::Symbol*>* symbList;
    std::vector<ast::Statement*>* stmtList;
    std::vector<ast::Expression*>* exprList;

#line 228 "nolife_parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_NOLIFE_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 245 "nolife_parser.cpp" /* yacc.c:358  */

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
#define YYLAST   207

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  184

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
       0,   178,   178,   192,   197,   202,   209,   222,   236,   250,
     257,   263,   268,   273,   277,   281,   286,   290,   292,   296,
     304,   314,   332,   349,   353,   368,   372,   377,   383,   386,
     390,   394,   396,   398,   402,   404,   408,   412,   416,   423,
     425,   429,   433,   437,   451,   453,   455,   459,   476,   486,
     494,   499,   501,   505,   507,   511,   515,   517,   521,   530,
     538,   542,   548,   557,   561,   568,   572,   579,   583,   590,
     594,   598,   602,   606,   611,   615,   620,   624,   629,   633,
     638,   642,   646,   650,   654,   658,   663,   667,   672,   677,
     681,   686,   691,   695,   700,   705,   709,   713
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
  "while_stmt", "procedure_invocation", "i_o_stmt", "compound_stmt",
  "stmt_list", "return_stmt", "case_stmt", "cases", "case_element",
  "case_labels", "expr_list", "expr", "rel_expr", "add_expr", "mul_expr",
  "factor", "variable", "addop", "mulop", "relop", "logop", "identifier",
  "intnum", "char_const", "string_constant", "constant", "id_s", "semicln",
  "comma", "colon", YY_NULLPTR
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

#define YYPACT_NINF -135

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-135)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       8,    18,    79,  -135,    85,    90,  -135,  -135,  -135,    80,
      18,    18,    18,   101,   101,    85,    26,  -135,    44,   125,
      44,   144,    44,    44,  -135,  -135,  -135,  -135,  -135,  -135,
    -135,     7,  -135,  -135,    96,    -2,   123,   143,    18,    42,
    -135,   101,  -135,    85,  -135,  -135,   166,  -135,   130,    44,
    -135,  -135,  -135,  -135,    84,   115,   -19,    78,  -135,  -135,
    -135,  -135,    18,    22,   111,    93,    74,  -135,    80,    44,
      44,   126,  -135,    18,   153,    61,    85,  -135,    42,  -135,
      18,   124,  -135,  -135,  -135,  -135,    12,  -135,  -135,    80,
     130,  -135,  -135,  -135,  -135,  -135,  -135,   130,  -135,  -135,
     130,  -135,  -135,   130,   148,   152,    80,  -135,    17,   150,
       1,  -135,    93,    70,  -135,   145,    93,    42,   132,    61,
    -135,  -135,  -135,    85,  -135,   124,  -135,   154,    85,  -135,
    -135,  -135,   184,   115,   -19,    78,  -135,  -135,  -135,  -135,
    -135,  -135,    34,  -135,   120,  -135,  -135,  -135,    44,   124,
    -135,    18,    85,  -135,    85,   137,  -135,    80,  -135,    64,
      80,    64,    93,  -135,    42,  -135,  -135,  -135,   155,   156,
     157,  -135,  -135,  -135,  -135,   124,   179,   146,   149,  -135,
      61,  -135,  -135,  -135
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    88,     0,     0,     1,    95,    94,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     0,     0,
       0,     0,     0,     0,    48,    30,    31,    32,    33,    34,
      35,     0,    36,    37,     0,    74,     0,     0,     6,     0,
       9,     0,     3,     0,     4,    20,     0,    22,     0,     0,
      90,    93,    92,    73,     0,    60,    63,    65,    67,    69,
      71,    70,     0,     0,     0,    50,     0,    47,     0,     0,
       0,     0,    97,     0,     0,     0,     0,    26,     0,    96,
       0,     0,     2,    19,    21,    62,     0,    86,    87,     0,
       0,    80,    81,    82,    83,    84,    85,     0,    76,    77,
       0,    78,    79,     0,     0,    74,     0,    91,     0,     0,
       0,    49,    38,     0,    42,     0,    58,     0,     0,     0,
      15,    14,    13,     0,    25,     0,    10,     0,     0,    11,
      12,    72,    40,    61,    64,    66,    68,    44,    41,    45,
      46,    52,     0,    53,     0,    56,    75,    43,     0,     0,
      27,     0,     0,    24,     0,     0,     7,     0,    51,     0,
       0,     0,    59,    28,     0,    23,     8,    89,     0,     0,
       0,    39,    54,    55,    57,     0,     0,     0,     0,    29,
       0,    17,    18,    16
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -135,  -135,   183,  -135,   -34,  -103,   -58,  -135,  -135,   187,
      -5,  -135,   164,  -135,   -41,  -135,  -135,  -135,    -8,  -135,
     122,  -135,  -135,  -135,  -135,    43,  -135,  -135,   -15,   113,
     107,   105,   -37,    -9,  -135,  -135,  -135,  -135,     2,    29,
    -134,  -135,   -91,  -135,   -13,    92,   -33
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    13,    38,    39,   128,   129,   130,   168,    14,
      15,    16,    74,   118,    24,    25,    26,    27,    53,    29,
      30,    31,    32,    33,   142,   143,   144,   115,    54,    55,
      56,    57,    58,    59,   100,   103,    97,    90,    35,   169,
      60,   109,    61,     5,     8,    80,    75
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      34,    28,    45,     4,    78,    63,    81,    65,    66,    43,
     141,    85,    36,    37,    40,    87,    67,   123,    68,   145,
      87,   170,   154,    98,    77,    87,     1,   111,    88,   106,
      83,     9,    99,    88,    86,    70,    43,    71,    88,   117,
      40,   119,     7,   158,   182,   125,   163,    12,   132,   108,
      51,    52,   131,   104,   112,   113,   116,   139,    48,    34,
      28,   152,     3,   124,   105,   138,   136,   120,   145,   159,
     174,   121,   179,    87,   122,    40,    72,    87,    79,     6,
      34,    28,   126,    49,   149,     9,    88,    87,     3,   110,
      88,    50,    18,    51,    52,     9,    87,    34,    28,    19,
      88,    10,    20,    21,    89,   151,     9,    11,   146,    88,
     153,    12,    10,    51,    52,   156,   171,   164,    11,   173,
       7,   101,   183,   102,     3,    48,    22,    17,   127,    69,
     120,   175,    23,   162,   121,    42,    44,   122,    47,   165,
      48,   166,    91,    92,    93,    94,    95,    96,    34,    28,
      49,    34,    28,    40,   160,     3,   161,    72,    50,   107,
      51,    52,    73,    82,    62,    49,   114,     7,    84,    49,
       3,     9,   150,    50,     3,    51,    52,    50,     7,    51,
      52,    79,    73,    64,    50,   147,   167,    72,   137,    70,
     140,   155,   157,   176,   180,   167,    50,   177,   178,    46,
      41,    76,   172,   133,   134,   135,   181,   148
};

static const yytype_uint8 yycheck[] =
{
       9,     9,    15,     1,    38,    20,    39,    22,    23,    14,
       9,    48,    10,    11,    12,     3,     9,    75,    31,   110,
       3,   155,   125,    42,    37,     3,    18,    68,    16,     7,
      43,     5,    51,    16,    49,    37,    41,    39,    16,    73,
      38,    74,    35,     9,   178,    78,   149,    21,    89,    64,
      49,    50,    40,    62,    69,    70,    71,    40,    14,    68,
      68,   119,    44,    76,    62,   106,   103,     6,   159,    35,
     161,    10,   175,     3,    13,    73,    34,     3,    36,     0,
      89,    89,    80,    39,   117,     5,    16,     3,    44,    15,
      16,    47,    12,    49,    50,     5,     3,   106,   106,    19,
      16,    11,    22,    23,    20,   118,     5,    17,    38,    16,
     123,    21,    11,    49,    50,   128,   157,   151,    17,   160,
      35,    43,   180,    45,    44,    14,    46,     5,     4,    33,
       6,   164,    52,   148,    10,    13,    14,    13,    16,   152,
      14,   154,    27,    28,    29,    30,    31,    32,   157,   157,
      39,   160,   160,   151,    34,    44,    36,    34,    47,    48,
      49,    50,    39,    41,    39,    39,    40,    35,    46,    39,
      44,     5,    40,    47,    44,    49,    50,    47,    35,    49,
      50,    36,    39,    39,    47,    40,    49,    34,    40,    37,
      40,    37,     8,    38,    15,    49,    47,    41,    41,    16,
      13,    37,   159,    90,    97,   100,   177,   115
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    54,    44,    91,    96,     0,    35,    97,     5,
      11,    17,    21,    55,    62,    63,    64,    73,    12,    19,
      22,    23,    46,    52,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    86,    91,    91,    91,    56,    57,
      91,    62,    73,    63,    73,    97,    55,    73,    14,    39,
      47,    49,    50,    71,    81,    82,    83,    84,    85,    86,
      93,    95,    39,    81,    39,    81,    81,     9,    97,    33,
      37,    39,    34,    39,    65,    99,    65,    97,    57,    36,
      98,    99,    73,    97,    73,    85,    81,     3,    16,    20,
      90,    27,    28,    29,    30,    31,    32,    89,    42,    51,
      87,    43,    45,    88,    86,    91,     7,    48,    81,    94,
      15,    67,    81,    81,    40,    80,    81,    57,    66,    99,
       6,    10,    13,    59,    97,    99,    91,     4,    58,    59,
      60,    40,    67,    82,    83,    84,    85,    40,    67,    40,
      40,     9,    77,    78,    79,    95,    38,    40,    98,    99,
      40,    97,    59,    97,    58,    37,    97,     8,     9,    35,
      34,    36,    81,    58,    57,    97,    97,    49,    61,    92,
      93,    67,    78,    67,    95,    99,    38,    41,    41,    58,
      15,    92,    93,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    54,    54,    55,    56,    56,    57,
      57,    58,    58,    59,    59,    59,    60,    61,    61,    62,
      62,    63,    63,    64,    64,    64,    64,    65,    66,    66,
      67,    67,    67,    67,    67,    67,    67,    67,    68,    69,
      69,    70,    71,    71,    72,    72,    72,    73,    74,    74,
      75,    76,    76,    77,    77,    78,    79,    79,    80,    80,
      81,    81,    81,    82,    82,    83,    83,    84,    84,    85,
      85,    85,    85,    85,    86,    86,    87,    87,    88,    88,
      89,    89,    89,    89,    89,    89,    90,    90,    91,    92,
      93,    94,    95,    95,    96,    97,    98,    99
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     4,     3,     2,     4,     5,     1,
       3,     1,     1,     1,     1,     1,     6,     3,     3,     3,
       2,     3,     2,     6,     5,     4,     3,     3,     3,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     6,
       4,     4,     3,     4,     4,     4,     4,     3,     1,     3,
       2,     5,     4,     1,     3,     3,     1,     3,     1,     3,
       1,     3,     2,     1,     3,     1,     3,     1,     3,     1,
       1,     1,     3,     1,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1
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
#line 178 "nolife_parser.y" /* yacc.c:1646  */
    {
        std::cout << "Done (id_s decls sub_decls compound_stmt)\n";

        // combine decls with subprogram_decls
        for (auto typeNode : (yyvsp[-1].declaration)->getChildren()) {
            (yyvsp[-2].declaration)->addChild(typeNode);
        }

        // delete subprogram_decls, since we saved its children

        delete (yyvsp[-1].declaration);

        gASTRoot = ast::Program((yyvsp[-3].symbol), (yyvsp[-2].declaration), (yyvsp[0].compoundstatement));
    }
#line 1473 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 192 "nolife_parser.y" /* yacc.c:1646  */
    { 
        std::cout << "Done (id_s decls compound_stmt)\n";

        gASTRoot = ast::Program((yyvsp[-2].symbol), (yyvsp[-1].declaration), (yyvsp[0].compoundstatement));
    }
#line 1483 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 197 "nolife_parser.y" /* yacc.c:1646  */
    { 
        std::cout << "Done (id_s sub_decls compound_stmt)\n";

        gASTRoot = ast::Program((yyvsp[-2].symbol), (yyvsp[-1].declaration), (yyvsp[0].compoundstatement));
    }
#line 1493 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 202 "nolife_parser.y" /* yacc.c:1646  */
    { 
        std::cout << "Done\n (compound_stmt)";

        gASTRoot = ast::Program((yyvsp[-1].symbol), nullptr, (yyvsp[0].compoundstatement));
    }
#line 1503 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 209 "nolife_parser.y" /* yacc.c:1646  */
    { 
    // returns a declaration (ast::Declaration)
    std::cout << "decls\n";
    auto declNode = new ast::Declaration();
    for (auto type : *(yyvsp[0].typeList)) {
        declNode->addChild(type);
    }

    delete (yyvsp[0].typeList); // delete vector of type node pointers (decl_list)

    (yyval.declaration) = declNode;
}
#line 1520 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 222 "nolife_parser.y" /* yacc.c:1646  */
    { 
    // returns typeList (std::vector<ast::Type*>*)
    std::cout << "decl_list (single)\n";
    auto typeList = new std::vector<ast::Type*>();
    for (auto sym : *(yyvsp[-3].symbList)) { // for each symbol node in the identifier_list
        auto newType = (yyvsp[-1].type)->clone();
        newType->addChild(sym);
        typeList->push_back(newType);
    }

    delete (yyvsp[-1].type); // delete the original type node, since we cloned it

    (yyval.typeList) = typeList;
}
#line 1539 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 236 "nolife_parser.y" /* yacc.c:1646  */
    { 
    // returns typeList (std::vector<ast::Type*>*)
    std::cout << "decl_list (recursive, )\n";
    for (auto sym : *(yyvsp[-3].symbList)) { // for each symbol node in the identifier_list
        auto newType = (yyvsp[-1].type)->clone();
        newType->addChild(sym);
        (yyvsp[-4].typeList)->push_back(newType);
    }

    delete (yyvsp[-1].type); // delete the original type node, since we cloned it

    (yyval.typeList) = (yyvsp[-4].typeList);
}
#line 1557 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 250 "nolife_parser.y" /* yacc.c:1646  */
    { 
    // returns symbList std::vector<ast::Symbol*>*)
    std::cout << "identifier_list (single)\n";
    auto symList = new std::vector<ast::Symbol*>();
    symList->push_back((yyvsp[0].symbol));
    (yyval.symbList) = symList;
}
#line 1569 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 257 "nolife_parser.y" /* yacc.c:1646  */
    {
    std::cout << "identifier_list (recursive)\n";
    (yyvsp[-2].symbList)->push_back((yyvsp[0].symbol));
    (yyval.symbList) = (yyvsp[-2].symbList);
}
#line 1579 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 263 "nolife_parser.y" /* yacc.c:1646  */
    {
    // returns a type node (ast::Type)
    std::cout << "type (standard)\n";
    (yyval.type) = (yyvsp[0].type);
}
#line 1589 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 268 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "type (array)\n";
    // $$ = $1;
}
#line 1598 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 273 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "standard_type\n";
    (yyval.type) = new ast::Integer();
}
#line 1607 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 277 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "standard_type\n";
    (yyval.type) = new ast::Float();
}
#line 1616 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 281 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "standard_type\n";
    (yyval.type) = new ast::Character();
}
#line 1625 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 287 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "array_type\n";}
#line 1631 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 291 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "dim\n";}
#line 1637 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 293 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "dim\n";}
#line 1643 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 296 "nolife_parser.y" /* yacc.c:1646  */
    { 
    // returns a declaration (ast::Declaration)
    std::cout << "subprogram_decls\n";

    (yyvsp[-2].declaration)->addChild((yyvsp[-1].type));

    (yyval.declaration) = (yyvsp[-2].declaration);
}
#line 1656 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 304 "nolife_parser.y" /* yacc.c:1646  */
    { 
    // returns a declaration (ast::Declaration)
    std::cout << "subprogram_decls\n";

    auto declNode = new ast::Declaration();
    declNode->addChild((yyvsp[-1].type));

    (yyval.declaration) = declNode;
}
#line 1670 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 314 "nolife_parser.y" /* yacc.c:1646  */
    { 
    // returns a type node (ast::Type)
    std::cout << "subprogram_decl\n";

    // get func node from type node
    // since subprogram_head returns a type node with a func node attached to it
    auto funcNode_base = (yyvsp[-2].type)->getChildren()[0]; // this gets an ast::Base*
    auto funcNode = dynamic_cast<ast::Procedure*>(funcNode_base);

    if (funcNode == nullptr) {
        std::cout << "  Error in subprogram_decl!\n";
    }

    funcNode->setDecl((yyvsp[-1].declaration));
    funcNode->setCompoundStmt((yyvsp[0].compoundstatement));

    (yyval.type) = (yyvsp[-2].type);
}
#line 1693 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 332 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "subprogram_decl\n";

    // get func node from type node
    // since subprogram_head returns a type node with a func node attached to it
    auto funcNode_base = (yyvsp[-1].type)->getChildren()[0]; // this gets an ast::Base*
    auto funcNode = dynamic_cast<ast::Procedure*>(funcNode_base);

    if (funcNode == nullptr) {
        std::cout << "  Error in subprogram_decl!\n";
    }

    funcNode->setCompoundStmt((yyvsp[0].compoundstatement));

    (yyval.type) = (yyvsp[-1].type);
}
#line 1714 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 349 "nolife_parser.y" /* yacc.c:1646  */
    { 
    // returns a type node (ast::Type) that points to a func/proceedure
    std::cout << "subprogram_head\n";
}
#line 1723 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 353 "nolife_parser.y" /* yacc.c:1646  */
    {
    // returns a type node (ast::Type) that points to a func/proceedure
    std::cout << "subprogram_head\n";

    auto func = new ast::Procedure(
        (yyvsp[-3].symbol), // identifier; symbol node
        nullptr, // no parameters
        nullptr, // no declarations available yet
        nullptr // no compound statement available yet
    );

    (yyvsp[-1].type)->setFunc(func);

    (yyval.type) = (yyvsp[-1].type);
}
#line 1743 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 368 "nolife_parser.y" /* yacc.c:1646  */
    {
    // returns a type node (ast::Type) that points to a func/proceedure
    std::cout << "subprogram_head\n";
}
#line 1752 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 372 "nolife_parser.y" /* yacc.c:1646  */
    {
    // returns a type node (ast::Type) that points to a func/proceedure
    std::cout << "subprogram_head\n";
}
#line 1761 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 377 "nolife_parser.y" /* yacc.c:1646  */
    { 
    // returns a parameter node (ast::Parameters)
    std::cout << "arguments\n";
    // $$ = $2;
}
#line 1771 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 385 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "parameter_list\n";}
#line 1777 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 387 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "parameter_list\n";}
#line 1783 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 390 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "stmt (assignment)\n";
    (yyval.statement) = (yyvsp[0].assignment);
}
#line 1792 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 395 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "stmt\n";}
#line 1798 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 397 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "stmt\n";}
#line 1804 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 398 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "stmt (proc invoke)\n";
    // $$ = $1;
}
#line 1813 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 403 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "stmt\n";}
#line 1819 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 404 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "stmt (compound_stmt)\n";
    (yyval.statement) = (yyvsp[0].compoundstatement);
}
#line 1828 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 408 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "stmt (return)\n";
    (yyval.statement) = (yyvsp[0].rtrn);
}
#line 1837 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 413 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "stmt\n";}
#line 1843 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 416 "nolife_parser.y" /* yacc.c:1646  */
    { 
    // returns assignment (ast::Assignement)
    std::cout << "assignment\n";

    (yyval.assignment) = new ast::Assignment((yyvsp[-2].variable), (yyvsp[0].expression));
}
#line 1854 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 424 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "if_stmt\n";}
#line 1860 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 426 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "if_stmt\n";}
#line 1866 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 430 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "while_stmt\n";}
#line 1872 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 433 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "procedure_invocation\n";
    (yyval.call) = new ast::Call((yyvsp[-2].symbol));
}
#line 1881 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 437 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "procedure_invocation\n";
    
    auto callNode = new ast::Call((yyvsp[-3].symbol));

    for (auto expr : *(yyvsp[-1].exprList)) {
        callNode->addChild(expr);
    }

    delete (yyvsp[-1].exprList);

    (yyval.call) = callNode;
}
#line 1899 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 452 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "io_stmt\n";}
#line 1905 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 454 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "io_stmt\n";}
#line 1911 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 456 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "io_stmt\n";}
#line 1917 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 459 "nolife_parser.y" /* yacc.c:1646  */
    { 
    // returns a compoundstatement (ast::CompoundStatement)
    std::cout << "compound_stmt\n";

    auto list = (yyvsp[-1].stmtList);

    auto compoundstmt = new ast::CompoundStatement;

    for (auto stmt : *list) {
        compoundstmt->addChild(stmt);
    }

    delete (yyvsp[-1].stmtList);

    (yyval.compoundstatement) = compoundstmt;
}
#line 1938 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 476 "nolife_parser.y" /* yacc.c:1646  */
    { 
    // returns a stmtList (std::vector<ast::Statement>*)
    std::cout << "stmt_list (single)\n";

    auto list = new std::vector<ast::Statement*>;

    list->push_back((yyvsp[0].statement));

    (yyval.stmtList) = list;
}
#line 1953 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 486 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "stmt_list (recursive)\n";

    (yyvsp[-2].stmtList)->push_back((yyvsp[0].statement));

    (yyval.stmtList) = (yyvsp[-2].stmtList);
}
#line 1965 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 494 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "return_stmt\n";
    (yyval.rtrn) = new ast::Return((yyvsp[0].expression));
}
#line 1974 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 500 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "case_stmt";}
#line 1980 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 502 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "case_stmt";}
#line 1986 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 506 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "cases\n";}
#line 1992 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 508 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "cases\n";}
#line 1998 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 512 "nolife_parser.y" /* yacc.c:1646  */
    {std::cout << "case_element\n";}
#line 2004 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 516 "nolife_parser.y" /* yacc.c:1646  */
    {std::cout << "case_element\n";}
#line 2010 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 518 "nolife_parser.y" /* yacc.c:1646  */
    {std::cout << "case_element\n";}
#line 2016 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 521 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "expr_list (single)\n";

    auto list = new std::vector<ast::Expression*>;

    list->push_back((yyvsp[0].expression));

    (yyval.exprList) = list;
}
#line 2030 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 530 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "expr_list (recursive)\n";

    (yyvsp[-2].exprList)->push_back((yyvsp[0].expression));

    (yyval.exprList) = (yyvsp[-2].exprList);
}
#line 2042 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 538 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "expr\n";
    (yyval.expression) = (yyvsp[0].expression);
}
#line 2051 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 542 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "expr\n";
    (yyvsp[-1].expression)->addChild((yyvsp[-2].expression));
    (yyvsp[-1].expression)->addChild((yyvsp[0].expression));
    (yyval.expression) = (yyvsp[-1].expression);
}
#line 2062 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 548 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "expr\n";
    auto exprNode = new ast::Expression(ast::Expression::Operation::Not);
    exprNode->addChild((yyvsp[0].expression));
    (yyval.expression) = exprNode;
}
#line 2073 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 557 "nolife_parser.y" /* yacc.c:1646  */
    {
    std::cout << "rel_expr\n";
    (yyval.expression) = (yyvsp[0].expression);
}
#line 2082 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 561 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "rel_expr\n";
    (yyvsp[-1].expression)->addChild((yyvsp[-2].expression));
    (yyvsp[-1].expression)->addChild((yyvsp[0].expression));
    (yyval.expression) = (yyvsp[-1].expression);
}
#line 2093 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 568 "nolife_parser.y" /* yacc.c:1646  */
    {
    std::cout << "add_expr\n";
    (yyval.expression) = (yyvsp[0].expression);
}
#line 2102 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 572 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "add_expr\n";
    (yyvsp[-1].expression)->addChild((yyvsp[-2].expression));
    (yyvsp[-1].expression)->addChild((yyvsp[0].expression));
    (yyval.expression) = (yyvsp[-1].expression);
}
#line 2113 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 579 "nolife_parser.y" /* yacc.c:1646  */
    {
    std::cout << "mul_expr\n";
    (yyval.expression) = (yyvsp[0].expression);
}
#line 2122 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 583 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "mul_expr\n";
    (yyvsp[-1].expression)->addChild((yyvsp[-2].expression));
    (yyvsp[-1].expression)->addChild((yyvsp[0].expression));
    (yyval.expression) = (yyvsp[-1].expression);
}
#line 2133 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 590 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "factor\n";
    (yyval.expression) = new ast::Expression((yyvsp[0].variable));
}
#line 2142 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 594 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "factor\n";
    (yyval.expression) = new ast::Expression((yyvsp[0].constant));
}
#line 2151 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 598 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "factor\n";
    (yyval.expression) = new ast::Expression((yyvsp[0].constant));
}
#line 2160 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 602 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "factor\n";
    (yyval.expression) = (yyvsp[-1].expression);
}
#line 2169 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 606 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "factor\n";
    (yyval.expression) = new ast::Expression((yyvsp[0].call));
}
#line 2178 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 611 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "variable\n";
    (yyval.variable) = new ast::Variable((yyvsp[0].symbol));
}
#line 2187 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 615 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "variable\n";
    (yyval.variable) = new ast::ArrayAccess((yyvsp[-3].symbol), (yyvsp[-1].expression));
}
#line 2196 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 620 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "addop\n";
    (yyval.expression) = new ast::Expression(ast::Expression::Operation::Plus);
}
#line 2205 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 624 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "addop\n";
    (yyval.expression) = new ast::Expression(ast::Expression::Operation::Minus);
}
#line 2214 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 629 "nolife_parser.y" /* yacc.c:1646  */
    {
    std::cout << "mulop\n";
    (yyval.expression) = new ast::Expression(ast::Expression::Operation::Multiply);
}
#line 2223 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 633 "nolife_parser.y" /* yacc.c:1646  */
    {
    std::cout << "mulop\n";
    (yyval.expression) = new ast::Expression(ast::Expression::Operation::Modulo);
}
#line 2232 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 638 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "relop\n";
    (yyval.expression) = new ast::Expression(ast::Expression::Operation::LessThanOrEqual);
}
#line 2241 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 642 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "relop\n";
    (yyval.expression) = new ast::Expression(ast::Expression::Operation::LessThan);
}
#line 2250 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 646 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "relop\n";
    (yyval.expression) = new ast::Expression(ast::Expression::Operation::GreaterThanOrEqual);
}
#line 2259 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 650 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "relop\n";
    (yyval.expression) = new ast::Expression(ast::Expression::Operation::GreaterThan);
}
#line 2268 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 654 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "relop\n";
    (yyval.expression) = new ast::Expression(ast::Expression::Operation::Equals);
}
#line 2277 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 658 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "relop\n";
    (yyval.expression) = new ast::Expression(ast::Expression::Operation::NotEqual);
}
#line 2286 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 663 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "logop\n";
    (yyval.expression) = new ast::Expression(ast::Expression::Operation::And);
}
#line 2295 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 667 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "logop\n";
    (yyval.expression) = new ast::Expression(ast::Expression::Operation::Or);
}
#line 2304 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 672 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "identifier (" << yytext << ") \n";
    (yyval.symbol) = new ast::Symbol(yytext);
}
#line 2313 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 678 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "intnum\n";}
#line 2319 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 681 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "char_const" << yytext << "\n";
    (yyval.constant) = new ast::Constant(yytext);
}
#line 2328 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 686 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "string_constant" << yytext << "\n";
    (yyval.constant) = new ast::Constant(yytext);
}
#line 2337 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 691 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "constant" << yytext << "\n";
    (yyval.constant) = new ast::Constant(yytext);
}
#line 2346 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 695 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "constant" << yytext << "\n";
    (yyval.constant) = new ast::Constant(yytext);
}
#line 2355 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 700 "nolife_parser.y" /* yacc.c:1646  */
    { 
    std::cout << "id_s\n";
    (yyval.symbol) = (yyvsp[-1].symbol);
}
#line 2364 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 706 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "semicln\n";}
#line 2370 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 710 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "comma\n";}
#line 2376 "nolife_parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 714 "nolife_parser.y" /* yacc.c:1646  */
    { std::cout << "colon\n";}
#line 2382 "nolife_parser.cpp" /* yacc.c:1646  */
    break;


#line 2386 "nolife_parser.cpp" /* yacc.c:1646  */
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
#line 716 "nolife_parser.y" /* yacc.c:1906  */


/********************C ROUTINES *********************************/

int yyerror(const char *s)
{
  std::cout << "Parse error: " << s << "\n";
}

/******************END OF C ROUTINES**********************/
