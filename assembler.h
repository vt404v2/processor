#ifndef STACK__ASSEMBLER_H
#define STACK__ASSEMBLER_H

#include "utils.h"

enum ASSEMBLER_ERRORS
{
    ASSEMBLER_CANT_ALLOCATE_MEMORY_FOR_PROGRAM = 1 << 4,
    ASSEMBLER_CANT_ALLOCATE_MEMORY_FOR_STRINGS = 1 << 5,
    ASSEMBLER_COMPILATION_FAILED               = 1 << 6,
    ASSEMBLER_CANT_SHRINK_TO_FIT               = 1 << 7,
};

const size_t COMPILATION_CONST = 0xDEADF00D;
const size_t VERSION           = 0;

/**
 * @brief Struct for storing array of strings, its' length and pointer
 * to memory block with not sorted text(array of string)
 */
struct Program
{
    char **lines  = nullptr;
    size_t length = 0;
};

/**
 * @brief reads file to struct Program
 *
 * @param fp - opened file
 * @param program - struct Program with file
 * @return error code
 */
size_t readFile(FILE *fp, Program *program);

/**
 * @brief Adds info about code: the compilation const, version, and code length
 *
 * @param code array with code
 */
void addInfo(int **code);

/**
 * @brief Compiles code
 *
 * @param program array with program to compile
 * @param error error code
 * @return compiled code
 */
int *compile(Program *program, size_t *error);

/**
 * @brief Saves array with compiled code to file
 *
 * @param code code to write to file
 * @param filename name of file to write
 * @return error code
 */
size_t saveFile(int *code, const char *filename);

#endif //STACK__ASSEMBLER_H
