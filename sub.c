#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * sub - Function that subtracts top and 2nd top elements
 * @stack: Stack to subtract from
 * @line_number: Line number in the file
 *
 * Return: void
 */

void sub(stack_t **stack, unsigned int line_number)
{
int size, result;
stack_t *tmp, *tmp2;

size = 0;
tmp = *stack;

while (tmp)
{
size++;
tmp = tmp->next;
}

if (size <= 2)
{
fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

tmp = *stack;
tmp2 = tmp->next;

result = tmp2->n - tmp->n;
tmp2->n = result;
tmp2->prev = NULL;
*stack = tmp2;
}
