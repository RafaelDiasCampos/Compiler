#pragma once

#include "Construct.h"

class Type : public Construct {
public:
    enum IdType {
        INT,
        FLOAT,
        CHAR
    };
    Type(IdType idType) : idType(idType) {}
    ~Type() {}
private:
    IdType idType;
};