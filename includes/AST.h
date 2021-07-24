#ifndef BYTECODE_H
#define BYTECODE_H
#include "lexer.h"

class AstNode {
private:

protected:
    AstNode();
public:
    virtual ~AstNode();


};

class Program: public AstNode {
public:



};
class Identifier: public AstNode {
public:


};

class Literal: public AstNode {
public:


};
class CallExpression: public AstNode {
public:



};

class BinaryExpression: public AstNode {
public:


};

class AssignmentExpression: public AstNode {
public:


};
class UpdateExpression: public AstNode {
public:


};
class LogicalExpression: public AstNode {
public:

};

class ExpressionStatement: public AstNode {
public:



};

class ReturnStatement: public AstNode {
public:


};

class BlockStatement: public AstNode {
public:


};

class VariableDeclaration: public AstNode {
public:


};
class ForStatement: public AstNode {
public:


};

class WhileStatement: public AstNode {
public:


};

class IfStatement: public AstNode {
public:

};



#endif
