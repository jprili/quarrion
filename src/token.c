#include "token_type.c"
#include "literal_type.c"

struct token {
    token_type type;
    char**     lexeme;
    int value;
};
