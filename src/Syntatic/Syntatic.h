#pragma once

#include <iostream>
#include "../Lexic/Lexic.h"
#include "../Syntatic/Construct/Program.h"

class SyntaticAnalyzer {
    public:
    SyntaticAnalyzer(std::string filename) : lexic(filename) {};
    ~SyntaticAnalyzer() {}

    std::unique_ptr<Program> parseProgram();

    private:
    LexicAnalyzer lexic;
    Token* token_read;
    bool returned_token = false;

    Token* getNextToken();
    void returnToken();
    void printError();
    
    std::unique_ptr<Body> parseBody();
    std::unique_ptr<DeclList> parseDeclList();
    std::unique_ptr<Decl> parseDecl();
    std::unique_ptr<IdentList> parseIdentList();
    std::unique_ptr<Type> parseType();
    std::unique_ptr<StmtList> parseStmtList();
    std::unique_ptr<Stmt> parseStmt();
    std::unique_ptr<AssignStmt> parseAssignStmt();
    std::unique_ptr<IfStmt> parseIfStmt();
    std::unique_ptr<Condition> parseCondition();
    std::unique_ptr<RepeatStmt> parseRepeatStmt();
    std::unique_ptr<StmtSuffix> parseStmtSuffix();
    std::unique_ptr<WhileStmt> parseWhileStmt();
    std::unique_ptr<StmtPrefix> parseStmtPrefix();
    std::unique_ptr<ReadStmt> parseReadStmt();
    std::unique_ptr<WriteStmt> parseWriteStmt();
    std::unique_ptr<Writable> parseWritable();
    std::unique_ptr<Expression> parseExpression();
    std::unique_ptr<SimpleExprA> parseSimpleExprA();
    std::unique_ptr<SimpleExpr> parseSimpleExpr();
    std::unique_ptr<TermA> parseTermA();
    std::unique_ptr<Term> parseTerm();
    std::unique_ptr<FactorA> parseFactorA();
    std::unique_ptr<Factor> parseFactor();
    std::unique_ptr<RelOp> parseRelOp();
    std::unique_ptr<AddOp> parseAddOp();
    std::unique_ptr<MulOp> parseMulOp();
    std::unique_ptr<Constant> parseConstant();
};