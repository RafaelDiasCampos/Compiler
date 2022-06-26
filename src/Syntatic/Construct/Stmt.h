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
    Stmt(std::unique_ptr<AssignStmt> assignStmt) : assignStmt(std::move(assignStmt)), statementType(Assign) {}
    Stmt(std::unique_ptr<IfStmt> ifStmt) : ifStmt(std::move(ifStmt)), statementType(If) {}
    Stmt(std::unique_ptr<WhileStmt> whileStmt) : whileStmt(std::move(whileStmt)), statementType(While) {}
    Stmt(std::unique_ptr<RepeatStmt> repeatStmt) : repeatStmt(std::move(repeatStmt)), statementType(Repeat) {}
    Stmt(std::unique_ptr<ReadStmt> readStmt) : readStmt(std::move(readStmt)), statementType(Read) {}
    Stmt(std::unique_ptr<WriteStmt> writeStmt) : writeStmt(std::move(writeStmt)), statementType(Write) {}
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