#include "func.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pall - Function that prints all n members in a stack
 * @stack: stack / doubly linked list to print n from
 * @line_number: Line number to print (not used)
 *
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
stack_t *current;

(void)line_number;

if (*stack == NULL)
{
return;
}

current = *stack;

while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
}
