#include "monty.h"

/**
 * _strcmp - Compares string s1 and s2
 * @s1: first string to compare
 * @s2: second string to compare
 *
 * Return: -1 or 0 or 1
 */

int _strcmp(char *s1, char *s2)
{
int i;
for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
{
if (s1[i] != s2[i])
{
if (s2[i] < s1[i])
{
return (s1[i] - s2[i]);
}

else if (s1[i] < s2[i])
{
return (s1[i] - s2[i]);
}
}

}
return (0);

}
