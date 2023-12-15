#include "monty.h"
#include <stdlib.h>

/**
 * _strdup - Function copies str into newly allocated memory
 * @str: string to copy/duplicate
 *
 *Return: p or NULL
 */

char *_strdup(char *str)
{
char *p;
int i, n;
i = 1;

if (str == NULL)
{
return (NULL);
}

while (str[i])
{
i++;
}

p = malloc((sizeof(char) * i) +1);

if (p == NULL)
{
return (NULL);
}

for (n = 0; n < i; n++)
{
p[n] = str[n];
}

return (p);
}
