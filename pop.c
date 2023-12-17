#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * pop - Function that removes top element from stack
 * @stack: stack to remove top element from
 * @line_number: line number from file
 *
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
stack_t *tmp, *tmp2;

if (*stack == NULL)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}

tmp = *stack;
tmp2 = *stack;

if (tmp->next != NULL)
{
tmp = tmp->next;
tmp->prev = NULL;
*stack = tmp;
}
else
{
*stack = NULL;
}
free(tmp2);
}
