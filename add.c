#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

void add(stack_t **stack, unsigned int line_number)
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
fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

tmp = *stack;
tmp2 = tmp->next;

result = tmp->n + tmp2->n;
tmp2->n = result;
tmp2->prev = NULL;
*stack = tmp2;
}
