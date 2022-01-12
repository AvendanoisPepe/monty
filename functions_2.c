#include "monty.h"
/**
 *check_push:-function check push valido
 *@line:-n line
 *@op:-argument
 */
void check_push(char *op, __attribute__((unused))unsigned int line)
{
	int i = 0;

	while (op[i])
	{
		if (!(isdigit(op[i])))
		{
			fprintf(stderr, "L<%d>: usage: push integer\n", ++line);
			exit(EXIT_FAILURE);
		}
		i++;
	}

}
