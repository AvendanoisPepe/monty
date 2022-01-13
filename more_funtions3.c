#include "monty.h"
/**
 * pstr - entry point
 * @stack: stack_t variable
 * @line_number: unsigned int variable
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	int string;
	stack_t *tmp;
	(void)line_number;

	if (stack != NULL)
	{
		tmp = *stack;
		while (tmp)
		{
			string = tmp->n;
			if (string > 0 && string <= 127)
				putchar(string);
			else
				break;
			tmp = tmp->next;
		}
	}
	putchar('\n');
}
