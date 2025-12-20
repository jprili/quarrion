#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define READ_MODE "r"
#define NEXT_CHAR_OFFSET 1
#define INITIAL_ARRAY_SIZE 128
#define TOKEN_BUFFER_SIZE 512

typedef enum {
    NO_ARGUMENTS = 1,
    FILE_NOT_FOUND,
    UNEXPECTED_TOKEN
} exit_code;

typedef struct node node;
struct node {
    char* token;
    node* next;
};

const int   reserved_tokens_size = 10;
const char* reserved_tokens[] = {
    "DEF",
    "INT",
    "ARG",
    "STR",
    "DCR",
    "RET",
    ":",
    "[",
    "]",
    ","
};

unsigned char is_token_reserved(const char* token,
        const char* reserved_tokens[],
        const unsigned int reserved_tokens_size) {
    for (unsigned int i = 0; i < reserved_tokens_size; ++i) {
        if (!strcmp(reserved_tokens[i], token)) {
            return 1;
        }
    }
    return 0;
};

/**
 * Obtains all the tokens in the file input.
 *
 * @param file_name the name of the file to compile.
 * @param target    the target array.
 */
void lex(char* file_name, node* target) {
    FILE* file = fopen(file_name, READ_MODE);
    if (file == NULL) {
        printf("Cannot find file ");
        printf("%s\n", file_name);
        exit(FILE_NOT_FOUND);
    }

    char current = fgetc(file);
    char* buffer = malloc(TOKEN_BUFFER_SIZE);
    unsigned int buffer_index = 0;
    while (current != EOF) {
        unsigned char reserved = is_token_reserved(
                buffer,
                reserved_tokens,
                reserved_tokens_size
            );

        if (reserved || isspace(current)) {
            current       = fgetc(file); // go to next character
            target->token = buffer;
            target->next  = malloc(sizeof(node));
            target        = target->next;
            buffer        = malloc(TOKEN_BUFFER_SIZE);
            buffer_index  = 0;
        } 
        buffer[buffer_index++] = current;
        current = fgetc(file);
    } 
    target->next = NULL;
    fclose(file);
}

void _print_target(node* target) {
    if (!target) {
        printf("\n");
        return;
    } else {
        printf("%s, ", target->token);
    }
    _print_target(target->next);
};

