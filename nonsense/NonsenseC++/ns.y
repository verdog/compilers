%{
   
#include <string>
#include <iostream>
#include <unordered_map>
#include <cmath>

#include "types.hpp"

extern int yylineno;
extern char *yytext;
extern FILE* yyin;

extern int yylex(void);

int yyerror (std::string msg);

// global symbol table
SymbolTable g_symbol_table;

// global register manager
RegisterManager g_register_manager;

// global loop manager
LoopManager g_loop_manager;

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

%left O_PAREN

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
	std::cout << "// assignment: " << $1 << " <- " << $3 << std::endl;
	std::string location = $3->location;
	std::cout <<
		"mov %eax, " << location << std::endl <<
		"mov dword ptr [%ebp" << $1->offset << "], %eax" << std::endl
	;

	// clean up
	delete $3;
	g_register_manager.clear_all();
}

output: O_OUTPUT O_LPAREN expression O_RPAREN {
	std::cout << "// output: " << $3 << "\n";
	std::cout <<
	"push " + $3->location + "\n"
	"push offset flat:.io_format\n"
	"call printf\n"
	"add %esp, 8\n"
	;

	// clean up
	delete $3;
	g_register_manager.clear_all();
}

expression: 
	integer { 
		std::cout << "// expression:integer: " << $1 << "\n";
		Expression *val = new Expression;
		val->location = std::to_string($1);
		$$ = val;
	}

|   identifier { 
		std::cout << "// expression:identifier: " << $1 << "\n";
		Expression *val = new Expression;
		val->location = "dword ptr [%ebp" + std::to_string($1->offset) + "]";
		$$ = val;
	}

|   expression O_PLUS expression { 
		std::cout << "// addition: " << $1 << " + " << $3 << std::endl;
		Expression *val = new Expression;
		val->location = g_register_manager.get_free_register();
		std::cout <<
			"mov %eax, " + $1->location + "\n"
			"add %eax, " + $3->location + "\n"
			"mov " + val->location + ", %eax\n"
		;
		$$ = val;

		// clear registers
		g_register_manager.clear_single($1->location);

		//clean up
		delete $1;
		delete $3;
	}

|   expression O_MINUS expression {
		std::cout << "// subtraction: " << $1 << " - " << $3 << std::endl;
		Expression *val = new Expression;
		val->location = g_register_manager.get_free_register();
		std::cout <<
			"mov %eax, " + $1->location + "\n"
			"sub %eax, " + $3->location + "\n"
			"mov " + val->location + ", %eax\n"
		;
		$$ = val;

		// clear registers
		g_register_manager.clear_single($1->location);

		//clean up
		delete $1;
		delete $3;
	}

|   expression O_MULT expression { 
		std::cout << "// mulitplication: " << $1 << " * " << $3 << std::endl; 
		Expression *val = new Expression;
		val->location = g_register_manager.get_free_register();
		std::cout <<
			"mov %eax, " + $1->location + "\n"
			"imul %eax, " + $3->location + "\n"
			"mov " + val->location + ", %eax\n"
		;
		$$ = val;

		// clear registers
		g_register_manager.clear_single($1->location);

		//clean up
		delete $1;
		delete $3;
	}
	
|   expression O_DIV expression { 
		std::cout << "// division: " << $1 << " / " << $3 << std::endl;
		Expression *val = new Expression;
		val->location = g_register_manager.get_free_register();
		std::string math_location = g_register_manager.get_free_register();

		// math location cannot be edx
		if (math_location == "%edx") {
			std::cout << "// /!\\ math_location cannot be %edx\n";
			math_location = g_register_manager.get_free_register();
			g_register_manager.clear_single("%edx");
		}

		std::cout <<
			"mov %eax, " + $1->location + "\n" 
			"mov " + math_location + ", " + $3->location + "\n"
			"cdq\n"
			"idiv " + math_location + "\n"
			"mov " + val->location + ", %eax\n"
		;
		$$ = val;

		// clear registers
		g_register_manager.clear_single($1->location);
		g_register_manager.clear_single($3->location);
		g_register_manager.clear_single(math_location);

		// clean up
		delete $1;
		delete $3;
 	}

|   O_MINUS expression %prec O_NEG { 
		std::cout << "// negative: " << $2 << std::endl;

		Expression *val = new Expression;
		val->location = g_register_manager.get_free_register();

		std::cout <<
			"mov " + val->location + ", " + $2->location + "\n"
			"neg " + val->location + "\n"
		; 
		$$ = val;

		// clean up
		g_register_manager.clear_single($2->location);

		delete $2;
 	}

|   expression O_EXP expression {
		std::cout << "// exponent: " << $1 << " ^ " << $3 << "\n";

		Expression *val = new Expression;

		std::string label_loop = g_loop_manager.generate_unique_label();
		std::string label_end = label_loop + "_end";

		std::string location_base = g_register_manager.get_free_register();
		std::string location_exponent = g_register_manager.get_free_register();

		std::string location_result = g_register_manager.get_free_register();
		val->location = location_result;

		std::cout <<
			"mov %eax, 1\n"
			"mov " + location_base + ", " + $1->location + "\n"
			"mov " + location_exponent + ", " + $3->location + "\n"
			"" + label_loop + ":\n"
			"cmp " + location_exponent + ", 0\n"
			"je " + label_end + "\n"
			"imul " + location_base + "\n"
			"sub " + location_exponent + ", 1\n"
			"jmp " + label_loop + "\n"
			"" + label_end + ":\n"
			"mov " + location_result + ", %eax\n" 
		;

		$$ = val;

		// clean up
		g_register_manager.clear_single($1->location);
		g_register_manager.clear_single($3->location);
		g_register_manager.clear_single(location_base);
		g_register_manager.clear_single(location_exponent);

		delete $1;
		delete $3;
	}

| 	O_LPAREN expression O_RPAREN %prec O_PAREN {
		std::cout << "// expression:parens: " << $2 << "\n"; $$ = $2;
	}
         
identifier: O_IDENTIFIER {
	std::string key = yytext;
	Identifier *id_ptr = g_symbol_table.lookup(key);
	$$ = id_ptr;
	// std::cout << "// identifier: " << $$ << "\n";
}

integer: O_INTEGER {
	$$ = yylval.val;
	// std::cout << "// integer: " << $$ << "\n";
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
	"mov %eax, 0\n" // return value of 0
	"leave\n"
	"ret\n";
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "Usage: ./nsc <file.ns>\n";
		std::exit(1);
	}

	yyin = fopen(argv[1], "r");
	if (!yyin) {
		std::cout << "Error opening " << argv[1] << "!\n";
		std::exit(1);
	}

	output_header();
   	yyparse();
	output_footer();
    
	fclose(yyin);
}