#pragma once

#include "Construct.h"
#include "Type.h"
#include "IdentList.h"

class Decl : public Construct {
public:
    Decl(std::unique_ptr<Type> type, std::unique_ptr<IdentList> identList)  : type(std::move(type)), identList(std::move(identList)) {}
    ~Decl() {}
private:
    std::unique_ptr<Type> type;
    std::unique_ptr<IdentList> identList;
};