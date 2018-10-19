/*******************************************************/
/*                     Nolife PARSER                   */
/*                                                     */
/*******************************************************/

/*********************DEFINITIONS***********************/
%{
#include <iostream>
#include <string>

#include "astnode.hpp"
#include "astsymnode.hpp"
#include "astprognode.hpp"

ast::Base gASTRoot = ast::Base();

extern int yylex();
int yyerror(const char *s);

using namespace std;

%}
%start program

%union {
    int integer;
}

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
%token <integer> O_IDENTIFER 	43
%token <integer> O_MOD          44
%token <integer> O_RETURN	    45
%token <integer> O_CHAR    	    46
%token <integer> O_STRING	    47
%token <integer> O_INT    	    48
%token <integer> O_FLOATCON 	49
%token <integer> O_MINUS        50
%token <integer> O_CASE		    51

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
        cout << "Done\n";
    }
|   O_PROGRAM id_s decls compound_stmt { 
        cout << "Done\n";
    }
|   O_PROGRAM id_s subprogram_decls compound_stmt { 
        cout << "Done\n";
    }
|   O_PROGRAM id_s compound_stmt { 
        cout << "Done\n";

        gASTRoot = ast::Program(new ast::Symbol("hey."), nullptr, nullptr);
    }
;

decls     : O_VAR decl_list     
                { cout << "decls\n";}
          ;       

decl_list : identifier_list_colon  type  semicln  
                { cout << "decl_list\n";}
          | decl_list identifier_list_colon type semicln  
                { cout << "decl_list\n";}
          ;


identifier_list : identifier  
                { cout << "identifier_list\n";}
                | identifier_list comma identifier
                { cout << "identifier_list\n";}
                ;

type            : standard_type          
                { cout << "type\n";}
                | array_type
                { cout << "type\n";}
                ;

standard_type   : O_INTEGER 
                { cout << "standard_type\n";}
                | O_FLOAT   
                { cout << "standard_type\n";}
                | O_CHARACTER
                { cout << "standard_type\n";}
                ;

array_type      : O_ARRAY O_LBRACKET dim O_RBRACKET O_OF standard_type  
                { cout << "array_type\n";}
                ;

dim             : intnum  O_DOTDOT intnum
                { cout << "dim\n";}
                | char_const O_DOTDOT char_const 
                { cout << "dim\n";}
                ;

subprogram_decls: subprogram_decls subprogram_decl semicln  
                { cout << "subprogram_decls\n";}
                | subprogram_decl semicln 
                { cout << "subprogram_decls\n";}
                ;

subprogram_decl : subprogram_head decls compound_stmt 
                { cout << "subprogram_decl\n";}
                | subprogram_head compound_stmt 
                { cout << "subprogram_decl\n";}
                ;

subprogram_head : O_FUNCTION identifier arguments colon standard_type semicln  
                { cout << "subprogram_head\n";}
                | O_FUNCTION identifier  colon standard_type semicln  
                { cout << "subprogram_head\n";}
                | O_PROCEDURE identifier arguments semicln  
                { cout << "subprogram_head\n";}
                | O_PROCEDURE identifier  semicln  
                { cout << "subprogram_head\n";}
                ;

arguments       : O_LPAREN parameter_list O_RPAREN  
                { cout << "arguments\n";}
                ;

parameter_list  : identifier_list_colon type
                { cout << "parameter_list\n";}
                | parameter_list  semicln identifier_list_colon type
                { cout << "parameter_list\n";}
                ;

stmt            : assignment
                { cout << "stmt\n";}
                | if_stmt
                { cout << "stmt\n";}
                | while_stmt
                { cout << "stmt\n";}
                | procedure_invocation
                { cout << "stmt\n";}
                | i_o_stmt  
                { cout << "stmt\n";}
                | compound_stmt
                { cout << "stmt\n";}
                | return_stmt
                { cout << "stmt\n";}
                | case_stmt
                { cout << "stmt\n";}
                ;

assignment      : variable O_ASSIGN expr    
                { cout << "assignment\n";}
                ;

if_stmt         : O_IF expr O_THEN restricted_stmt O_ELSE stmt
                { cout << "if_stmt\n";}
                | O_IF expr O_THEN stmt        
                { cout << "if_stmt\n";}
                ;

restricted_stmt : assignment
                { cout << "restricted_stmt\n";}
                | while_stmt    
                { cout << "restricted_stmt\n";}
                | i_o_stmt      
                { cout << "restricted_stmt\n";}
                | procedure_invocation 
                { cout << "restricted_stmt\n";}
                | compound_stmt        
                { cout << "restricted_stmt\n";}
                | return_stmt          
                { cout << "restricted_stmt\n";}
                | case_stmt          
                { cout << "restricted_stmt\n";}
                | O_IF expr O_THEN restricted_stmt O_ELSE restricted_stmt
                { cout << "restricted_stmt\n";}
                ;

while_stmt     : O_WHILE expr O_DO restricted_stmt         
                { cout << "while_stmt\n";}
               ;

               
procedure_invocation : identifier O_LPAREN O_RPAREN
                { cout << "procedure_invocation\n";}
                     | identifier O_LPAREN expr_list O_RPAREN 
                { cout << "procedure_invocation\n";}
                     ;

i_o_stmt        : O_READ O_LPAREN variable O_RPAREN  
                { cout << "io_stmt\n";}
                | O_WRITE O_LPAREN expr O_RPAREN     
                { cout << "io_stmt\n";}
                | O_WRITE O_LPAREN string_constant O_RPAREN           
                { cout << "io_stmt\n";}
                ;

compound_stmt   : O_BEGIN stmt_list   O_END  
                { cout << "compound_stmt\n";}
                ;

stmt_list       : stmt
                { cout << "stmt_list\n";}
                | stmt_list semicln stmt     
                { cout << "stmt_list\n";}
                ;

return_stmt     : O_RETURN expr 
                { cout << "return_stmt\n";}
                ;

case_stmt	: O_CASE expr O_OF cases O_END
                { cout << "case_stmt";}
                | O_CASE expr O_OF O_END
                { cout << "case_stmt";}
                ;

cases		: case_element
                { cout << "cases\n";}
                | cases O_SEMICOLON case_element
                { cout << "cases\n";}
                ;

case_element	: case_labels O_COLON stmt
                {cout << "case_element\n";}
                ;

case_labels	: constant
                {cout << "case_element\n";}
                | case_labels O_COMMA constant
                {cout << "case_element\n";}
                ;

expr_list       : expr 
                { cout << "expr_list\n";}
                | expr_list comma expr
                { cout << "expr_list\n";}
                ;

expr            : simple_expr
                { cout << "expr\n";}
                | expr logop simple_expr 
                { cout << "expr\n";}
                | O_NOT simple_expr 
                { cout << "expr\n";}
                ;

simple_expr     : add_expr
                { cout << "simple_expr\n";}
                | simple_expr relop add_expr
                { cout << "simple_expr\n";}
                ;

add_expr        :  mul_expr            
                { cout << "add_expr\n";}
                |  add_expr addop mul_expr
                { cout << "add_expr\n";}
                ;

mul_expr        :  factor
                { cout << "mul_expr\n";}
                |  mul_expr mulop factor
                { cout << "mul_expr\n";}
                ;

factor          : variable
                { cout << "factor\n";}
                | constant
                { cout << "factor\n";}
                | char_const  
                { cout << "factor\n";}
                | O_LPAREN expr O_RPAREN
                { cout << "factor\n";}
                | procedure_invocation
                { cout << "factor\n";}
                ;  

variable        : identifier
                { cout << "variable\n";}
                | identifier O_LBRACKET expr O_RBRACKET    
                { cout << "variable\n";}
                ;			       

addop           : O_PLUS  
                { cout << "addop\n";}
                | O_MINUS 
                { cout << "addop\n";}
                ;

mulop           : O_TIMES
                { cout << "mulop\n";}
                | O_MOD  
                { cout << "mulop\n";}
                ;

relop           : O_LE
                { cout << "relop\n";}
                | O_LT
                { cout << "relop\n";}
                | O_GE
                { cout << "relop\n";}
                | O_GT
                { cout << "relop\n";}
                | O_EQ
                { cout << "relop\n";}
                | O_NE
                { cout << "relop\n";}
                ;

logop           : O_AND
                { cout << "logop\n";}
                | O_OR 
                { cout << "logop\n";}
                ;

identifier      : O_IDENTIFER  
                { cout << "identifier\n";}
                ;

intnum          : O_INT  
                { cout << "intnum\n";}
                ;

char_const      : O_CHAR
                { cout << "char_const\n";}
                ;

string_constant : O_STRING
                { cout << "string_constant\n";}
                ;

constant        : O_FLOATCON    
                { cout << "constant\n";}
                | O_INT
                { cout << "constant\n";}
                ;

identifier_list_colon : identifier_list colon
                { cout << "identifier_list_colon\n";}
                      ;

id_s      : identifier semicln 
                { cout << "id_s\n";}
          ;

semicln        : O_SEMICOLON
                { cout << "semicln\n";}
               ;

comma           : O_COMMA
                { cout << "comma\n";}
                ;

colon           : O_COLON
                { cout << "colon\n";}
                ;  
%%

/*********************EXTERNAL DECLARATIONS***********************/

extern char yytext[];
extern FILE  *yyin;
int errcount=0;

/********************C ROUTINES *********************************/
int yyerror(const char *s)
{
  cout << "Parse error: %s\n",s;
}

/******************END OF C ROUTINES**********************/










