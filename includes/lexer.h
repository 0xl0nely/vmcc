#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <vector>
#include <map>
#include "util.h"

// gives us a good idea of what initial state to jump to

enum class TOKEN_ENUMERATION {
    /* statements */
    IF, ELSE, ELIF, RETURN, WHILE, FOR, STRUCT, TYPEDEF, ENUM, SWITCH, CASE, DEFAULT, GOTO,

    /* bool */
    TRUE, FALSE,

    /* literals */
    INTEGER, LONG, CHAR, LITERAL_INTEGER, LITERAL_HEX, LITERAL_STRING, LITERAL_CHAR,

    /* identifier */
    IDENTIFIER,
    
    /* operators */
    ADD, SUB, DIV, MUL, ASSIGN, MOD, EQUALS, NOT_EQUALS, INC, DEC, APPEND_ADD, APPEND_SUB, APPEND_DIV,
    APPEND_MUL, LESS, GREATER, LESS_E, GREATER_E, NOT, XOR, AND, OR, ANDAND, OROR,

    /* expressions */
    ESCAPE, COMMA, LEFT_BRACKET, RIGHT_BRACKET, SEMI_COLON, COLON, DOT, ARROW, ASTERISK, INDEX,
    LPAREN, RPAREN,

    F_EOF
};

struct TOKEN_STRUCTURE {
    TOKEN_ENUMERATION type;
    char* value;
};
typedef struct TOKEN_STRUCTURE token_t;

class Tokenizer {
private:
    const char* buffer;
    std::vector<token_t*> tokens;
public:
    Tokenizer(const char* path);
    ~Tokenizer();

    token_t* new_token(TOKEN_ENUMERATION, char*, int);
    void list_tokens();

    bool is_digit(char);
    bool is_alpha(char);
    bool is_operator(char);
    bool is_ascii(char);
    bool is_hex(char);
    char* strstr(char*, char*);
    char* strchr(char, char*);
    bool strequals(char*,char*);
    void output_tok();
    void check_keyword();
    void src_tok();
};
#endif
