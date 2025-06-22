
@ equivalent to
@ int main(int argc, char*[] argv) {
@   return 2;
@ }
@ in C.
DEF main, INT:
    ARG argc, INT
    ARG argv, STR[]

    DCR exit_code, INT, 2 @ int exit_code = 2;
    RET exit_code

