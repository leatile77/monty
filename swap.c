#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

void swap(stack_t **stack, unsigned int line_number)
{
int size;
stack_t *tmp, *tmp2, *tmp3;

size = 0;
tmp = *stack;

while (tmp)
{
size++;
tmp = tmp->next;
}

if (size <= 2)
{
fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

tmp = *stack;
tmp2 = *stack;
tmp3 = *stack;

tmp2 = tmp2->next;
tmp3 = tmp2->next;

tmp2->prev = NULL;
tmp2->next = tmp;

tmp->prev = tmp2;
tmp->next = tmp3;

tmp3->prev = tmp;

*stack = tmp2;
 
}
