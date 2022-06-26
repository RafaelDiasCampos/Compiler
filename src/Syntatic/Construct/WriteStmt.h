#pragma once

#include "Construct.h"
#include "Writable.h"

class WriteStmt : public Construct {
public:
    WriteStmt(std::unique_ptr<Writable> writable) : writable(std::move(writable)) {}
    ~WriteStmt() {}
private:
    std::unique_ptr<Writable> writable;
};