#include "monty.h"
/**
 * pstr - prints the string starting at the top of the stack
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
 * rotl - rotates the stack to the top
 * @stack: stack_t variable
 * @line_number: unsigned int variable
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL, *tmp2 = NULL;

	(void)line_number;
	if (*stack && (*stack)->next && stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		if ((*stack)->next)
		{
			tmp2 = (*stack)->next;
			while (tmp2->next)
			{
				tmp2 = tmp2->next;
			}
			tmp2->next = tmp;
			tmp->next = NULL;
			tmp->prev = tmp2;
		}
		else
		{
			(*stack)->next = tmp;
			tmp->next = NULL;
			tmp->prev = *stack;
		}
	}

}
/**
 * rotr - rotates the stack to the bottom.
 * @stack: stack_t variable
 * @line_number: unsigned int variable
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL, *tmp2 = NULL;

	(void)line_number;
	if (*stack && (*stack)->next && stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		if ((*stack)->next)
		{
			tmp2 = (*stack)->next;
			while (tmp2->next)
			{
				tmp2 = tmp2->next;
			}
			tmp2->next = tmp;
			tmp->prev = tmp2;
			tmp->next = NULL;
		}
		else
		{
			(*stack)->next = tmp;
			tmp->next = NULL;
			tmp->prev = *stack;
		}
	}
}
