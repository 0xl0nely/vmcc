#include <bits/stdc++.h>
#include "lexer.h"
#include "AST.h"
int main(int argc, char**argv) {
    Tokenizer t(argv[1]);
    t.src_tok();
    t.list_tokens();



}
