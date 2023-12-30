#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/**
 * mod - Function that gets 2nd top modulas top element
 * @stack: Stack to compute modulas on
 * @line_number: Line number in the file
 *
 * Return: void
 */

void mod(stack_t **stack, unsigned int line_number)
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
fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

tmp = *stack;
tmp2 = tmp->next;

if (tmp->n == 0)
{
fprintf(stderr, "L%u: division by zero\n", line_number);
exit(EXIT_FAILURE);
}

result = tmp2->n % tmp->n;
tmp2->n = result;
tmp2->prev = NULL;
*stack = tmp2;
free(tmp);
}
