/*******************************************************/
/*                     Nolife PARSER                   */
/*                                                     */
/*******************************************************/

/*********************DEFINITIONS***********************/
%{

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
#include "astarraynode.hpp"

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
}

%union {
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
%type <declaration> subprogram_decls

%type <type> subprogram_decl
%type <type> subprogram_head
%type <parameters> arguments
%type <parameters> parameter_list

%type <type> type
%type <type> standard_type
%type <type> array_type
%type <symbol> intnum
%type <symbList> dim

%type <symbList> identifier_list
%type <symbol> identifier
%type <symbol> id_s

%type <stmtList> stmt_list
%type <statement> stmt

%type <_if> if_stmt
%type <_while> while_stmt
%type <statement> i_o_stmt

%type <caseLabels> case_labels
%type <clause> case_element
%type <clauseList> cases
%type <_case> case_stmt

%type <compoundstatement> compound_stmt

%type <assignment> assignment

%type <exprList> expr_list
%type <expression> expr
%type <expression> rel_expr
%type <expression> add_expr
%type <expression> mul_expr
%type <expression> factor
%type <expression> addop
%type <expression> mulop
%type <expression> relop
%type <expression> logop

%type <call> procedure_invocation

%type <variable> variable
%type <constant> constant
%type <constant> char_const
%type <constant> string_constant

%type <_return> return_stmt;

%left O_OR
%left O_AND
%left O_NOT
%left O_LT O_LE O_GT O_GE O_NE O_EQ
%left O_PLUS O_MINUS
%left O_TIMES O_MOD

%right O_THEN O_ELSE

/***********************PRODUCTIONS****************************/
%%
program: 
    O_PROGRAM id_s decls subprogram_decls compound_stmt {
        std::cout << "Done (id_s decls sub_decls compound_stmt)\n";

        // combine decls with subprogram_decls
        for (auto typeNode : $4->getChildren()) {
            $3->addChild(typeNode);
        }

        // delete subprogram_decls, since we saved its children

        delete $4;

        gASTRoot = ast::Program($2, $3, $5);
    }
|   O_PROGRAM id_s decls compound_stmt { 
        std::cout << "Done (id_s decls compound_stmt)\n";

        gASTRoot = ast::Program($2, $3, $4);
    }
|   O_PROGRAM id_s subprogram_decls compound_stmt { 
        std::cout << "Done (id_s sub_decls compound_stmt)\n";

        gASTRoot = ast::Program($2, $3, $4);
    }
|   O_PROGRAM id_s compound_stmt { 
        std::cout << "Done\n (compound_stmt)";

        gASTRoot = ast::Program($2, nullptr, $3);
    }
;

decls: O_VAR decl_list { 
    // returns a declaration (ast::Declaration)
    std::cout << "decls\n";
    auto declNode = new ast::Declaration();
    for (auto type : *$2) {
        declNode->addChild(type);
    }

    delete $2; // delete vector of type node pointers (decl_list)

    $$ = declNode;
};       

decl_list: identifier_list colon type semicln { 
    // returns typeList (std::vector<ast::Type*>*)
    std::cout << "decl_list (single)\n";
    auto typeList = new std::vector<ast::Type*>();
    for (auto sym : *$1) { // for each symbol node in the identifier_list
        auto newType = $3->clone();
        newType->setSymbol(sym);
        typeList->push_back(newType);
    }

    delete $3; // delete the original type node, since we cloned it

    $$ = typeList;
}
| decl_list identifier_list colon type semicln { 
    // returns typeList (std::vector<ast::Type*>*)
    std::cout << "decl_list (recursive, )\n";
    for (auto sym : *$2) { // for each symbol node in the identifier_list
        auto newType = $4->clone();
        newType->setSymbol(sym);
        $1->push_back(newType);
    }

    delete $4; // delete the original type node, since we cloned it

    $$ = $1;
};

identifier_list: identifier { 
    // returns symbList std::vector<ast::Symbol*>*)
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
    // returns a type node (ast::Type)
    std::cout << "type (standard)\n";
    $$ = $1;
}
| array_type { 
    std::cout << "type (array)\n";
    $$ = $1;
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

array_type: O_ARRAY O_LBRACKET dim O_RBRACKET O_OF standard_type { 
    std::cout << "array_type\n";
    auto array = new ast::Array();

    auto dimlist = $3;
    auto type = $6;

    array->setBounds((*dimlist)[0], (*dimlist)[1]);

    type->setArray(array);

    $$ = type;
};

dim: intnum O_DOTDOT intnum { 
    std::cout << "dim\n";
    auto list = new std::vector<ast::Symbol*>;
    list->push_back($1);
    list->push_back($3);
    $$ = list;
}
| char_const O_DOTDOT char_const  { 
    std::cout << "dim\n";
    auto list = new std::vector<ast::Symbol*>;
    list->push_back($1);
    list->push_back($3);
    $$ = list;
};

subprogram_decls: subprogram_decls subprogram_decl semicln { 
    // returns a declaration (ast::Declaration)
    std::cout << "subprogram_decls\n";

    $1->addChild($2);

    $$ = $1;
}
| subprogram_decl semicln { 
    // returns a declaration (ast::Declaration)
    std::cout << "subprogram_decls\n";

    auto declNode = new ast::Declaration();
    declNode->addChild($1);

    $$ = declNode;
};

subprogram_decl: subprogram_head decls compound_stmt { 
    // returns a type node (ast::Type)
    std::cout << "subprogram_decl\n";

    // get func node from type node
    // since subprogram_head returns a type node with a func node attached to it
    auto funcNode_base = $1->getChildren()[0]; // this gets an ast::Base*
    auto funcNode = dynamic_cast<ast::Procedure*>(funcNode_base);

    if (funcNode == nullptr) {
        std::cout << "  Error in subprogram_decl!\n";
    }

    funcNode->setDecl($2);
    funcNode->setCompoundStmt($3);

    $$ = $1;
}
| subprogram_head compound_stmt { 
    std::cout << "subprogram_decl\n";

    // get func node from type node
    // since subprogram_head returns a type node with a func node attached to it
    auto funcNode_base = $1->getChildren()[0]; // this gets an ast::Base*
    auto funcNode = dynamic_cast<ast::Procedure*>(funcNode_base);

    if (funcNode == nullptr) {
        std::cout << "  Error in subprogram_decl!\n";
    }

    funcNode->setCompoundStmt($2);

    $$ = $1;
};

subprogram_head: O_FUNCTION identifier arguments colon standard_type semicln { 
    // returns a type node (ast::Type) that points to a func/proceedure
    std::cout << "subprogram_head\n";

    auto type = $5;

    auto func = new ast::Procedure(
        $2, // identifier; symbol node
        $3, // parameters
        nullptr, // no declarations available yet
        nullptr // no compound statement available yet
    );

    type->setFunc(func);

    $$ = type;
}
| O_FUNCTION identifier colon standard_type semicln {
    // returns a type node (ast::Type) that points to a func/proceedure
    std::cout << "subprogram_head\n";

    auto type = $4;

    auto func = new ast::Procedure(
        $2, // identifier; symbol node
        nullptr, // no parameters
        nullptr, // no declarations available yet
        nullptr // no compound statement available yet
    );

    type->setFunc(func);

    $$ = type;
}
| O_PROCEDURE identifier arguments semicln {
    // returns a type node (ast::Type) that points to a func/proceedure
    std::cout << "subprogram_head (proc)\n";

    auto type = new ast::Void();

    auto func = new ast::Procedure(
        $2, // identifier; symbol node
        $3, // parameters
        nullptr, // no declarations available yet
        nullptr // no compound statement available yet
    );

    type->setFunc(func);

    $$ = type;
}
| O_PROCEDURE identifier semicln {
    // returns a type node (ast::Type) that points to a func/proceedure
    std::cout << "subprogram_head (proc, no args)\n";

    auto type = new ast::Void();

    auto func = new ast::Procedure(
        $2, // identifier; symbol node
        nullptr, // no parameters
        nullptr, // no declarations available yet
        nullptr // no compound statement available yet
    );

    type->setFunc(func);

    $$ = type;
};

arguments: O_LPAREN parameter_list O_RPAREN { 
    // returns a parameter node (ast::Parameters)
    std::cout << "arguments\n";
    $$ = $2;
};

parameter_list: identifier_list colon type { 
    // returns a parameter node (ast::Parameters)
    std::cout << "parameter_list (single)\n";

    auto paramNode = new ast::Parameters;

    for (auto sym : *$1) {
        auto newType = $3->clone();
        newType->setSymbol(sym);
        paramNode->addChild(newType);
    }

    delete $3;

    $$ = paramNode;

} | parameter_list semicln identifier_list colon type { 
    std::cout << "parameter_list (recursive)\n";

    for (auto sym : *$3) {
        auto newType = $5->clone();
        newType->setSymbol(sym);
        $1->addChild(newType);
    }

    delete $5;

    $$ = $1;
} ;

stmt: assignment { 
    std::cout << "stmt (assignment)\n";
    $$ = $1;
} | if_stmt {
    std::cout << "stmt (if)\n";
    $$ = $1;
} | while_stmt {
    std::cout << "stmt (while)\n";
    $$ = $1;
} | procedure_invocation { 
    std::cout << "stmt (proc invoke)\n";
    $$ = $1;
} | i_o_stmt { 
    std::cout << "stmt\n";
    $$ = $1;
} | compound_stmt { 
    std::cout << "stmt (compound_stmt)\n";
    $$ = $1;
} | return_stmt { 
    std::cout << "stmt (return)\n";
    $$ = $1;
} | case_stmt { 
    std::cout << "stmt\n";
    $$ = $1;
};

assignment: variable O_ASSIGN expr { 
    // returns assignment (ast::Assignement)
    std::cout << "assignment\n";

    $$ = new ast::Assignment($1, $3);
};

if_stmt: O_IF expr O_THEN stmt O_ELSE stmt {
    std::cout << "if_stmt\n";

    $$ = new ast::If($2, $4, $6);
}
| O_IF expr O_THEN stmt {
    std::cout << "if_stmt\n";

    $$ = new ast::If($2, $4, nullptr);
};

while_stmt: O_WHILE expr O_DO stmt { 
    std::cout << "while_stmt\n";

    $$ = new ast::While($2, $4);
};
               
procedure_invocation: identifier O_LPAREN O_RPAREN { 
    std::cout << "procedure_invocation\n";
    $$ = new ast::Call($1);
}
| identifier O_LPAREN expr_list O_RPAREN { 
    std::cout << "procedure_invocation\n";
    
    auto callNode = new ast::Call($1);

    for (auto expr : *$3) {
        callNode->addChild(expr);
    }

    delete $3;

    $$ = callNode;
};

i_o_stmt: O_READ O_LPAREN variable O_RPAREN { 
    std::cout << "io_stmt\n";
    $$ = new ast::Read($3);
}| O_WRITE O_LPAREN expr O_RPAREN { 
    std::cout << "io_stmt\n";
    $$ = new ast::Write($3);
}| O_WRITE O_LPAREN string_constant O_RPAREN          { 
    std::cout << "io_stmt\n";
    $$ = new ast::Write($3);
};

compound_stmt: O_BEGIN stmt_list O_END { 
    // returns a compoundstatement (ast::CompoundStatement)
    std::cout << "compound_stmt\n";

    auto list = $2;

    auto compoundstmt = new ast::CompoundStatement;

    for (auto stmt : *list) {
        compoundstmt->addChild(stmt);
    }

    delete $2;

    $$ = compoundstmt;
};

stmt_list: stmt { 
    // returns a stmtList (std::vector<ast::Statement>*)
    std::cout << "stmt_list (single)\n";

    auto list = new std::vector<ast::Statement*>;

    list->push_back($1);

    $$ = list;
}
| stmt_list semicln stmt { 
    std::cout << "stmt_list (recursive)\n";

    $1->push_back($3);

    $$ = $1;
};

return_stmt: O_RETURN expr { 
    std::cout << "return_stmt\n";
    $$ = new ast::Return($2);
};

case_stmt: O_CASE expr O_OF cases O_END { 
    std::cout << "case_stmt";
    $$ = new ast::Case($2, $4);
} | O_CASE expr O_OF O_END { 
    std::cout << "case_stmt";
    $$ = new ast::Case($2, nullptr);
} ;

cases: case_element { 
    std::cout << "cases\n";

    auto list = new std::vector<ast::Clause*>;

    list->push_back($1);

    $$ = list;
} | cases O_SEMICOLON case_element { 
    std::cout << "cases (recursive)\n";

    $1->push_back($3);

    $$ = $1;
} ;

case_element: case_labels O_COLON stmt {
    std::cout << "case_element\n";
    $$ = new ast::Clause($1, $3);
};

case_labels: constant {
    std::cout << "case_element\n";

    auto caseLabels = new ast::CaseLabels();

    caseLabels->addChild($1);

    $$ = caseLabels;
} | case_labels O_COMMA constant {
    std::cout << "case_element (recursive)\n";
    $1->addChild($3);
    $$ = $1;
};

expr_list: expr { 
    std::cout << "expr_list (single)\n";

    auto list = new std::vector<ast::Expression*>;

    list->push_back($1);

    $$ = list;
}
| expr_list comma expr { 
    std::cout << "expr_list (recursive)\n";

    $1->push_back($3);

    $$ = $1;
};

expr: rel_expr { 
    std::cout << "expr\n";
    $$ = $1;
}
| expr logop rel_expr { 
    std::cout << "expr\n";
    $2->addChild($1);
    $2->addChild($3);
    $$ = $2;
}
| O_NOT factor { 
    std::cout << "expr\n";
    auto exprNode = new ast::Expression(ast::Expression::Operation::Not);
    exprNode->addChild($2);
    $$ = exprNode;
};

// structured for precdedence...

rel_expr: add_expr {
    std::cout << "rel_expr\n";
    $$ = $1;
}
| rel_expr relop add_expr { 
    std::cout << "rel_expr\n";
    $2->addChild($1);
    $2->addChild($3);
    $$ = $2;
};

add_expr: mul_expr {
    std::cout << "add_expr\n";
    $$ = $1;
}
| add_expr addop mul_expr { 
    std::cout << "add_expr\n";
    $2->addChild($1);
    $2->addChild($3);
    $$ = $2;
};

mul_expr: factor {
    std::cout << "mul_expr\n";
    $$ = $1;
}
| mul_expr mulop factor { 
    std::cout << "mul_expr\n";
    $2->addChild($1);
    $2->addChild($3);
    $$ = $2;
};

factor: variable { 
    std::cout << "factor\n";
    $$ = new ast::Expression($1);
}
| constant { 
    std::cout << "factor\n";
    $$ = new ast::Expression($1);
}
| char_const { 
    std::cout << "factor\n";
    $$ = new ast::Expression($1);
}
| O_LPAREN expr O_RPAREN { 
    std::cout << "factor\n";
    $$ = $2;
}
| procedure_invocation { 
    std::cout << "factor\n";
    $$ = new ast::Expression($1);
};  

variable: identifier { 
    std::cout << "variable\n";
    $$ = new ast::Variable($1);
}
| identifier O_LBRACKET expr O_RBRACKET { 
    std::cout << "variable\n";
    $$ = new ast::ArrayAccess($1, $3);
}			       

addop: O_PLUS  { 
    std::cout << "addop\n";
    $$ = new ast::Expression(ast::Expression::Operation::Plus);
}
| O_MINUS { 
    std::cout << "addop\n";
    $$ = new ast::Expression(ast::Expression::Operation::Minus);
};

mulop: O_TIMES {
    std::cout << "mulop\n";
    $$ = new ast::Expression(ast::Expression::Operation::Multiply);
}
| O_MOD {
    std::cout << "mulop\n";
    $$ = new ast::Expression(ast::Expression::Operation::Modulo);
};

relop: O_LE { 
    std::cout << "relop\n";
    $$ = new ast::Expression(ast::Expression::Operation::LessThanOrEqual);
}
| O_LT { 
    std::cout << "relop\n";
    $$ = new ast::Expression(ast::Expression::Operation::LessThan);
}
| O_GE { 
    std::cout << "relop\n";
    $$ = new ast::Expression(ast::Expression::Operation::GreaterThanOrEqual);
}
| O_GT { 
    std::cout << "relop\n";
    $$ = new ast::Expression(ast::Expression::Operation::GreaterThan);
}
| O_EQ { 
    std::cout << "relop\n";
    $$ = new ast::Expression(ast::Expression::Operation::Equals);
}
| O_NE { 
    std::cout << "relop\n";
    $$ = new ast::Expression(ast::Expression::Operation::NotEqual);
};

logop: O_AND { 
    std::cout << "logop\n";
    $$ = new ast::Expression(ast::Expression::Operation::And);
}
| O_OR { 
    std::cout << "logop\n";
    $$ = new ast::Expression(ast::Expression::Operation::Or);
};

identifier: O_IDENTIFER { 
    std::cout << "identifier (" << yytext << ") \n";
    $$ = new ast::Symbol(yytext);
};

intnum: O_INT { 
    std::cout << "intnum\n";
    $$ = new ast::Constant(yytext);
};

char_const: O_CHAR { 
    std::cout << "char_const" << yytext << "\n";
    $$ = new ast::Constant(yytext);
};

string_constant: O_STRING { 
    std::cout << "string_constant" << yytext << "\n";
    $$ = new ast::Constant(yytext);
};

constant: O_FLOATCON     { 
    std::cout << "constant" << yytext << "\n";
    $$ = new ast::Constant(yytext);
}
| O_INT { 
    std::cout << "constant" << yytext << "\n";
    $$ = new ast::Constant(yytext);
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
  std::cout << "Parse error: " << s << "\n";
}

/******************END OF C ROUTINES**********************/
