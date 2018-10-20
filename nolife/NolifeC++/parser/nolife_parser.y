/*******************************************************/
/*                     Nolife PARSER                   */
/*                                                     */
/*******************************************************/

/*********************DEFINITIONS***********************/
%{

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

%}

%code requires {
#include <string>
#include <vector>
#include "astsymnode.hpp"
#include "asttypenode.hpp"
#include "astdeclnode.hpp"
}

%union {
    int integer;
    ast::Symbol* symbol;
    ast::Type* type;
    ast::Declaration* declaration;
    std::vector<ast::Type*>* typeList;
    std::vector<ast::Symbol*>* symbList;
}

%start program

%token <integer> O_AND		    1
%token <integer> O_ARRAY	    2
%token <integer> O_BEGIN	    3
%token <integer> O_CHARACTER 	5
%token <integer> O_DO 		    6
%token <integer> O_ELSE 	    7
%token <integer> O_END 		    8
%token <integer> O_FLOAT   	    9
%token <integer> O_FUNCTION 	10
%token <integer> O_IF 		    11
%token <integer> O_INTEGER 	    12 
%token <integer> O_NOT 		    13
%token <integer> O_OF 		    14
%token <integer> O_OR 		    15
%token <integer> O_PROCEDURE 	16
%token <integer> O_PROGRAM 	    17
%token <integer> O_READ 	    18
%token <integer> O_THEN 	    19
%token <integer> O_VAR 		    20
%token <integer> O_WHILE        21
%token <integer> O_WRITE 	    22
%token <integer> O_LBRACE 	    23
%token <integer> O_RBRACE 	    24
%token <integer> O_CONSTANT 	25
%token <integer> O_LE 		    26
%token <integer> O_LT 		    27
%token <integer> O_GE 	        28
%token <integer> O_GT 		    29
%token <integer> O_EQ 		    30
%token <integer> O_NE 		    31
%token <integer> O_ASSIGN 	    32
%token <integer> O_COLON 	    33
%token <integer> O_SEMICOLON	34
%token <integer> O_COMMA 	    35
%token <integer> O_LBRACKET 	36
%token <integer> O_RBRACKET 	37
%token <integer> O_LPAREN 	    38
%token <integer> O_RPAREN 	    39
%token <integer> O_DOTDOT 	    40
%token <integer> O_PLUS 	    41
%token <integer> O_TIMES 	    42
%token <symbol> O_IDENTIFER 	43
%token <integer> O_MOD          44
%token <integer> O_RETURN	    45
%token <integer> O_CHAR    	    46
%token <integer> O_STRING	    47
%token <integer> O_INT    	    48
%token <integer> O_FLOATCON 	49
%token <integer> O_MINUS        50
%token <integer> O_CASE		    51

%type <typeList> decl_list
%type <declaration> decls

%type <type> type
%type <type> standard_type

%type <symbList> identifier_list
%type <symbol> identifier
%type <symbol> id_s

%left O_OR
%left O_AND
%left O_NOT
%left O_LT O_LE O_GT O_GE O_NE O_EQ
%left O_PLUS O_MINUS
%left O_TIMES O_MOD
  
/***********************PRODUCTIONS****************************/
%%
program: 
    O_PROGRAM id_s decls subprogram_decls compound_stmt {
        std::cout << "Done (id_s decls sub_decls compound stmt)\n";

        gASTRoot = ast::Program($2, $3, nullptr);
    }
|   O_PROGRAM id_s decls compound_stmt { 
        std::cout << "Done\n";
    }
|   O_PROGRAM id_s subprogram_decls compound_stmt { 
        std::cout << "Done\n";
    }
|   O_PROGRAM id_s compound_stmt { 
        std::cout << "Done\n";

        gASTRoot = ast::Program($2, nullptr, nullptr);
    }
;

decls: O_VAR decl_list { 
    // returns a declaration (ast::Declaration)
    std::cout << "decls\n";
    auto declNode = new ast::Declaration();
    for (auto type : *$2) {
        declNode->addChild(type);
    }

    delete $2; // delete vector of type nodes (decl_list)

    $$ = declNode;
};       

decl_list: identifier_list colon  type  semicln { 
    // returns typeList (std::vector<ast::Type*>*)
    std::cout << "decl_list (single)\n";
    auto typeList = new std::vector<ast::Type*>();
    for (auto sym : *$1) {
        auto newType = $3->clone();
        newType->addChild(sym);
        typeList->push_back(newType);
    }
    $$ = typeList;
}
| decl_list identifier_list_colon type semicln  
        { std::cout << "decl_list\n";}
;

identifier_list: identifier { 
    std::cout << "identifier_list (single)\n";
    auto symList = new std::vector<ast::Symbol*>();
    symList->push_back($1);
    $$ = symList;
}
| identifier_list comma identifier {
    std::cout << "identifier_list (recursive)\n";
    $1->push_back($3);
    $$ = $1;
};

type: standard_type { 
    std::cout << "type (standard)\n";
    $$ = $1;
}
| array_type { 
    std::cout << "type\n";
};

standard_type: O_INTEGER { 
    std::cout << "standard_type\n";
    $$ = new ast::Integer();
} 
| O_FLOAT { 
    std::cout << "standard_type\n";
    $$ = new ast::Float();
}
| O_CHARACTER { 
    std::cout << "standard_type\n";
    $$ = new ast::Character();
};

array_type      : O_ARRAY O_LBRACKET dim O_RBRACKET O_OF standard_type  
                { std::cout << "array_type\n";}
                ;

dim             : intnum  O_DOTDOT intnum
                { std::cout << "dim\n";}
                | char_const O_DOTDOT char_const 
                { std::cout << "dim\n";}
                ;

subprogram_decls: subprogram_decls subprogram_decl semicln  
                { std::cout << "subprogram_decls\n";}
                | subprogram_decl semicln 
                { std::cout << "subprogram_decls\n";}
                ;

subprogram_decl : subprogram_head decls compound_stmt 
                { std::cout << "subprogram_decl\n";}
                | subprogram_head compound_stmt 
                { std::cout << "subprogram_decl\n";}
                ;

subprogram_head : O_FUNCTION identifier arguments colon standard_type semicln  
                { std::cout << "subprogram_head\n";}
                | O_FUNCTION identifier  colon standard_type semicln  
                { std::cout << "subprogram_head\n";}
                | O_PROCEDURE identifier arguments semicln  
                { std::cout << "subprogram_head\n";}
                | O_PROCEDURE identifier  semicln  
                { std::cout << "subprogram_head\n";}
                ;

arguments       : O_LPAREN parameter_list O_RPAREN  
                { std::cout << "arguments\n";}
                ;

parameter_list  : identifier_list_colon type
                { std::cout << "parameter_list\n";}
                | parameter_list  semicln identifier_list_colon type
                { std::cout << "parameter_list\n";}
                ;

stmt            : assignment
                { std::cout << "stmt\n";}
                | if_stmt
                { std::cout << "stmt\n";}
                | while_stmt
                { std::cout << "stmt\n";}
                | procedure_invocation
                { std::cout << "stmt\n";}
                | i_o_stmt  
                { std::cout << "stmt\n";}
                | compound_stmt
                { std::cout << "stmt\n";}
                | return_stmt
                { std::cout << "stmt\n";}
                | case_stmt
                { std::cout << "stmt\n";}
                ;

assignment      : variable O_ASSIGN expr    
                { std::cout << "assignment\n";}
                ;

if_stmt         : O_IF expr O_THEN restricted_stmt O_ELSE stmt
                { std::cout << "if_stmt\n";}
                | O_IF expr O_THEN stmt        
                { std::cout << "if_stmt\n";}
                ;

restricted_stmt : assignment
                { std::cout << "restricted_stmt\n";}
                | while_stmt    
                { std::cout << "restricted_stmt\n";}
                | i_o_stmt      
                { std::cout << "restricted_stmt\n";}
                | procedure_invocation 
                { std::cout << "restricted_stmt\n";}
                | compound_stmt        
                { std::cout << "restricted_stmt\n";}
                | return_stmt          
                { std::cout << "restricted_stmt\n";}
                | case_stmt          
                { std::cout << "restricted_stmt\n";}
                | O_IF expr O_THEN restricted_stmt O_ELSE restricted_stmt
                { std::cout << "restricted_stmt\n";}
                ;

while_stmt     : O_WHILE expr O_DO restricted_stmt         
                { std::cout << "while_stmt\n";}
               ;

               
procedure_invocation : identifier O_LPAREN O_RPAREN
                { std::cout << "procedure_invocation\n";}
                     | identifier O_LPAREN expr_list O_RPAREN 
                { std::cout << "procedure_invocation\n";}
                     ;

i_o_stmt        : O_READ O_LPAREN variable O_RPAREN  
                { std::cout << "io_stmt\n";}
                | O_WRITE O_LPAREN expr O_RPAREN     
                { std::cout << "io_stmt\n";}
                | O_WRITE O_LPAREN string_constant O_RPAREN           
                { std::cout << "io_stmt\n";}
                ;

compound_stmt   : O_BEGIN stmt_list   O_END  
                { std::cout << "compound_stmt\n";}
                ;

stmt_list       : stmt
                { std::cout << "stmt_list\n";}
                | stmt_list semicln stmt     
                { std::cout << "stmt_list\n";}
                ;

return_stmt     : O_RETURN expr 
                { std::cout << "return_stmt\n";}
                ;

case_stmt	: O_CASE expr O_OF cases O_END
                { std::cout << "case_stmt";}
                | O_CASE expr O_OF O_END
                { std::cout << "case_stmt";}
                ;

cases		: case_element
                { std::cout << "cases\n";}
                | cases O_SEMICOLON case_element
                { std::cout << "cases\n";}
                ;

case_element	: case_labels O_COLON stmt
                {std::cout << "case_element\n";}
                ;

case_labels	: constant
                {std::cout << "case_element\n";}
                | case_labels O_COMMA constant
                {std::cout << "case_element\n";}
                ;

expr_list       : expr 
                { std::cout << "expr_list\n";}
                | expr_list comma expr
                { std::cout << "expr_list\n";}
                ;

expr            : simple_expr
                { std::cout << "expr\n";}
                | expr logop simple_expr 
                { std::cout << "expr\n";}
                | O_NOT simple_expr 
                { std::cout << "expr\n";}
                ;

simple_expr     : add_expr
                { std::cout << "simple_expr\n";}
                | simple_expr relop add_expr
                { std::cout << "simple_expr\n";}
                ;

add_expr        :  mul_expr            
                { std::cout << "add_expr\n";}
                |  add_expr addop mul_expr
                { std::cout << "add_expr\n";}
                ;

mul_expr        :  factor
                { std::cout << "mul_expr\n";}
                |  mul_expr mulop factor
                { std::cout << "mul_expr\n";}
                ;

factor          : variable
                { std::cout << "factor\n";}
                | constant
                { std::cout << "factor\n";}
                | char_const  
                { std::cout << "factor\n";}
                | O_LPAREN expr O_RPAREN
                { std::cout << "factor\n";}
                | procedure_invocation
                { std::cout << "factor\n";}
                ;  

variable        : identifier
                { std::cout << "variable\n";}
                | identifier O_LBRACKET expr O_RBRACKET    
                { std::cout << "variable\n";}
                ;			       

addop           : O_PLUS  
                { std::cout << "addop\n";}
                | O_MINUS 
                { std::cout << "addop\n";}
                ;

mulop           : O_TIMES
                { std::cout << "mulop\n";}
                | O_MOD  
                { std::cout << "mulop\n";}
                ;

relop           : O_LE
                { std::cout << "relop\n";}
                | O_LT
                { std::cout << "relop\n";}
                | O_GE
                { std::cout << "relop\n";}
                | O_GT
                { std::cout << "relop\n";}
                | O_EQ
                { std::cout << "relop\n";}
                | O_NE
                { std::cout << "relop\n";}
                ;

logop           : O_AND
                { std::cout << "logop\n";}
                | O_OR 
                { std::cout << "logop\n";}
                ;

identifier: O_IDENTIFER { 
    std::cout << "identifier\n";
    $$ = new ast::Symbol(yytext);
};

intnum          : O_INT  
                { std::cout << "intnum\n";}
                ;

char_const      : O_CHAR
                { std::cout << "char_const\n";}
                ;

string_constant : O_STRING
                { std::cout << "string_constant\n";}
                ;

constant        : O_FLOATCON    
                { std::cout << "constant\n";}
                | O_INT
                { std::cout << "constant\n";}
                ;

identifier_list_colon: identifier_list colon { 
    std::cout << "identifier_list_colon\n";
};

id_s: identifier semicln { 
    std::cout << "id_s\n";
    $$ = $1;
};

semicln        : O_SEMICOLON
                { std::cout << "semicln\n";}
               ;

comma           : O_COMMA
                { std::cout << "comma\n";}
                ;

colon           : O_COLON
                { std::cout << "colon\n";}
                ;  
%%

/********************C ROUTINES *********************************/
int yyerror(const char *s)
{
  std::cout << "Parse error: %s\n",s;
}

/******************END OF C ROUTINES**********************/










