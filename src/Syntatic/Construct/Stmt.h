#pragma once

class Stmt;

#include "Construct.h"
#include "AssignStmt.h"
#include "IfStmt.h"
#include "WhileStmt.h"
#include "RepeatStmt.h"
#include "ReadStmt.h"
#include "WriteStmt.h"

class Stmt : public Construct {
public:
    enum StatementType {
        Assign,
        If,
        While,
        Repeat,
        Read,
        Write
    };
    Stmt(std::unique_ptr<AssignStmt> assignStmt) : statementType(Assign), assignStmt(std::move(assignStmt)) {}
    Stmt(std::unique_ptr<IfStmt> ifStmt) : statementType(If), ifStmt(std::move(ifStmt)) {}
    Stmt(std::unique_ptr<WhileStmt> whileStmt) : statementType(While), whileStmt(std::move(whileStmt)) {}
    Stmt(std::unique_ptr<RepeatStmt> repeatStmt) : statementType(Repeat), repeatStmt(std::move(repeatStmt)) {}
    Stmt(std::unique_ptr<ReadStmt> readStmt) : statementType(Read), readStmt(std::move(readStmt)) {}
    Stmt(std::unique_ptr<WriteStmt> writeStmt) : statementType(Write), writeStmt(std::move(writeStmt)) {}
    ~Stmt() {}
private:
    StatementType statementType;
    std::unique_ptr<AssignStmt> assignStmt;
    std::unique_ptr<IfStmt> ifStmt;
    std::unique_ptr<WhileStmt> whileStmt;
    std::unique_ptr<RepeatStmt> repeatStmt;
    std::unique_ptr<ReadStmt> readStmt;
    std::unique_ptr<WriteStmt> writeStmt;
};