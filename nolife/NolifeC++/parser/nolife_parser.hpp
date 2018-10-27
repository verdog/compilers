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
#line 35 "nolife_parser.y" /* yacc.c:1909  */

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
#include "astparamnode.hpp"
#include "astifnode.hpp"
#include "astwhilenode.hpp"
#include "astreadnode.hpp"
#include "astwritenode.hpp"
#include "astcaselabelsnode.hpp"
#include "astclausenode.hpp"
#include "astcasenode.hpp"

#line 72 "nolife_parser.hpp" /* yacc.c:1909  */

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
#line 63 "nolife_parser.y" /* yacc.c:1909  */

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
    ast::Return* _return;
    ast::Parameters* parameters;
    ast::If* _if;
    ast::While* _while;
    ast::Read* read;
    ast::Write* write;
    ast::CaseLabels* caseLabels;
    ast::Clause* clause;
    ast::Case* _case;

    std::vector<ast::Type*>* typeList;
    std::vector<ast::Symbol*>* symbList;
    std::vector<ast::Statement*>* stmtList;
    std::vector<ast::Expression*>* exprList;
    std::vector<ast::Clause*>* clauseList;

#line 166 "nolife_parser.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_NOLIFE_PARSER_HPP_INCLUDED  */
