#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/**
 * mul - Function that multiplies 2nd top with top element
 * @stack: Stack to multiply from
 * @line_number: Line number in the file
 *
 * Return: void
 */

void mul(stack_t **stack, unsigned int line_number)
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
fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

tmp = *stack;
tmp2 = tmp->next;

result = tmp2->n * tmp->n;
tmp2->n = result;
tmp2->prev = NULL;
*stack = tmp2;
free(tmp);
}
