#include "monty.h"

/**
 * _strlen - checks the length of a string
 * @s: char variable used to count chars in string
 *
 * Return: length of string
 */

int _strlen(char *s)
{
int length;
length = 0;

while (*s++)
{
length++;
}
return (length);
}
