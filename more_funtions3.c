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
/**
 * rotl - entry point
 * @stack: stack_t variable
 * @line_number: unsigned int variable
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL, *tmp2 = NULL;

	(void)line_number;
	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		tmp2 = (*stack)->next;
		while (tmp2->next)
		{
			tmp2 = tmp2->next;
		}
		tmp2->next = tmp;
		tmp->next = NULL;
		tmp->prev = tmp2;
	}

}
