#include <iostream>
#include <string>
#include <algorithm>

#include "visitorcodegenerator.hpp"
#include "visitortypechecker.hpp"
#include "visitormemmap.hpp"

#include "../parser/astnode.hpp"
#include "../parser/astarrayaccessnode.hpp"
#include "../parser/astarraynode.hpp"
#include "../parser/astassignnode.hpp"
#include "../parser/astcallnode.hpp"
#include "../parser/astcaselabelsnode.hpp"
#include "../parser/astcasenode.hpp"
#include "../parser/astclausenode.hpp"
#include "../parser/astcompoundstmtnode.hpp"
#include "../parser/astconstantnode.hpp"
#include "../parser/astdeclnode.hpp"
#include "../parser/astexpressionnode.hpp"
#include "../parser/astifnode.hpp"
#include "../parser/astparamnode.hpp"
#include "../parser/astprocnode.hpp"
#include "../parser/astprognode.hpp"
#include "../parser/astreadnode.hpp"
#include "../parser/astreturnnode.hpp"
#include "../parser/aststmtnode.hpp"
#include "../parser/astsymnode.hpp"
#include "../parser/asttypenode.hpp"
#include "../parser/astvariablenode.hpp"
#include "../parser/astwhilenode.hpp"
#include "../parser/astwritenode.hpp"

/**************************
 * Code generator visitor *
 **************************/

CodeGeneratorVisitor::CodeGeneratorVisitor(
    std::ostream& output, 
    std::ostream& log,
    TypeCheckVisitor& typeCheckVisitor,
    MemoryMapVisitor& memoryMapVisitor
)
: mLogS {log}
, mOutputS {output}
, mTypeCheckVisitor {typeCheckVisitor}
, mMemoryMapVisitor {memoryMapVisitor}
, mCurrentProcedure {""}
{
}

void CodeGeneratorVisitor::initialize() {
    mOutputS <<
        "#-------------------------------#\n"
        "# nolife compiler               #\n"
        "# Josh Chandler                 #\n"
        "#-------------------------------#\n"
    ;

    mOutputS <<
        "   .intel_syntax\n"
        "   .section .rodata\n"
        ".io_format:\n"
        "   .string \"%d\\12\\0\"\n"
        "_constant:\n"
    ;
    
    auto &constMap = mMemoryMapVisitor.mConstantMap;

    // turn map into a list of pairs
    using pairType = std::pair<std::string, MemoryInfo>;
    std::vector<pairType> pairList;
    for (auto mapPair : constMap) {
        pairList.push_back(pairType(mapPair.first, mapPair.second));
    }

    // sort by offset
    std::sort(pairList.begin(), pairList.end(), 
        [](const pairType &a, const pairType &b) -> bool {
            return a.second.offset < b.second.offset;
        }
    );

    // output constants
    for (auto constantPair : pairList) {
        std::string image = constantPair.first;
        MemoryInfo info = constantPair.second;

        if (info.type == ast::Type::Types::Float) {
            mOutputS << "   .float " << image << std::endl;
        } else if (info.type == ast::Type::Types::Character
                || info.type == ast::Type::Types::StringConstant
        ) {
            // change single quotes to double quotes
            std::replace(image.begin(), image.end(), '\'', '\"');
            mOutputS << "   .string " << image << std::endl;
        }
    }
    
    mOutputS <<
        "   .text\n"
        "   .globl main;\n"
        "   .type main, @function\n"
    ;
}

void CodeGeneratorVisitor::finalize() {
    mOutputS <<
        "main:\n"
        "   push %ebp\n"
        "   mov %ebp, %esp\n"
        "   sub %esp, 4\n"
        "   mov %eax, offset flat:_constant\n"
        "   leave\n"
        "   ret\n"
    ;
}

void CodeGeneratorVisitor::visitUniversal(ast::Base *b) {
    // mLogS << "(universal)\n";

    for (auto node : b->getChildren()) {
        if (node != nullptr) {
            node->accept(*this);
        }
    }
}

void CodeGeneratorVisitor::visit(ast::Base* b) {
    visitUniversal(b);
}

void CodeGeneratorVisitor::visit(ast::Program* p) {
    // make sure we have a type map and a memory map
    if (!mTypeCheckVisitor.mDone) {
        mLogS << "Detected missing symbol table. Creating now.\n";
        p->accept(mTypeCheckVisitor);
    }

    if (!mMemoryMapVisitor.mDone) {
        mLogS << "Detected missing memory map. Creating now.\n";
        p->accept(mMemoryMapVisitor);
        mMemoryMapVisitor.dumpOutput(mLogS);
    }

    initialize(); // output default header info

    mCurrentProcedure = p->getSymbol()->getImage();

    visitUniversal(p);

    finalize();
}

void CodeGeneratorVisitor::visit(ast::Declaration* d) {
    visitUniversal(d);
}

void CodeGeneratorVisitor::visit(ast::CompoundStatement* cs) {
    visitUniversal(cs);
}

void CodeGeneratorVisitor::visit(ast::Parameters* p) {
    visitUniversal(p);
}

void CodeGeneratorVisitor::visit(ast::Symbol* s) {
    visitUniversal(s);
}

void CodeGeneratorVisitor::visit(ast::Type* t) {
    visitUniversal(t);
}

void CodeGeneratorVisitor::visit(ast::Integer* i) {
    visitUniversal(i);
}

void CodeGeneratorVisitor::visit(ast::Float* f) {
    visitUniversal(f);
}

void CodeGeneratorVisitor::visit(ast::Character* c) {
    visitUniversal(c);
}

void CodeGeneratorVisitor::visit(ast::Void* v) {
    visitUniversal(v);
}

void CodeGeneratorVisitor::visit(ast::ArrayAccess* aa) {
    visitUniversal(aa);
}

void CodeGeneratorVisitor::visit(ast::Array* a) {
    visitUniversal(a);
}

void CodeGeneratorVisitor::visit(ast::Assignment* a) {
    visitUniversal(a);
}

void CodeGeneratorVisitor::visit(ast::Call* c) {
    visitUniversal(c);
}

void CodeGeneratorVisitor::visit(ast::CaseLabels* cl) {
    visitUniversal(cl);
}

void CodeGeneratorVisitor::visit(ast::Case* c) {
    visitUniversal(c);
}

void CodeGeneratorVisitor::visit(ast::Clause* c) {
    visitUniversal(c);
}

void CodeGeneratorVisitor::visit(ast::Constant* c) {
    visitUniversal(c);
}

void CodeGeneratorVisitor::visit(ast::Expression* e) {
    visitUniversal(e);
}

void CodeGeneratorVisitor::visit(ast::If* i) {
    visitUniversal(i);
}

void CodeGeneratorVisitor::visit(ast::Procedure* p) {
    visitUniversal(p);
}

void CodeGeneratorVisitor::visit(ast::Return* r) {
    visitUniversal(r);
}

void CodeGeneratorVisitor::visit(ast::Statement* s) {
    visitUniversal(s);
}

void CodeGeneratorVisitor::visit(ast::Variable* v) {
    visitUniversal(v);
}

void CodeGeneratorVisitor::visit(ast::While* w) {
    visitUniversal(w);
}

void CodeGeneratorVisitor::visit(ast::Write* w) {
    // To execute an output we will use the C function printf. To call printf, use the following sequence,
    // where the variable to be printed has a 4-byte offset.
    // push dword ptr [%ebp-4]
    // push offset flat:.io_format
    // call printf
    // add %esp, 8
    visitUniversal(w);
}

void CodeGeneratorVisitor::visit(ast::Read* r) {
    visitUniversal(r);
}
