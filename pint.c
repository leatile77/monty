#include <stdlib.h>
#include <stdio.h>
#include "monty.h"

/**
 * pint - Function that prints the value at top of stack
 * @stack: stack with top value to print
 * @line_number: line number in the file
 *
 * Return: void
 */

void pint(stack_t **stack, unsigned int line_number)
{
stack_t *tmp;
tmp = *stack;

if (tmp == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}

printf("%d\n", tmp->n);
}
