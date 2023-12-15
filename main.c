#include <stdlib.h>
#include <stdio.h>
#include "func.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char *lines[BUFF];
  char line[BUFF];
  char *token;
  int fd;
  stack_t *stack;
  instruction_t validInstruct[3];
  size_t i, j, len, num_lines;

  len = 0;
  num_lines = 0;

  validInstruct[0].opcode = "push";
  validInstruct[0].f = push;
  validInstruct[1].opcode = "pall";
  validInstruct[1].f = pall;
  /*validInstruct[2].opcode = "pall";
  validInstruct[2].f = pall;*/
  validInstruct[2].opcode = NULL;
  validInstruct[2].f = NULL;
  
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
      while (token)
	{
	  lines[num_lines] = _strdup(token);
	  token = "";
	  if (lines[num_lines] == NULL)
	    {
	      fprintf(stderr, "Error: malloc failed\n");
	      close(fd);
	      exit(EXIT_FAILURE);
	    }
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
