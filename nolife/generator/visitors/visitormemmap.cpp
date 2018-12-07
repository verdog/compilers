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
, type {ast::Type::Types::Undefined}
, isArray {false}
, lowBoundString {""}
{

}

/**********************
 * Memory map visitor *
 **********************/

MemoryMapVisitor::MemoryMapVisitor(std::ostream& output, std::ostream& log)
: mLogS {log}
, mOutputS {output}
{
    mCurrentConstantOffset = 0;
}

void MemoryMapVisitor::resetOffsets() {
    mCurrentVariableOffset = -4;
    mCurrentParameterOffset = 0;
}

void MemoryMapVisitor::incrementVariableOffset() {
    mCurrentVariableOffset -= 4;
}

void MemoryMapVisitor::incrementParameterOffset() {
    mCurrentParameterOffset += 4;
}

void MemoryMapVisitor::incrementConstantOffset(int amount) {
    mCurrentConstantOffset += amount;
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
    // mLogS << "visited program node. (" << programName << ")\n";

    mFrameStack.push_back("main");
    resetOffsets();

    visitUniversal(p);

    mFrameStack.pop_back();
    mDone = true;
}

void MemoryMapVisitor::visit(ast::Declaration* d) {
    auto currentProcedure = mFrameStack.back();
    // mLogS << "visited declaration node of " << currentProcedure << ".\n";

    for (auto node : d->getChildren()) {
        auto typeNode = dynamic_cast<ast::Type*>(node);

        if (auto arrayNode = typeNode->childAsArray()) {
            std::string symbol = arrayNode->getSymbol()->getImage();
            auto &data = mProcedureToSymbolsMap[currentProcedure][symbol];
            data.isArray = true;
            data.upperOffset = mCurrentVariableOffset + 4;
            data.lowerOffset = mCurrentVariableOffset + 4 - arrayNode->getLength() * 4;
            data.offset = data.lowerOffset;
            data.lowBoundString = arrayNode->getLowBound()->getImage();
            data.type = typeNode->getType();
            mCurrentVariableOffset = data.lowerOffset;
            incrementVariableOffset();
        }
                                   /* procedures don't need any space allocated */
        else if (typeNode != nullptr && typeNode->childAsProcedure() == nullptr) {
            std::string symbol = typeNode->childAsSymbol()->getImage();
            mProcedureToSymbolsMap[currentProcedure][symbol].offset = mCurrentVariableOffset;
            mProcedureToSymbolsMap[currentProcedure][symbol].type = typeNode->getType();
            incrementVariableOffset();
        }
    }

    visitUniversal(d);
}

void MemoryMapVisitor::visit(ast::CompoundStatement* cs) {
    // mLogS << "visited compound statement node of " << mFrameStack.back() << ".\n";

    visitUniversal(cs);
}

void MemoryMapVisitor::visit(ast::Parameters* p) {
    auto currentProcedure = mFrameStack.back();
    // mLogS << "visited parameter node of " << currentProcedure << ".\n";

    for (auto node : p->getChildren()) {
        auto typeNode = dynamic_cast<ast::Type*>(node);

        if (typeNode != nullptr) {
            if (typeNode->childAsSymbol()) {
                std::string symbol = typeNode->childAsSymbol()->getImage();
                mProcedureToSymbolsMap[currentProcedure][symbol].offset = mCurrentParameterOffset;
                mProcedureToSymbolsMap[currentProcedure][symbol].type = typeNode->getType();
                incrementParameterOffset();
            } else if (auto arrayNode = typeNode->childAsArray()) {
                std::string symbol = arrayNode->getSymbol()->getImage();
                auto &info = mProcedureToSymbolsMap[currentProcedure][symbol];
                info.offset = mCurrentParameterOffset;
                info.type = typeNode->getType();
                info.isArray = true;
                info.lowBoundString = arrayNode->getLowBound()->getImage();
                info.lowerOffset = mCurrentParameterOffset;
                info.upperOffset = mCurrentParameterOffset;

                incrementParameterOffset();
            }
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
    // mLogS << "visited constant node. (" << c->getImage() << ")\n";

    auto image = c->getImage();
    auto type = c->getType();
    // mLogS << "  type: " << ast::typeToString(type) << std::endl;

    if (mConstantMap.count(image) < 1) {
        if (type == ast::Type::Types::Integer) {
            // do nothing, int constants can be stored in operations.
        } else if (type == ast::Type::Types::Float) {
            MemoryInfo info;
            info.offset = mCurrentConstantOffset;
            info.type = ast::Type::Types::Float;
            mConstantMap[image] = info;
            incrementConstantOffset(4);

        } else if (type == ast::Type::Types::Character) {
            // do nothing, char constants can be stored in operations.
        } else if (type == ast::Type::Types::StringConstant) {
            MemoryInfo info;
            info.offset = mCurrentConstantOffset;
            info.type = ast::Type::Types::StringConstant;
            mConstantMap[image] = info;

            // get word length
            int length = c->getImage().size() - 2 + 1; // minus two single quotes, plus space for a null
            incrementConstantOffset(length);

        } else {
            // Void or Undefined
            // should never happen
            mLogS << "ERROR: Constant \"" << c->getImage() << "\" appears to have type of " << ast::typeToString(type) << ".\n";
        }
    } else {
        // we have already stored this constant somewhere. do nothing
        // mLogS << "detected repeated constant: " << image << std::endl;
    }

    visitUniversal(c);
}

void MemoryMapVisitor::visit(ast::Expression* e) {
    visitUniversal(e);
}

void MemoryMapVisitor::visit(ast::If* i) {
    visitUniversal(i);
}

void MemoryMapVisitor::visit(ast::Procedure* p) {
    // mLogS << "visited procedure node. (" << p->getSymbol()->getImage() << ")\n";

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

    out << "Constants:\n";

    for (auto mapPair : mConstantMap) {
        std::string label = mapPair.first;
        int offset = mapPair.second.offset;
        out << "  " << label << ": " << offset << std::endl;
    }

    out << "Procedure locals:\n";

    for (auto mapPair : mProcedureToSymbolsMap) {
        std::string procedureName = mapPair.first;
        out << procedureName << ":" << std::endl;
        for (auto symbolPair : mProcedureToSymbolsMap[procedureName]) {
            std::string symbol = symbolPair.first;
            auto data = symbolPair.second;

            if (!data.isArray) {
                out << "  " << symbol << ":\n";
                out << "    offset: " << data.offset << std::endl;
                out << "    type: " << ast::typeToString(data.type) << std::endl;
            } else {
                // array element
                out << "  " << symbol << ":\n";
                out << "    offset: " << data.lowerOffset << " to " << data.upperOffset << std::endl;
                out << "    low bound: " << data.lowBoundString << std::endl;
                out << "    type: " << ast::typeToString(data.type) << std::endl;
            }
        }
    }
}