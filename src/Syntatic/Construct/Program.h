#pragma once

#include "Construct.h"
#include "Body.h"

class Program : public Construct {
public:
    Program(std::unique_ptr<Body> body) : body(std::move(body)) {}
    ~Program() {}
private:
    std::unique_ptr<Body> body;
};