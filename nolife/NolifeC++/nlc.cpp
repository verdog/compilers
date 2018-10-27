#include <iostream>
#include <string>

#include <parser/nolife_parser.hpp>
#include <parser/astnode.hpp>
#include <parser/astsymnode.hpp>

extern ast::Base gASTRoot;

int main(int argc, char *argv[]) {
    yyparse(); // sets gASTRoot to the root of the ast.

    
}
