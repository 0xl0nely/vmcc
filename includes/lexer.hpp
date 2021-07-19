#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <vector>
#include <malloc.h>

// gives us a good idea of what initial state to jump to

const char* keywords[] = {"if","else","elif","return","while","for","true","false",
    "int","long","char"};

enum class TOKEN_ENUMERATION {
	/* statements */
	IF, ELSE, ELIF, RETURN, WHILE, FOR, STRUCT, TYPEDEF, ENUM,

	/* bool */
	TRUE, FALSE,

    /* literals */
    INTEGER, LONG, CHAR, LITERAL,

    /* identifier */
    IDENTIFIER,

    /* function */
    LFUNCTION, RFUNCTION,

	/* operators */
	ADD, SUB, DIV, MUL, ASSIGN, MOD, EQUALS, NOT_EQUALS, INC, DEC, APPEND_ADD, APPEND_SUB, APPEND_DIV,
	APPEND_MUL, LESS, GREATER, LESS_E, GREATER_E,

	/* expressions */
	ESCAPE, COMMA, LEFT_BRACKET, RIGHT_BRACKET, SEMI_COLON, DOT, ARROW, ASTERISK, INDEX
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
	char* strstr(char*, char*);
	char* strchr(char, char*);
	bool strequals(char*,char*);
	void err_handle(const char*);
	void output_tok();
    int check_keyword(char*);
	void src_tok();
};
#endif
