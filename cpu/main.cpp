#include "cpu.h"

int main(int argc, char *argv[])
{
    size_t error = NO_ERRORS;
    const char *input_filename = "data.code";

    if (argc == 2)
    {
        input_filename = argv[1];
    }
    if (argc > 2)
    {
        return -1;
    }
    setbuf(stdout, NULL);
    FILE *fp = fopen(input_filename, "rb");

    Stack stack = {};
    stackCtor(&stack, 1, &error)

    Code code = {};
    CPU cpu = {&code, &stack};

    error = readCode(fp, &code);
    if (error)
    {
        printf("ERROR read: %zu\n", error);
    }

    error = run(&cpu);
    if (error)
    {
        printf("ERROR run: %zu\n", error);
        printf("Stack size: %zu\n", stack.size);
    }
    fclose(fp);
    return 0;
}