#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"

/**
 * process - Function that process instructions and calls matching functn
 * @instr: string of extracted line of instruction
 * @stack: the stack to perfom operations on
 * @num_line: Line number to perform operations on if necessary
 * @validInstruct: A struct array of valid Instructions
 * @global: Global variable, used as operation arg
 *
 * Return: void
 */

char *global;

void process(char *instr, stack_t **stack, unsigned int num_line, instruction_t *validInstruct)
{
char *operation;
int i, match;

operation = strtok(instr, " ");
global = strtok(NULL, " ");

if (operation == NULL)
{
return;
}

for (i = 0; validInstruct[i].opcode != NULL; i++)
{
match = _strcmp(operation, validInstruct[i].opcode);
if (match == 0)
{
validInstruct[i].f(stack, num_line);
return;
}
}

fprintf(stderr, "L%u: unknown instruction %s\n", num_line, operation);
exit(EXIT_FAILURE);
}
