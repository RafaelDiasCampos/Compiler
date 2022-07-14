#include "Syntatic.h"
#include <memory>

void SyntaticAnalyzer::print_error() {
    std::cout << "Error: Unexpected token at position " << lexic.get_file_position() << std::endl;
}

void SyntaticAnalyzer::print_error(std::string message) {
    std::cout << "Error: " << message << " at position " << lexic.get_file_position() << std::endl;
}

Token* SyntaticAnalyzer::get_next_token() {
    if (returned_token) {
        returned_token = false;
        return token_read;
    }

    token_read = lexic.get_next_token();

    while (token_read->token_type == Token::INVALID_TOKEN) {
        std::cout << "Error: Invalid token at position " << lexic.get_file_position() << std::endl;
        token_read = lexic.get_next_token();
    }

    return token_read;
}

void SyntaticAnalyzer::return_token() {
    returned_token = true; 
}

void SyntaticAnalyzer::eat_until(std::list<Token::TokenType> tokens) {
    return_token(); 
    Token* token = get_next_token();
    while ( std::find(tokens.begin(), tokens.end(), token->token_type) == tokens.end() &&
            token->token_type != Token::END_OF_FILE) {
        token = get_next_token();
    }

    return_token();   
}

std::unique_ptr<Constant> SyntaticAnalyzer::parseConstant() {
    Token* token = get_next_token();
    
    std::unique_ptr<Constant> constant;

    switch (token->token_type) {
        case Token::CONST_INT:
            constant = std::make_unique<Constant>((ValueType*) token);
            constant->semanticType = Constant::INT;
            break;
        case Token::CONST_FLOAT:
            constant = std::make_unique<Constant>((ValueType*) token);
            constant->semanticType = Constant::FLOAT;
            break;
        case Token::CONST_CHAR:
            constant = std::make_unique<Constant>((ValueType*) token);
            constant->semanticType = Constant::CHAR;
            break;
        default:
            print_error();
            eat_until(Constant::follow);
            constant = std::make_unique<Constant>((ValueType*) nullptr);
            constant->semanticType = Constant::ERROR;
            break;
    }

    return constant;
}

std::unique_ptr<MulOp> SyntaticAnalyzer::parseMulOp() {
    Token* token = get_next_token();

    std::unique_ptr<MulOp> mulOp;
    Construct::ConstructType semanticType = Constant::VOID;

    switch (token->token_type) {
        case Token::MUL:
            mulOp = std::make_unique<MulOp>(MulOp::MUL);
            break;
        case Token::DIV:
            mulOp = std::make_unique<MulOp>(MulOp::DIV);
            break;
        case Token::AND:
            mulOp = std::make_unique<MulOp>(MulOp::AND);
            break;
        default:
            print_error();
            eat_until(MulOp::follow);
            mulOp = std::make_unique<MulOp>(MulOp::MUL);
            semanticType = Constant::ERROR;
    }

    mulOp->semanticType = semanticType;
    return mulOp;
}

std::unique_ptr<AddOp> SyntaticAnalyzer::parseAddOp() {
    Token* token = get_next_token();

    std::unique_ptr<AddOp> addOp;
    Construct::ConstructType semanticType = Constant::VOID;

    switch (token->token_type) {
        case Token::ADD:
            addOp = std::make_unique<AddOp>(AddOp::ADD);
            break;
        case Token::SUB:
            addOp = std::make_unique<AddOp>(AddOp::SUB);
            break;
        case Token::OR:
            addOp = std::make_unique<AddOp>(AddOp::OR);
            break;
        default:
            print_error();
            eat_until(AddOp::follow);
            addOp = std::make_unique<AddOp>(AddOp::ADD);
            semanticType = Constant::ERROR;
    }

    addOp->semanticType = semanticType;
    return addOp;
}

std::unique_ptr<RelOp> SyntaticAnalyzer::parseRelOp() {
    Token* token = get_next_token();

    std::unique_ptr<RelOp> relOp;
    Construct::ConstructType semanticType = Constant::VOID;

    switch (token->token_type) {
        case Token::COMP_EQ:
            relOp = std::make_unique<RelOp>(RelOp::EQUALS);
            break;
        case Token::COMP_NE:
            relOp = std::make_unique<RelOp>(RelOp::NOT_EQUALS);
            break;
        case Token::COMP_GT:
            relOp = std::make_unique<RelOp>(RelOp::GREATER_THAN);
            break;
        case Token::COMP_LT:
            relOp = std::make_unique<RelOp>(RelOp::LESS_THAN);
            break;
        case Token::COMP_GE:
            relOp = std::make_unique<RelOp>(RelOp::GREATER_THAN_OR_EQUAL);
            break;
        case Token::COMP_LE:
            relOp = std::make_unique<RelOp>(RelOp::LESS_THAN_OR_EQUAL);
            break;
        default:
            print_error();
            eat_until(RelOp::follow);
            relOp = std::make_unique<RelOp>(RelOp::EQUALS);
            semanticType = Constant::ERROR;
    }

    relOp->semanticType = semanticType;
    return relOp;
}

std::unique_ptr<Factor> SyntaticAnalyzer::parseFactor() {
    Token* token = get_next_token();

    std::unique_ptr<Factor> factor;
    std::unique_ptr<Constant> constant;
    std::unique_ptr<Expression> expr;
    Construct::ConstructType semanticType;
    TokenId* id;

    switch (token->token_type) {
        case Token::ID:
            id = (TokenId*) token;
            factor = std::make_unique<Factor>(id);
            if (id->declared) {
                switch (id->value->token_type) {
                    case Token::CONST_INT:
                        semanticType = Constant::INT;
                        break;
                    case Token::CONST_FLOAT:
                        semanticType = Constant::FLOAT;
                        break;
                    case Token::CONST_CHAR:
                        semanticType = Constant::CHAR;
                        break;
                    default:
                        semanticType = Constant::ERROR;
                        break;
                }
            }
            else {
                semanticType = Constant::ERROR;
                print_error("Undeclared Variable");
            }            
            factor->semanticType = semanticType;
            break;
        case Token::CONST_INT:
        case Token::CONST_FLOAT:
        case Token::CONST_CHAR:
            return_token();

            constant = parseConstant();
            semanticType = constant->semanticType;

            factor = std::make_unique<Factor>(std::move(constant));
            break;
        case Token::OPEN_BRACES:
            expr = parseExpression();
            semanticType = expr->semanticType;

            token = get_next_token();
            if (token->token_type != Token::CLOSE_BRACES) {
                print_error();
                eat_until(Factor::follow);
                semanticType = Constant::ERROR;
            }

            factor = std::make_unique<Factor>(std::move(expr));
            break;
        default:
            print_error();
            eat_until(Factor::follow);
            factor = std::make_unique<Factor>(nullptr);
            semanticType = Construct::ERROR;
    }

    factor->semanticType = semanticType;
    return factor;
}

std::unique_ptr<FactorA> SyntaticAnalyzer::parseFactorA() {
    Token* token = get_next_token();

    std::unique_ptr<FactorA> factorA;
    std::unique_ptr<Factor> factor;
    Construct::ConstructType semanticType;

    switch (token->token_type) {
        case Token::NOT:
            factor = parseFactor();
            semanticType = factor->semanticType;
            factorA = std::make_unique<FactorA>(std::move(factor), FactorA::Not);
            break;
        case Token::SUB:
            factor = parseFactor();
            semanticType = factor->semanticType;
            factorA = std::make_unique<FactorA>(std::move(factor), FactorA::Sub);
            break;
        default:
            return_token();
            factor = parseFactor();
            semanticType = factor->semanticType;
            factorA = std::make_unique<FactorA>(std::move(factor), FactorA::Base);
    }

    factorA->semanticType = semanticType;
    return factorA;
}

std::unique_ptr<Term> SyntaticAnalyzer::parseTerm() {
    Token* token = get_next_token();

    std::unique_ptr<Term> term;
    std::unique_ptr<MulOp> mulOp;
    std::unique_ptr<FactorA> factorA;
    std::unique_ptr<Term> term_recur;
    Construct::ConstructType semanticType;

    switch (token->token_type) {
        case Token::MUL:
        case Token::DIV:
        case Token::AND:
            return_token();
            mulOp = parseMulOp();
            factorA = parseFactorA();
            term_recur = parseTerm();

            semanticType = construct_type(term_recur.get(), factorA.get());
            if (semanticType == Constant::ERROR) {
                print_error("Incompatible types");
            }

            term = std::make_unique<Term>(std::move(mulOp), std::move(factorA), std::move(term_recur));
            break;
        default:
            return_token();
            term = std::make_unique<Term>();
            semanticType = Constant::VOID;
    }

    term->semanticType = semanticType;
    return term;
}

std::unique_ptr<TermA> SyntaticAnalyzer::parseTermA() {
    std::unique_ptr<TermA> termA;
    std::unique_ptr<FactorA> factorA;
    std::unique_ptr<Term> term;
    Construct::ConstructType semanticType;

    factorA = parseFactorA();
    term  = parseTerm();
    
    semanticType = construct_type(term.get(), factorA.get());
    if (semanticType == Constant::ERROR) {
        print_error("Incompatible types");
    }

    termA = std::make_unique<TermA>(std::move(factorA), std::move(term));
    termA->semanticType = semanticType;
    return termA;
}

std::unique_ptr<SimpleExpr> SyntaticAnalyzer::parseSimpleExpr() {
    Token* token = get_next_token();

    std::unique_ptr<SimpleExpr> simpleExpr;
    std::unique_ptr<AddOp> addOp;
    std::unique_ptr<TermA> termA;
    std::unique_ptr<SimpleExpr> simpleExpr_recur;
    Construct::ConstructType semanticType;

    switch (token->token_type) {
        case Token::ADD:
        case Token::SUB:
        case Token::OR:
            return_token();
            addOp = parseAddOp();
            termA = parseTermA();
            simpleExpr_recur = parseSimpleExpr();

            semanticType = construct_type(termA.get(), simpleExpr_recur.get());
            if (semanticType == Constant::ERROR) {
                print_error("Incompatible types");
            }
            simpleExpr = std::make_unique<SimpleExpr>(std::move(addOp), std::move(termA), std::move(simpleExpr_recur));
            break;
        default:
            return_token();
            simpleExpr = std::make_unique<SimpleExpr>();
            semanticType = Construct::VOID;
    }

    simpleExpr->semanticType = semanticType;
    return simpleExpr;
}

std::unique_ptr<SimpleExprA> SyntaticAnalyzer::parseSimpleExprA() {
    std::unique_ptr<SimpleExprA> simpleExprA;
    std::unique_ptr<TermA> termA;
    std::unique_ptr<SimpleExpr> simpleExpr;
    Construct::ConstructType semanticType;

    termA  = parseTermA();
    simpleExpr = parseSimpleExpr();
    
    semanticType = construct_type(termA.get(), simpleExpr.get());
    if (semanticType == Constant::ERROR) {
        print_error("Incompatible types");
    }

    simpleExprA = std::make_unique<SimpleExprA>(std::move(termA), std::move(simpleExpr));
    simpleExprA->semanticType = semanticType;
    return simpleExprA;
}

std::unique_ptr<Expression> SyntaticAnalyzer::parseExpression() {
    std::unique_ptr<Expression> expression;
    std::unique_ptr<SimpleExprA> simpleExprA;
    std::unique_ptr<RelOp> relOp;
    std::unique_ptr<SimpleExprA> simpleExprB;
    Construct::ConstructType semanticType;

    simpleExprA = parseSimpleExprA();
    Token* token = get_next_token();

    switch (token->token_type) {
        case Token::COMP_EQ:
        case Token::COMP_NE:
        case Token::COMP_GT:
        case Token::COMP_LT:
        case Token::COMP_GE:
        case Token::COMP_LE:
            return_token();
            relOp = parseRelOp();
            simpleExprB = parseSimpleExprA();

            semanticType = construct_type(simpleExprA.get(), simpleExprB.get());
            if (semanticType == Constant::ERROR) {
                print_error("Incompatible types");
            }
            expression = std::make_unique<Expression>(std::move(simpleExprA), std::move(relOp), std::move(simpleExprB));
            break;
        default:
            return_token();
            semanticType = simpleExprA->semanticType;
            expression = std::make_unique<Expression>(std::move(simpleExprA));
    }

    expression->semanticType = semanticType;
    return expression;
}

std::unique_ptr<Writable> SyntaticAnalyzer::parseWritable() {
    Token* token = get_next_token();

    std::unique_ptr<Writable> writable;
    std::unique_ptr<SimpleExprA> simpleExprA;
    Construct::ConstructType semanticType;

    switch (token->token_type) {
        case Token::CONST_STRING:
            writable = std::make_unique<Writable>((TokenConstString*) token);
            semanticType = Construct::VOID;
            break;
        case Token::ID:
        case Token::OPEN_BRACES:
        case Token::NOT:
        case Token::SUB:        
        case Token::CONST_INT:
        case Token::CONST_FLOAT:
        case Token::CONST_CHAR:
            return_token();
            simpleExprA = parseSimpleExprA();
            semanticType = simpleExprA->semanticType;
            writable = std::make_unique<Writable>(std::move(simpleExprA));
            break;
        default:
            print_error();
            eat_until(Writable::follow);
            writable = std::make_unique<Writable>(nullptr);
            semanticType = Construct::ERROR;
    }

    writable->semanticType = semanticType;
    return writable;
}

std::unique_ptr<WriteStmt> SyntaticAnalyzer::parseWriteStmt() {
    Token* token = get_next_token();

    std::unique_ptr<WriteStmt> writeStmt;
    std::unique_ptr<Writable> writable;
    Construct::ConstructType semanticType;

    if (token->token_type != Token::WRITE) {
        print_error();
        eat_until(WriteStmt::follow);
        writeStmt = std::make_unique<WriteStmt>(nullptr);
        writeStmt->semanticType = Construct::ERROR;
        return writeStmt;
    }

    token = get_next_token();
    if (token->token_type != Token::OPEN_BRACES) {
        print_error();
        eat_until(WriteStmt::follow);
        writeStmt = std::make_unique<WriteStmt>(nullptr);
        writeStmt->semanticType = Construct::ERROR;
        return writeStmt;
    }

    writable = parseWritable();
    semanticType = writable->semanticType;
    writeStmt = std::make_unique<WriteStmt>(std::move(writable));

    token = get_next_token();
    if (token->token_type != Token::CLOSE_BRACES) {
        print_error();
        eat_until(WriteStmt::follow);
        semanticType = Construct::ERROR;
    }

    writeStmt->semanticType = semanticType;
    return writeStmt;
}

std::unique_ptr<ReadStmt> SyntaticAnalyzer::parseReadStmt() {
    Token* token = get_next_token();

    std::unique_ptr<ReadStmt> readStmt;
    Construct::ConstructType semanticType;

    if (token->token_type != Token::READ) {
        print_error();
        eat_until(ReadStmt::follow);
        readStmt = std::make_unique<ReadStmt>(nullptr);
        readStmt->semanticType = Construct::ERROR;
        return readStmt;
    }

    token = get_next_token();
    if (token->token_type != Token::OPEN_BRACES) {
        print_error();
        eat_until(ReadStmt::follow);
        readStmt = std::make_unique<ReadStmt>(nullptr);
        readStmt->semanticType = Construct::ERROR;
        return readStmt;
    }

    token = get_next_token();
    if (token->token_type != Token::ID) {
        print_error();
        eat_until(ReadStmt::follow);
        readStmt = std::make_unique<ReadStmt>(nullptr);
        readStmt->semanticType = Construct::ERROR;
        return readStmt;
    }

    readStmt = std::make_unique<ReadStmt>((TokenId*) token);
    semanticType = Construct::VOID;

    token = get_next_token();
    if (token->token_type != Token::CLOSE_BRACES) {
        print_error();
        eat_until(ReadStmt::follow);
        semanticType = Construct::ERROR;
    }

    readStmt->semanticType = semanticType;
    return readStmt;
}

std::unique_ptr<StmtPrefix> SyntaticAnalyzer::parseStmtPrefix() {
    Token* token = get_next_token();
    
    std::unique_ptr<StmtPrefix> stmtPrefix;
    Construct::ConstructType semanticType;

    if (token->token_type != Token::WHILE) {
        print_error();
        eat_until(StmtPrefix::follow);
        stmtPrefix = std::make_unique<StmtPrefix>(nullptr);
        stmtPrefix->semanticType = Construct::ERROR;
        return stmtPrefix;
    }

    std::unique_ptr<Condition> condition = parseCondition();

    token = get_next_token();
    if (token->token_type != Token::DO) {
        print_error();
        eat_until(StmtPrefix::follow);
        stmtPrefix = std::make_unique<StmtPrefix>(nullptr);
        stmtPrefix->semanticType = Construct::ERROR;
        return stmtPrefix;
    }

    semanticType = condition->semanticType;
    stmtPrefix = std::make_unique<StmtPrefix>(std::move(condition));
    stmtPrefix->semanticType = semanticType;
    return stmtPrefix;
}

std::unique_ptr<WhileStmt> SyntaticAnalyzer::parseWhileStmt() {
    std::unique_ptr<WhileStmt> whileStmt;
    std::unique_ptr<StmtPrefix> stmtPrefix = parseStmtPrefix();
    std::unique_ptr<StmtList> stmtList = parseStmtList();
    Construct::ConstructType semanticType;

    Token* token = get_next_token();
    if (token->token_type != Token::END) {
        print_error();
        eat_until(WhileStmt::follow);
        whileStmt = std::make_unique<WhileStmt>(nullptr, nullptr);
        whileStmt->semanticType = Construct::ERROR;
        return whileStmt;
    }

    semanticType = Construct::VOID;
    if (stmtPrefix->semanticType == Construct::ERROR || stmtList->semanticType == Construct::ERROR) {
        semanticType = Construct::ERROR;
    }
    whileStmt = std::make_unique<WhileStmt>(std::move(stmtPrefix), std::move(stmtList));
    whileStmt->semanticType = semanticType;
    return whileStmt;
}

std::unique_ptr<StmtSuffix> SyntaticAnalyzer::parseStmtSuffix() {
    Token* token = get_next_token();

    std::unique_ptr<StmtSuffix> stmtSuffix;
    std::unique_ptr<Condition> condition;
    Construct::ConstructType semanticType;

    if (token->token_type != Token::UNTIL) {
        print_error();
        eat_until(StmtSuffix::follow);
        stmtSuffix = std::make_unique<StmtSuffix>(nullptr);
        stmtSuffix->semanticType = Construct::ERROR;
        return stmtSuffix;
    }

    condition = parseCondition();
    semanticType = condition->semanticType;
    stmtSuffix = std::make_unique<StmtSuffix>(std::move(condition));
    stmtSuffix->semanticType = semanticType;
    return stmtSuffix;
}

std::unique_ptr<RepeatStmt> SyntaticAnalyzer::parseRepeatStmt() {
    Token* token = get_next_token();

    std::unique_ptr<RepeatStmt> repeatStmt;
    Construct::ConstructType semanticType;

    if (token->token_type != Token::REPEAT) {
        print_error();
        eat_until(RepeatStmt::follow);
        repeatStmt = std::make_unique<RepeatStmt>(nullptr, nullptr);
        repeatStmt->semanticType = Construct::ERROR;
        return repeatStmt;
    }

    std::unique_ptr<StmtList> stmtList = parseStmtList();
    std::unique_ptr<StmtSuffix> stmtSuffix = parseStmtSuffix();

    semanticType = Construct::VOID;
    if (stmtList->semanticType == Construct::ERROR || stmtSuffix->semanticType == Construct::ERROR) {
        semanticType = Construct::ERROR;
    }    
    repeatStmt = std::make_unique<RepeatStmt>(std::move(stmtList), std::move(stmtSuffix));
    repeatStmt->semanticType = semanticType;
    return repeatStmt;
}

std::unique_ptr<Condition> SyntaticAnalyzer::parseCondition() {
    std::unique_ptr<Condition> condition;
    std::unique_ptr<Expression> expression;
    Construct::ConstructType semanticType;
    
    expression = parseExpression();
    semanticType = expression->semanticType;
    condition = std::make_unique<Condition>(std::move(expression));
    condition->semanticType = semanticType;
    return condition;
}

std::unique_ptr<IfStmt> SyntaticAnalyzer::parseIfStmt() {
    Token* token = get_next_token();

    std::unique_ptr<IfStmt> ifStmt;
    std::unique_ptr<StmtList> trueStmtList;
    std::unique_ptr<StmtList> falseStmtList;
    Construct::ConstructType semanticType = Construct::VOID;

    if (token->token_type != Token::IF) {
        print_error();
        eat_until(IfStmt::follow);
        ifStmt = std::make_unique<IfStmt>(nullptr, nullptr, nullptr);
        ifStmt->semanticType = Construct::ERROR;
        return ifStmt;
    }

    std::unique_ptr<Condition> condition = parseCondition();
    if (condition->semanticType == Construct::ERROR) {
        semanticType = Construct::ERROR;
    }

    token = get_next_token();
    if (token->token_type != Token::THEN) {
        print_error();
        eat_until(IfStmt::follow);
        ifStmt = std::make_unique<IfStmt>(nullptr, nullptr, nullptr);
        ifStmt->semanticType = Construct::ERROR;
        return ifStmt;
    }

    trueStmtList = parseStmtList();
    if (trueStmtList->semanticType == Construct::ERROR) {
        semanticType = Construct::ERROR;
    }

    token = get_next_token();
    switch (token->token_type) {
        case Token::END:
            ifStmt = std::make_unique<IfStmt>(std::move(condition), std::move(trueStmtList));
            break;
        case Token::ELSE:
            falseStmtList = parseStmtList();
            if (falseStmtList->semanticType == Construct::ERROR) {
                semanticType = Construct::ERROR;
            }
            token = get_next_token();
            if (token->token_type != Token::END) {
                print_error();
                eat_until(IfStmt::follow);
                return nullptr;
            }
            ifStmt = std::make_unique<IfStmt>(std::move(condition), std::move(trueStmtList), std::move(falseStmtList));    
            break;
        default:
            print_error();
            eat_until(IfStmt::follow);
            ifStmt = std::make_unique<IfStmt>(nullptr, nullptr, nullptr);
            semanticType = Construct::ERROR;
    }

    ifStmt->semanticType = semanticType;
    return ifStmt;
}

std::unique_ptr<AssignStmt> SyntaticAnalyzer::parseAssignStmt() {
    Token* token = get_next_token();

    std::unique_ptr<AssignStmt> assignStmt;
    std::unique_ptr<SimpleExprA> simpleExprA;
    Construct::ConstructType semanticType;

    if (token->token_type != Token::ID) {
        print_error();
        eat_until(AssignStmt::follow);
        assignStmt = std::make_unique<AssignStmt>(nullptr, nullptr);
        assignStmt->semanticType = Construct::ERROR;
        return assignStmt;
    }

    TokenId* id = (TokenId*) token;

    token = get_next_token();
    if (token->token_type != Token::ASSIGN) {
        print_error();
        eat_until(AssignStmt::follow);
        assignStmt = std::make_unique<AssignStmt>(nullptr, nullptr);
        assignStmt->semanticType = Construct::ERROR;
        return assignStmt;
    }

    simpleExprA = parseSimpleExprA();
    semanticType = simpleExprA->semanticType;

    
    if (id->declared) {
        switch (id->value->token_type) {
            case Token::CONST_INT:
                if (simpleExprA->semanticType != Construct::INT) {
                    print_error("Incompatible types");
                    semanticType = Construct::ERROR;
                }
                break;
            case Token::CONST_FLOAT:
                if (simpleExprA->semanticType != Construct::INT && simpleExprA->semanticType != Construct::FLOAT) {
                    print_error("Incompatible types");
                    semanticType = Construct::ERROR;
                }
                break;
            case Token::CONST_CHAR:
                if (simpleExprA->semanticType != Construct::CHAR) {
                    print_error("Incompatible types");
                    semanticType = Construct::ERROR;
                }
                break;
            default:
                semanticType = Construct::ERROR;
        }
    }
    else {
        semanticType = Constant::ERROR;
        print_error("Undeclared Variable");
    }

    assignStmt = std::make_unique<AssignStmt>(id, std::move(simpleExprA));
    assignStmt->semanticType = semanticType;
    return assignStmt;
}

std::unique_ptr<Stmt> SyntaticAnalyzer::parseStmt() {
    Token* token = get_next_token();

    std::unique_ptr<Stmt> stmt;
    std::unique_ptr<AssignStmt> assignStmt;
    std::unique_ptr<ReadStmt> readStmt;
    std::unique_ptr<WriteStmt> writeStmt;
    std::unique_ptr<IfStmt> ifStmt;
    std::unique_ptr<WhileStmt> whileStmt;
    std::unique_ptr<RepeatStmt> repeatStmt;
    Construct::ConstructType semanticType;

    return_token();
    switch (token->token_type) {
        case Token::ID:
            assignStmt = parseAssignStmt();
            semanticType = assignStmt->semanticType;
            stmt = std::make_unique<Stmt>(std::move(assignStmt));
            break;
        case Token::READ:
            readStmt = parseReadStmt();
            semanticType = readStmt->semanticType;
            stmt = std::make_unique<Stmt>(std::move(readStmt));
            break;
        case Token::WRITE:
            writeStmt = parseWriteStmt();
            semanticType = writeStmt->semanticType;
            stmt = std::make_unique<Stmt>(std::move(writeStmt));
            break;
        case Token::IF:
            ifStmt = parseIfStmt();
            semanticType = ifStmt->semanticType;
            stmt = std::make_unique<Stmt>(std::move(ifStmt));
            break;
        case Token::WHILE:
            whileStmt = parseWhileStmt();
            semanticType = whileStmt->semanticType;
            stmt = std::make_unique<Stmt>(std::move(whileStmt));
            break;
        case Token::REPEAT:
            repeatStmt = parseRepeatStmt();
            semanticType = repeatStmt->semanticType;
            stmt = std::make_unique<Stmt>(std::move(repeatStmt));
            break;    
        default:
            print_error();
            eat_until(Stmt::follow);
            stmt = std::make_unique<Stmt>(std::unique_ptr<AssignStmt>(nullptr));
            semanticType = Construct::ERROR;
    }

    stmt->semanticType = semanticType;
    return stmt;
}

std::unique_ptr<StmtList> SyntaticAnalyzer::parseStmtList() {
    std::unique_ptr<Stmt> stmt;
    std::list<std::unique_ptr<Stmt>> listStmts;
    std::unique_ptr<StmtList> stmtList;
    Construct::ConstructType semanticType = Construct::VOID;

    stmt = parseStmt();
    if (stmt->semanticType == Construct::ERROR) {
        semanticType = Construct::ERROR;
    }
    listStmts.push_back(std::move(stmt));

    Token* token = get_next_token();
    while (token->token_type == Token::SEMICOLON) {
        stmt = parseStmt();
        if (stmt->semanticType == Construct::ERROR) {
            semanticType = Construct::ERROR;
        }
        listStmts.push_back(std::move(stmt));
        token = get_next_token();
    }
    return_token();

    stmtList = std::make_unique<StmtList>(std::move(listStmts));
    stmtList->semanticType = semanticType;
    return stmtList;
}

std::unique_ptr<Type> SyntaticAnalyzer::parseType() {
    Token* token = get_next_token();

    std::unique_ptr<Type> type;
    Construct::ConstructType semanticType;

    switch (token->token_type) {
        case Token::INT:
            type = std::make_unique<Type>(Type::INT);
            semanticType = Construct::INT;
            break;
        case Token::FLOAT:
            type = std::make_unique<Type>(Type::FLOAT);
            semanticType = Construct::FLOAT;
            break;
        case Token::CHAR:
            type = std::make_unique<Type>(Type::CHAR);
            semanticType = Construct::CHAR;
            break;
        default:
            print_error();
            eat_until(Type::follow);
            type = std::make_unique<Type>(Type::INT);
            semanticType = Construct::ERROR;
    }

    type->semanticType = semanticType;
    return type;
}

std::unique_ptr<IdentList> SyntaticAnalyzer::parseIdentList() {
    std::list<TokenId*> listIdent;
    std::unique_ptr<IdentList> identList;
    Construct::ConstructType semanticType = Construct::VOID;

    Token* token = get_next_token();
    TokenId* id;

    if (token->token_type != Token::ID) {
        print_error();
        eat_until(IdentList::follow);
        identList = std::make_unique<IdentList>(std::move(listIdent));
        identList->semanticType = Construct::ERROR;
        return identList;
    }
    
    id = (TokenId*) token;
    if (id->declared) {
        print_error("Duplicate Identifier");
        semanticType = Construct::ERROR;
    }
    listIdent.push_back(id);

    token = get_next_token();
    while (token->token_type == Token::COMMA) {
        token = get_next_token();
        if (token->token_type != Token::ID) {
            print_error();
            eat_until(IdentList::follow);
            identList = std::make_unique<IdentList>(std::move(listIdent));
            identList->semanticType = Construct::ERROR;
            return identList;
        }
        id = (TokenId*) token;
        if (id->declared) {
            print_error("Duplicate Identifier");
            semanticType = Construct::ERROR;
        }
        listIdent.push_back(id);
        token = get_next_token();
    }
    return_token();

    identList = std::make_unique<IdentList>(std::move(listIdent));
    identList->semanticType = semanticType;
    return identList;
}

std::unique_ptr<Decl> SyntaticAnalyzer::parseDecl() {
    std::unique_ptr<Decl> decl;
    std::unique_ptr<Type> type = parseType();
    std::unique_ptr<IdentList> identList = parseIdentList();
    Construct::ConstructType semanticType = Construct::VOID;

    if (type->semanticType == Construct::ERROR || identList->semanticType == Construct::ERROR) {
        semanticType = Construct::ERROR;
    }

    if (type->semanticType == Construct::INT) {
        identList->set_type(Token::CONST_INT);
    } else if (type->semanticType == Construct::FLOAT) {
        identList->set_type(Token::CONST_FLOAT);
    } else if (type->semanticType == Construct::CHAR) {
        identList->set_type(Token::CONST_CHAR);
    } else {
        semanticType = Construct::ERROR;
    }    

    decl = std::make_unique<Decl>(std::move(type), std::move(identList));
    decl->semanticType = semanticType;
    return decl;
}

std::unique_ptr<DeclList> SyntaticAnalyzer::parseDeclList() {
    std::unique_ptr<Decl> decl;
    std::list<std::unique_ptr<Decl>> listDecl;
    std::unique_ptr<DeclList> declList;
    Construct::ConstructType semanticType = Construct::VOID;

    Token* token = get_next_token();
    if (token->token_type != Token::DECLARE) {
        print_error();
        eat_until(DeclList::follow);
        declList = std::make_unique<DeclList>(std::move(listDecl));
    }

    decl = parseDecl();
    if (decl->semanticType == Construct::ERROR) {
        semanticType = Construct::ERROR;
    }
    listDecl.push_back(std::move(decl));
    
    token = get_next_token();
    if (token->token_type != Token::SEMICOLON) {
        print_error();
        eat_until(DeclList::follow);
        declList = std::make_unique<DeclList>(std::move(listDecl));
        declList->semanticType = Construct::ERROR;
        return declList;
    }

    token = get_next_token();
    while (true) {
        switch (token->token_type) {
            case Token::INT:
            case Token::FLOAT:
            case Token::CHAR:
                return_token();
                decl = parseDecl();
                if (decl->semanticType == Construct::ERROR) {
                    semanticType = Construct::ERROR;
                }
                listDecl.push_back(std::move(decl));
                break;
            default:
                return_token();
                declList = std::make_unique<DeclList>(std::move(listDecl));
                declList->semanticType = semanticType;
                return declList;
        }

        token = get_next_token();
        if (token->token_type != Token::SEMICOLON) {
            print_error();
            eat_until(DeclList::follow);
            declList = std::make_unique<DeclList>(std::move(listDecl));
            declList->semanticType = Construct::ERROR;
            return declList;
        }

        token = get_next_token();
    }
}

std::unique_ptr<Body> SyntaticAnalyzer::parseBody() {
    Token* token = get_next_token();

    std::unique_ptr<Body> body;
    std::unique_ptr<DeclList> declList;
    std::unique_ptr<StmtList> stmtList;
    Construct::ConstructType semanticType = Construct::VOID;

    if (token->token_type != Token::BEGIN) {
        return_token();
        declList = parseDeclList();
        
        token = get_next_token();
        if (token->token_type != Token::BEGIN) {
            print_error();
            eat_until(Body::follow);
            body = std::make_unique<Body>(nullptr);
            body->semanticType = Construct::ERROR;
            return body;
        }

        std::unique_ptr<StmtList> stmtList = parseStmtList();
        token = get_next_token();
        if (token->token_type != Token::END) {
            print_error();
            eat_until(Body::follow);
            body = std::make_unique<Body>(nullptr);
            body->semanticType = Construct::ERROR;
            return body;
        }

        if (declList->semanticType == Construct::ERROR || stmtList->semanticType == Construct::ERROR) {
            semanticType = Construct::ERROR;
        }
        body =  std::make_unique<Body>(std::move(declList), std::move(stmtList));
        body->semanticType = semanticType;
        return body;
    }

    stmtList = parseStmtList();
    token = get_next_token();
    if (token->token_type != Token::END) {
        print_error();
        eat_until(Body::follow);
        body = std::make_unique<Body>(nullptr, nullptr);
        body->semanticType = Construct::ERROR;
        return body;
    }

    if (stmtList->semanticType == Construct::ERROR) {
        semanticType = Construct::ERROR;
    }
    body = std::make_unique<Body>(std::move(stmtList));
    body->semanticType = semanticType;
    return body;
}

std::unique_ptr<Program> SyntaticAnalyzer::parseProgram() {
    Token* token = get_next_token();

    std::unique_ptr<Program> program;
    std::unique_ptr<Body> body;
    Construct::ConstructType semanticType = Construct::VOID;

    if (token->token_type != Token::ROUTINE) {
        print_error();
        eat_until(Program::follow);
        program = std::make_unique<Program>(nullptr);
        semanticType = Construct::ERROR;
    }

    body = parseBody();
    if (body->semanticType == Construct::ERROR) {
        semanticType = Construct::ERROR;
    }
    program = std::make_unique<Program>(std::move(body));
    program->semanticType = semanticType;
    return program;
}

Construct::ConstructType SyntaticAnalyzer::construct_type(Construct* constructA, Construct* constructB) {
    if (constructA->semanticType == Construct::ERROR || constructB->semanticType == Construct::ERROR) {
        return Construct::VOID;
    }

    switch (constructA->semanticType) {
        case Constant::INT:
            if (constructB->semanticType != Constant::INT && constructB->semanticType != Constant::VOID) {
                return Constant::ERROR;
            }
            return Constant::INT;
            break;
        case Constant::FLOAT:
            if (constructB->semanticType != Constant::INT && constructB->semanticType != Constant::FLOAT && constructB->semanticType != Constant::VOID) {
                return Constant::ERROR;
            }
            return Constant::FLOAT;
            break;
        case Constant::CHAR:
            if (constructB->semanticType != Constant::CHAR && constructB->semanticType != Constant::VOID) {
                return Constant::ERROR;
            }
            return Constant::CHAR;
            break;
        default:
            return constructB->semanticType;
            break;
    }

    return Construct::ERROR;
}