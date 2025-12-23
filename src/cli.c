/**
 * Command Line Interface for Quarrion (CLIQ)
 *
 * This is where all the CLI logic is contained.
 * Written using the REPL architecture.
 *
 */

#include "stdio.h"

#define BUFFER_SIZE 256

int    cli_read_into(char[]);
void   cli_execute(char[], char*);
void   cli_print(char*);

int cli_read_into(char* target_buffer) 
{
    printf(">>> ");
    return fgets(target_buffer, BUFFER_SIZE - 1, stdin) != NULL;
};

void cli_execute(char buffer_in[], char* buffer_out)
{};

void cli_print(char* buffer)
{
    printf("%s\n", buffer);
};

void cli_loop() 
{
    char buffer[BUFFER_SIZE] = {0};
    while (buffer[0] != '') 
    {
        int read_status = cli_read_into(buffer);
        if (!read_status) {
            printf("[ERROR] Read unsuccessful.");
            printf("        buffer: %s", buffer);
            break;
        }
        // read buffer contents, 
        // then overwrite with output
        cli_execute(buffer, buffer);
        cli_print(buffer);
    }
    printf("[INFO] Exiting...");
};
