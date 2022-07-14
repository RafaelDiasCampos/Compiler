#pragma once

#include <list>
#include "../../Lexic/Lexic.h"

class Construct {
public:
    enum ConstructType {
        INT,
        FLOAT,
        CHAR,
        ERROR,
        VOID
    };
    Construct() {};
    ~Construct() {}

    ConstructType semanticType = ERROR;
};