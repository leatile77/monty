#include <stdlib.h>
#include <stdio.h>
#include "monty.h"

/**
 * push - Function that adds a new element at the top of stack
 * @stack: list to add element in
 * @line_number: Line number(position) to add element in (unused)
 *
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
stack_t *tmp, *new;
char *arg;

tmp = *stack;
(void)line_number;

new = malloc(sizeof(stack_t));
if (new == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

if (global == NULL || *global == '\0')
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
free(new);
exit(EXIT_FAILURE);
}

for (arg = global; *arg != '\0'; arg++)
{
if (*arg < '0' || *arg > '9')
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
}

new->n = atoi(global);
new->next = tmp;
new->prev = NULL;

if (tmp != NULL)
{
tmp->prev = new;
}

*stack = new;
}
