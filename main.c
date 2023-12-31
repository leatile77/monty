#include <stdlib.h>
#include <stdio.h>
#include "monty.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/**
 * main - monty compiler
 * @argc: number of arguments
 * @argv: strings of arguments
 *
 * Return : 0 on success, else EXIT_FAILURE
 */


int main(int argc, char *argv[])
{
char *lines[BUFF];
char line[BUFF];
char *token;
int fd;
stack_t *stack;
instruction_t validInstruct[12];
size_t i, j, len, num_lines;

len = 0;
num_lines = 0;

validInstruct[0].opcode = "push";
validInstruct[0].f = push;
validInstruct[1].opcode = "pall";
validInstruct[1].f = pall;
validInstruct[2].opcode = "pint";
validInstruct[2].f = pint;
validInstruct[3].opcode = "pop";
validInstruct[3].f = pop;
validInstruct[4].opcode = "swap";
validInstruct[4].f = swap;
validInstruct[5].opcode = "add";
validInstruct[5].f = add;
validInstruct[6].opcode = "nop";
validInstruct[6].f = nop;
validInstruct[7].opcode = "sub";
validInstruct[7].f = sub;
validInstruct[8].opcode = "div";
validInstruct[8].f = _div;
validInstruct[9].opcode = "mul";
validInstruct[9].f = mul;
validInstruct[10].opcode = "mod";
validInstruct[10].f = mod;
validInstruct[11].opcode = NULL;
validInstruct[11].f = NULL;

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}

while (read(fd, line, BUFF) > 0)
{
len = strlen(line);
if (len > 0 && line[len - 1] == '\n')
{
line[len - 1] = '\0';
}

token = strtok(line, "'\n'$");
if (token == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
close(fd);
exit(EXIT_FAILURE);
}

while (token != NULL)
{
lines[num_lines] = _strdup(token);
token = "";
 
/**
*if (lines[num_lines] == NULL)
*{
*fprintf(stderr, "Error: malloc failed\n");
*close(fd);
*free(lines[num_lines]);
*exit(EXIT_FAILURE);
*}
*/

num_lines++;
token = strtok(NULL, "'\n'$");
}
}
close(fd);

stack = NULL;

for (j = 0; j < num_lines; j++)
{
process(lines[j], &stack, j + 1, validInstruct);
}

for (i = 0; i < num_lines; i++)
{
free(lines[i]);
}

return (0);
}
