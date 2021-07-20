#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <vector>
#include <map>
#include <malloc.h>

// gives us a good idea of what initial state to jump to

enum class TOKEN_ENUMERATION {
    /* statements */
    IF, ELSE, ELIF, RETURN, WHILE, FOR, STRUCT, TYPEDEF, ENUM, SWITCH, CASE, DEFAULT, GOTO,

    /* bool */
    TRUE, FALSE,

    /* literals */
    INTEGER, LONG, CHAR, LITERAL, HEX,

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

const char* keywords[] = {"if","else","elif","return","while","for", "struct", "typedef", "enum", 
    "switch", "case", "default", "goto", "true", "false", "int", "long", "char"};

TOKEN_ENUMERATION keyword_tokens[] = {
    TOKEN_ENUMERATION::IF,
    TOKEN_ENUMERATION::ELSE,
    TOKEN_ENUMERATION::ELIF,
    TOKEN_ENUMERATION::RETURN,
    TOKEN_ENUMERATION::WHILE,
    TOKEN_ENUMERATION::FOR,
    TOKEN_ENUMERATION::STRUCT,
    TOKEN_ENUMERATION::TYPEDEF,
    TOKEN_ENUMERATION::ENUM,
    TOKEN_ENUMERATION::SWITCH,
    TOKEN_ENUMERATION::CASE,
    TOKEN_ENUMERATION::DEFAULT,
    TOKEN_ENUMERATION::GOTO,
    TOKEN_ENUMERATION::TRUE,
    TOKEN_ENUMERATION::FALSE,
    TOKEN_ENUMERATION::INTEGER,
    TOKEN_ENUMERATION::LONG,
    TOKEN_ENUMERATION::CHAR
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
    void err_handle(const char*);
    void output_tok();
    void check_keyword();
    void src_tok();
};
#endif
