#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define READ_MODE "r"
#define INITIAL_ARRAY_SIZE 128

typedef enum {
    NO_ARGUMENTS = 1,
    FILE_NOT_FOUND
} exit_codes;

/**
 * Obtains all the tokens in the file input.
 *
 * @param file_name the name of the file to compile.
 * @param target    the target array.
 */
void lex(char* file_name, char** target) {
    FILE* file = fopen(file_name, READ_MODE);
    if (file == NULL) {
        printf("Cannot find file ");
        printf("%s\n", file_name);
        exit(FILE_NOT_FOUND);
    }

    // iterate through the entire file
    char previous;
    for (char current = fgetc(file); current != EOF;
            current = fgetc(file)) {
        if (isspace(current) && current == previous) {
            continue;
        }
        else if (isspace(current)) {
            printf("");
        }
        previous = current;
        printf("%c", current);
    };
    printf("\n");

    fclose(file);
}

/**
 * Drives the compilation.
 */
int main(int argc, char* argv[]) {
    if (argc <= 1) {
        printf("Please provide a file name.");
        return NO_ARGUMENTS;
    }
    char* file_name = argv[1];
    char** tokens   = (char**) malloc(INITIAL_ARRAY_SIZE * sizeof(void*));
    lex(file_name, tokens);
    return EXIT_SUCCESS;
}
