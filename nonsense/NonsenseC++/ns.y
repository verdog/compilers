%{
   
#include <string>
#include <iostream>
#include <unordered_map>
#include <cmath>

#include "types.hpp"

extern int yylineno;
extern char *yytext;

extern int yylex(void);

int yyerror (std::string msg);

// global symbol table
SymbolTable g_symbol_table;

%}

%start program

%union {
	int val;
	Identifier *identifier;
	Expression *expression;
}

%token <val> O_BEGIN
%token <val> O_END
%token <val> O_EQ
%token <val> O_EXP
%token <val> O_MULT
%token <val> O_MINUS
%token <val> O_SEMI
%token <val> O_DIV
%token <val> O_LPAREN
%token <val> O_RPAREN
%token <val> O_OUTPUT
%token <val> O_IDENTIFIER
%token <val> O_INTEGER
%token <val> O_PLUS

%type <val> integer
%type <expression> expression
%type <identifier> identifier

%left O_PLUS O_MINUS
%left O_MULT O_DIV
%left O_NEG

%right O_EXP

%%

program: 
	O_BEGIN O_SEMI statement_list O_END O_SEMI {;}
|   O_BEGIN O_SEMI O_END O_SEMI {;}

statement_list: 
	statement_list statement {;}
|   statement {;}

statement: 
	assignment O_SEMI {;}
|   output O_SEMI {;}

assignment: identifier O_EQ expression {
	std::cout << "; assignment: " << $1 << " <- " << $3 << std::endl;
}

output: O_OUTPUT O_LPAREN expression O_RPAREN {
	std::cout << "; output: " << $3 << "\n";
	std::cout <<
	"push dword ptr [%ebp-4]\n"
	"push offset flat:.io_format\n"
	"call printf\n"
	"add %esp, 8\n"
	;
}

expression: 
	integer { 
		std::cout << "; expression:integer: " << $1 << "\n";
	}
|   identifier { 
		std::cout << "; expression:integer: " << $1 << "\n";
	}
|   expression O_PLUS expression {  }
|   expression O_MINUS expression {  }
|   expression O_MULT expression {  }
|   expression O_DIV expression {  }
|   O_MINUS expression %prec O_NEG {  }
|   expression O_EXP expression { 
	}
         
identifier: O_IDENTIFIER {
	std::string key = yytext;
	Identifier *id_ptr = g_symbol_table.lookup(key);
	$$ = id_ptr;
	std::cout << "; identifier: " << $$ << "\n";
}

integer: O_INTEGER {
	$$ = yylval.val;
	std::cout << "; integer: " << $$ << "\n";
}

%%

int yyerror(std::string msg) {
   std::cerr << msg << std::endl;
   return 0;
}

void output_header() {
	std::cout <<
	".intel_syntax\n"
	".section .rodata\n"
	".io_format:\n"
	".string \"%d\\12\\0\"\n"
	".text\n"
	".globl main;\n"
	".type main, @function\n"
	"main:\n"
	"push %ebp\n"
	"mov %ebp, %esp\n"
	"sub %esp, 64\n";
}

void output_footer() {
	std::cout <<
	"leave\n"
	"ret\n";
}

main()
{
	output_header();
   	yyparse();
	output_footer();
}