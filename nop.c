#include "monty.h"
#include <stddef.h>

/**
 * nop - Function that doesn't do anything
 * @stack: doubly linked list
 * @line_number: line number from file
 *
 * Return: void
 */ 

void nop(stack_t **stack, unsigned int line_number)
{
*stack = NULL;
(void)line_number;
return;
}
