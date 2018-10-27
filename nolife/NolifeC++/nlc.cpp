#include <iostream>
#include <string>

#include <parser/nolife_parser.hpp>
#include <parser/astnode.hpp>

#include "parser/visitor.hpp"
#include "parser/visitorprinter.hpp"

extern ast::Base gASTRoot;

int main(int argc, char *argv[]) {
    yyparse(); // sets gASTRoot to the root of the ast.

    PrintVisitor v;

    gASTRoot.accept(v);
}
