#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../includes/lexer.hpp"

Tokenizer::Tokenizer(const char* path) {
    int fd;
    struct stat finfo;
    if (access(path, F_OK)) err_handle("Could not access file!");
    if ((fd = open(path, O_RDONLY)) < 0) err_handle("Could not open file!");
    stat(path, &finfo);
    this->buffer = (char*)malloc(finfo.st_size);
    memset((void*)this->buffer, 0, finfo.st_size);
    if (read(fd, (void*)buffer, finfo.st_size) < 0) {
        err_handle("Could not load source into memory!");
    }
    return;
}
// dealloc everything, after tokens have been parsed, we do not want it in memory anymore
Tokenizer::~Tokenizer() {
    free((void*)buffer);
    return;
}

token_t* Tokenizer::new_token(TOKEN_ENUMERATION type, char* start, int n) {
    token_t* tok = (token_t*)malloc(sizeof(token_t));
    tok->type = type;
    tok->value = (char*)malloc(n);
    memset(tok->value, 0, malloc_usable_size(tok->value));
    int i;
    for (i = 0; i < n; i++) {
        tok->value[i] = start[i];
    }
    return tok;
}

void Tokenizer::list_tokens() {
    for (auto& it: tokens) {
        switch (it->type) {
        case TOKEN_ENUMERATION::IF:printf("(IF)\n");break;
        case TOKEN_ENUMERATION::ELSE:printf("(ELSE)\n");break;
        case TOKEN_ENUMERATION::ELIF:printf("(ELIF)\n");break;
        case TOKEN_ENUMERATION::RETURN:printf("(RETURN)\n");break;
        case TOKEN_ENUMERATION::WHILE:printf("(WHILE)\n");break;
        case TOKEN_ENUMERATION::FOR:printf("(FOR)\n");break;
        case TOKEN_ENUMERATION::STRUCT:printf("(STRUCT)\n");break;
        case TOKEN_ENUMERATION::TYPEDEF:printf("(TYPEDEF)\n");break;
        case TOKEN_ENUMERATION::ENUM:printf("(ENUM)\n");break;
        case TOKEN_ENUMERATION::SWITCH:printf("(SWITCH)\n");break;
        case TOKEN_ENUMERATION::CASE:printf("(CASE)\n");break;
        case TOKEN_ENUMERATION::DEFAULT:printf("DEFAULT\n");break;
        case TOKEN_ENUMERATION::TRUE:printf("(TRUE)\n");break;
        case TOKEN_ENUMERATION::FALSE:printf("(FALSE)\n");break;
        case TOKEN_ENUMERATION::INTEGER:printf("(INTEGER)\n");break;
        case TOKEN_ENUMERATION::LONG:printf("(LONG)\n");break;
        case TOKEN_ENUMERATION::CHAR:printf("(CHAR)\n");break;
        case TOKEN_ENUMERATION::LITERAL:printf("(LITERAL, %s)\n", it->value);break;
        case TOKEN_ENUMERATION::IDENTIFIER:printf("(IDENTIFIER, %s)\n", it->value);break;
        case TOKEN_ENUMERATION::LFUNCTION:printf("(LFUNCTION)\n");break;
        case TOKEN_ENUMERATION::RFUNCTION:printf("(RFUNCTION)\n");break;
        case TOKEN_ENUMERATION::ADD:printf("(ADD)\n");break;
        case TOKEN_ENUMERATION::SUB:printf("(SUB)\n");break;
        case TOKEN_ENUMERATION::DIV:printf("(DIV)\n");break;
        case TOKEN_ENUMERATION::MUL:printf("(MUL)\n");break;
        case TOKEN_ENUMERATION::ASSIGN:printf("(ASSIGN)\n");break;
        case TOKEN_ENUMERATION::MOD:printf("(MOD)\n");break;
        case TOKEN_ENUMERATION::EQUALS:printf("(EQUALS)\n");break;
        case TOKEN_ENUMERATION::NOT_EQUALS:printf("(NOT EQUALS)\n");break;
        case TOKEN_ENUMERATION::INC:printf("(INC)\n");break;
        case TOKEN_ENUMERATION::DEC:printf("(DEC)\n");break;
        case TOKEN_ENUMERATION::APPEND_ADD:printf("(APPEND ADD)\n");break;
        case TOKEN_ENUMERATION::APPEND_SUB:printf("(APPEND_SUB)\n");break;
        case TOKEN_ENUMERATION::APPEND_DIV:printf("(APPEND_DIV)\n");break;
        case TOKEN_ENUMERATION::APPEND_MUL:printf("(APPEND_MUL)\n");break;
        case TOKEN_ENUMERATION::LESS:printf("(LESS THAN)\n");break;
        case TOKEN_ENUMERATION::GREATER:printf("(GREATER THAN)\n");break;
        case TOKEN_ENUMERATION::LESS_E:printf("(LESS THAN OR EQUALS TO)\n");break;
        case TOKEN_ENUMERATION::GREATER_E:printf("(GREATER THAN OR EQUALS TO)\n");break;
        case TOKEN_ENUMERATION::ESCAPE:printf("(ESCAPE)\n");break;
        case TOKEN_ENUMERATION::COMMA:printf("(COMMA)\n");break;
        case TOKEN_ENUMERATION::LEFT_BRACKET:printf("(LEFT BRACKET)\n");break;
        case TOKEN_ENUMERATION::RIGHT_BRACKET:printf("(RIGHT BRACKET)\n");break;
        case TOKEN_ENUMERATION::SEMI_COLON:printf("(SEMI COLON)\n");break;
        case TOKEN_ENUMERATION::COLON:printf("(COLON)\n");break;
        case TOKEN_ENUMERATION::DOT:printf("(DOT)\n");break;
        case TOKEN_ENUMERATION::ARROW:printf("(ARROW)\n");break;
        case TOKEN_ENUMERATION::ASTERISK:printf("(ASTERISK)\n");break;
        case TOKEN_ENUMERATION::INDEX:printf("(INDEX, %s)\n", it->value);
        }
    }
    return;
}

bool Tokenizer::is_digit(char in) {
    if (48 <= in && in <= 57) {
        return true;
    }
    return false;
}

bool Tokenizer::is_alpha(char in) {
    if ((65 <= in && in <= 90) || (97 <= in && in <= 122) ) {
        return true;
    }
    return false;
}

bool Tokenizer::is_operator(char in) {
    if ((33 <= in && in <= 47) || (58 <= in && in <= 63)) {
        return true;
    }
    return false;
}

bool Tokenizer::is_ascii(char in) {
    if (33 <= in && in <= 126) {
        return true;
    }
    return false;
}

char* Tokenizer::strstr(char* needle, char* haystack) {
    int n, c = 0, i;
    for (n = 0; needle[n]; n++);
    for (i = 0; haystack[i] != 0; i++) {
        (needle[c] == haystack[i]) ? c++ : c = 0;
        if (c == n) return haystack + (i-n+1);
    }
    return haystack;
}

char* Tokenizer::strchr(char needle, char* haystack) {
    int i;
    for (i = 0; haystack[i] != 0; i++) {
        if (needle == haystack[i]) return haystack+i;
    }
    return haystack;
}

bool Tokenizer::strequals(char* cursor, char* s) {
    return strncmp(cursor, s, strlen(s)) == 0;
}

void Tokenizer::err_handle(const char* err) {
    std::cout<<err<<std::endl;
    exit(-1);
    return;
}

void Tokenizer::check_keyword() {
    int n = sizeof(keywords)/sizeof(char*), i;
    for (auto& it: tokens) {
        if (it->type == TOKEN_ENUMERATION::IDENTIFIER) {
            for (i = 0; i < n; i++) {
                if (strequals(it->value, (char*)keywords[i])) {
                    it->type = keyword_tokens[i];
                }
            }
        }
    }
    return;
}

void Tokenizer::src_tok() {
    char* cursor = (char*)buffer, *temp = cursor;
    int n;
    while (*cursor) { // skip whitespace and \n
reset:
        n = 0;
        if (__glibc_unlikely(strequals(cursor, (char*)"//"))) {
            cursor = strchr('\n', cursor);
        }
        if (__glibc_unlikely(strequals(cursor, (char*)"/*"))) {
            cursor = strstr((char*)"*/", cursor)+2;
        }
        if (*cursor == '\n' || *cursor == ' ') {
            cursor++;
            goto reset;
        }
        if (*cursor == ';') {
            tokens.push_back(new_token(TOKEN_ENUMERATION::SEMI_COLON, cursor, 0));
            cursor++;
            goto reset;
        }
        if (*cursor == '*') {
            tokens.push_back(new_token(TOKEN_ENUMERATION::ASTERISK, cursor, 0));
            cursor++;
            goto reset;
        }
        if (*cursor == '\\') {
            tokens.push_back(new_token(TOKEN_ENUMERATION::ESCAPE, cursor, 0));
            cursor++;
            goto reset;
        }
        if (*cursor == ',') {
            tokens.push_back(new_token(TOKEN_ENUMERATION::COMMA, cursor, 0));
            cursor++;
            goto reset;
        }
        if (*cursor == '{') {
            tokens.push_back(new_token(TOKEN_ENUMERATION::LEFT_BRACKET, cursor, 0));
            cursor++;
            goto reset;
        }
        if (*cursor == '}') {
            tokens.push_back(new_token(TOKEN_ENUMERATION::RIGHT_BRACKET, cursor, 0));
            cursor++;
            goto reset;
        }
        if (*cursor == '.') {
            tokens.push_back(new_token(TOKEN_ENUMERATION::DOT, cursor, 0));
            cursor++;
            goto reset;
        }
        if (*cursor == ':') {
            tokens.push_back(new_token(TOKEN_ENUMERATION::COLON, cursor, 0));
            cursor++;
            goto reset;
        }
        if (*cursor == '+') {
            switch (*(cursor+1)) {
            case '=':
                tokens.push_back(new_token(TOKEN_ENUMERATION::APPEND_ADD, cursor, 0));
                cursor+=2;
                goto reset;
                break;
            case '+':
                tokens.push_back(new_token(TOKEN_ENUMERATION::INC, cursor, 0));
                cursor+=2;
                goto reset;
                break;
            default:
                tokens.push_back(new_token(TOKEN_ENUMERATION::ADD, cursor, 0));
                cursor++;
                goto reset;
                break;
            }
        }
        if (*cursor == '-') {
            switch (*(cursor+1)) {
            case '=':
                tokens.push_back(new_token(TOKEN_ENUMERATION::APPEND_SUB, cursor, 0));
                cursor+=2;
                goto reset;
                break;
            case '-':
                tokens.push_back(new_token(TOKEN_ENUMERATION::DEC, cursor, 0));
                cursor+=2;
                goto reset;
                break;
            case '>':
                tokens.push_back(new_token(TOKEN_ENUMERATION::ARROW, cursor, 0));
                cursor+=2;
                goto reset;
                break;
            default:
                tokens.push_back(new_token(TOKEN_ENUMERATION::ADD, cursor, 0));
                cursor++;
                goto reset;
                break;
            }
        }
        if (*cursor == '/') {
            switch (*(cursor+1)) {
            case '=':
                tokens.push_back(new_token(TOKEN_ENUMERATION::APPEND_DIV, cursor, 0));
                cursor+=2;
                goto reset;
                break;
            default:
                tokens.push_back(new_token(TOKEN_ENUMERATION::DIV, cursor, 0));
                cursor++;
                goto reset;
                break;
            }
        }
        if (*cursor == '*') {
            switch (*(cursor+1)) {
            case '=':
                tokens.push_back(new_token(TOKEN_ENUMERATION::APPEND_MUL, cursor, 0));
                cursor+=2;
                goto reset;
                break;
            default:
                tokens.push_back(new_token(TOKEN_ENUMERATION::ASTERISK, cursor, 0));
                cursor++;
                goto reset;
                break;
            }
        }
        if (*cursor == '=') {
            switch (*(cursor+1)) {
            case '=':
                tokens.push_back(new_token(TOKEN_ENUMERATION::EQUALS, cursor, 0));
                cursor+=2;
                goto reset;
                break;
            default:
                tokens.push_back(new_token(TOKEN_ENUMERATION::ASSIGN, cursor, 0));
                cursor++;
                goto reset;
                break;
            }
        }
        if (*cursor == '(') {
            tokens.push_back(new_token(TOKEN_ENUMERATION::LFUNCTION, cursor, 0));
            cursor++;
            goto reset;
        }
        if (*cursor == ')') {
            tokens.push_back(new_token(TOKEN_ENUMERATION::RFUNCTION, cursor, 0));
            cursor++;
            goto reset;
        }
        if (is_digit(*cursor)) {
            temp = cursor; // now integer literal is between cursor and temp
            while(is_digit(*temp)) {
                temp++;
            };
            // add literal integer value to token vector
            n = (int)(temp-cursor);
            tokens.push_back(new_token(TOKEN_ENUMERATION::LITERAL, cursor, n));
            cursor+=n;
            n=0;
            goto reset;
        }

        if (*cursor == '\"') {
            for (temp = cursor+1; *temp != '\"'; temp++) {
                if (!*temp) {
                    err_handle("Incorrect string literal!");
                }
            }
            n = (int)(temp-cursor)+1;
            tokens.push_back(new_token(TOKEN_ENUMERATION::LITERAL, cursor, n));
            cursor+=n;
            n=0;
            goto reset;
        }

        if (*cursor == '[') {
            temp = strchr(']', cursor);
            n = (int)(temp-cursor);
            tokens.push_back(new_token(TOKEN_ENUMERATION::INDEX, cursor+1, n-1));
            cursor+=n;
            n=0;
            goto reset;
        }

        if (is_alpha(*cursor)) {
            temp = cursor;
            while(is_alpha(*temp)) {
                temp++;
                if (!*temp) {
                    err_handle("Invalid Identifier Token");
                }
            }
            n = (int)(temp-cursor);
            tokens.push_back(new_token(TOKEN_ENUMERATION::IDENTIFIER, cursor, n));
            cursor+=n;
            n=0;
            goto reset;
        }
        cursor++;
    }
    check_keyword();
}

int main(int argc, char**argv) {
    Tokenizer t(argv[1]);
    t.src_tok();
    t.list_tokens();
}
