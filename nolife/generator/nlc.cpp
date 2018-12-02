#include <iostream>
#include <fstream>
#include <string>

#include "parser/nolife_parser.hpp"
#include "parser/astnode.hpp"

#include "visitors/visitor.hpp"
#include "visitors/visitorprinter.hpp"
#include "visitors/visitortypechecker.hpp"
#include "visitors/visitormemmap.hpp"
#include "visitors/visitorcodegenerator.hpp"

extern FILE* yyin;

extern ast::Base* gASTRoot;

int main(int argc, char *argv[]) {

    if (argc < 2) {
        std::cout << "Usage: ./nlc <.nl file>\n";
        return -1;
    }

    FILE* file = fopen(argv[1], "r");

    if (file) {
        yyin = file;
    } else {
        std::cout << "Error opening file " << argv[1] << "!\n";
    }

    // hack to disable cout temporarily
    std::cout.setstate(std::ios_base::failbit);

    yyparse(); // sets gASTRoot to the root of the ast.

    // re-enable cout
    std::cout.clear();

    PrintVisitor p;
    TypeCheckVisitor t;
    MemoryMapVisitor mm(std::cout, std::cout);

    std::ofstream outputFile;

    outputFile.open("asm.S");

    CodeGeneratorVisitor cg(outputFile, std::cout, t, mm);
    
    gASTRoot->accept(p);
    gASTRoot->accept(cg);
    gASTRoot->accept(p);

}
