#include <iostream>
#include <string>

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

/***************
 * Memory info *
 ***************/

MemoryInfo::MemoryInfo() 
: offset {0}
, upperOffset {0}
, lowerOffset {0}
{

}

/**********************
 * Memory map visitor *
 **********************/

MemoryMapVisitor::MemoryMapVisitor(std::ostream& output, std::ostream& log)
: mLogS {log}
, mOutputS {output}
{

}

void MemoryMapVisitor::resetOffsets() {
    mCurrentVariableOffset = -4;
    mCurrentParameterOffset = 4;
}

void MemoryMapVisitor::incrementVariableOffset() {
    mCurrentVariableOffset -= 4;
}

void MemoryMapVisitor::incrementParameterOffset() {
    mCurrentParameterOffset += 4;
}

void MemoryMapVisitor::visitUniversal(ast::Base *b) {
    // mLogS << "(universal)\n";

    for (auto node : b->getChildren()) {
        if (node != nullptr) {
            node->accept(*this);
        }
    }
}

void MemoryMapVisitor::visit(ast::Base* b) {
    visitUniversal(b);
}

void MemoryMapVisitor::visit(ast::Program* p) {
    std::string programName = p->getSymbol()->getImage();
    mLogS << "visited program node. (" << programName << ")\n";

    mFrameStack.push_back(programName);
    resetOffsets();

    visitUniversal(p);

    mFrameStack.pop_back();
}

void MemoryMapVisitor::visit(ast::Declaration* d) {
    auto currentProcedure = mFrameStack.back();
    mLogS << "visited declaration node of " << currentProcedure << ".\n";

    for (auto node : d->getChildren()) {
        auto typeNode = dynamic_cast<ast::Type*>(node);

        if (auto arrayNode = typeNode->childAsArray()) {
            std::string symbol = arrayNode->getSymbol()->getImage();
            auto &data = mProcedureToSymbolsMap[currentProcedure][symbol];
            data.isArray = true;
            data.upperOffset = mCurrentVariableOffset;
            data.lowerOffset = mCurrentVariableOffset - arrayNode->getLength() * 4;
            mCurrentVariableOffset = data.lowerOffset;
            incrementVariableOffset();
        }
                                   /* procedures don't need any space allocated */
        else if (typeNode != nullptr && typeNode->childAsProcedure() == nullptr) {
            std::string symbol = typeNode->childAsSymbol()->getImage();
            mProcedureToSymbolsMap[currentProcedure][symbol].offset = mCurrentVariableOffset;
            incrementVariableOffset();
        }
    }

    visitUniversal(d);
}

void MemoryMapVisitor::visit(ast::CompoundStatement* cs) {
    mLogS << "visited compound statement node of " << mFrameStack.back() << ".\n";

    visitUniversal(cs);
}

void MemoryMapVisitor::visit(ast::Parameters* p) {
    auto currentProcedure = mFrameStack.back();
    mLogS << "visited parameter node of " << currentProcedure << ".\n";

    for (auto node : p->getChildren()) {
        auto typeNode = dynamic_cast<ast::Type*>(node);

        if (typeNode != nullptr) {
            std::string symbol = typeNode->childAsSymbol()->getImage();
            mProcedureToSymbolsMap[currentProcedure][symbol].offset = mCurrentParameterOffset;
            incrementParameterOffset();
        }
    }

    visitUniversal(p);
}

void MemoryMapVisitor::visit(ast::Symbol* s) {
    // mLogS << "visited symbol node. (" << s->getImage() << ")\n";
    visitUniversal(s);
}

void MemoryMapVisitor::visit(ast::Type* t) {
    visitUniversal(t);
}

void MemoryMapVisitor::visit(ast::Integer* i) {
    visitUniversal(i);
}

void MemoryMapVisitor::visit(ast::Float* f) {
    visitUniversal(f);
}

void MemoryMapVisitor::visit(ast::Character* c) {
    visitUniversal(c);
}

void MemoryMapVisitor::visit(ast::Void* v) {
    visitUniversal(v);
}

void MemoryMapVisitor::visit(ast::ArrayAccess* aa) {
    visitUniversal(aa);
}

void MemoryMapVisitor::visit(ast::Array* a) {
    visitUniversal(a);
}

void MemoryMapVisitor::visit(ast::Assignment* a) {
    visitUniversal(a);
}

void MemoryMapVisitor::visit(ast::Call* c) {
    visitUniversal(c);
}

void MemoryMapVisitor::visit(ast::CaseLabels* cl) {
    visitUniversal(cl);
}

void MemoryMapVisitor::visit(ast::Case* c) {
    visitUniversal(c);
}

void MemoryMapVisitor::visit(ast::Clause* c) {
    visitUniversal(c);
}

void MemoryMapVisitor::visit(ast::Constant* c) {
    mLogS << "visited constant node. (" << c->getImage() << ")\n";
    visitUniversal(c);
}

void MemoryMapVisitor::visit(ast::Expression* e) {
    visitUniversal(e);
}

void MemoryMapVisitor::visit(ast::If* i) {
    visitUniversal(i);
}

void MemoryMapVisitor::visit(ast::Procedure* p) {
    mLogS << "visited procedure node. (" << p->getSymbol()->getImage() << ")\n";

    mFrameStack.push_back(p->getSymbol()->getImage());
    resetOffsets();

    visitUniversal(p);

    mFrameStack.pop_back();
}

void MemoryMapVisitor::visit(ast::Return* r) {
    visitUniversal(r);
}

void MemoryMapVisitor::visit(ast::Statement* s) {
    visitUniversal(s);
}

void MemoryMapVisitor::visit(ast::Variable* v) {
    visitUniversal(v);
}

void MemoryMapVisitor::visit(ast::While* w) {
    visitUniversal(w);
}

void MemoryMapVisitor::visit(ast::Write* w) {
    visitUniversal(w);
}

void MemoryMapVisitor::visit(ast::Read* r) {
    visitUniversal(r);
}

void MemoryMapVisitor::dumpOutput(std::ostream& out) {
    out << "Memory map:\n";

    for (auto mapPair : mProcedureToSymbolsMap) {
        std::string procedureName = mapPair.first;
        out << procedureName << ":" << std::endl;
        for (auto symbolPair : mProcedureToSymbolsMap[procedureName]) {
            std::string symbol = symbolPair.first;
            auto data = symbolPair.second;

            if (!data.isArray) {
                out << "  " << symbol << ":\n";
                out << "    offset: " << data.offset << std::endl;
            } else {
                // array element
                out << "  " << symbol << ":\n";
                out << "    offset: " << data.lowerOffset << " to " << data.upperOffset << std::endl;
            }
        }
    }
}