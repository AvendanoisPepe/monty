#include "monty.h"
/**
 *check_push:-check push valido
 *@line:-n line
 *@op:-argument
 *Return: err or not err
 */
int check_push(char *op, __attribute__((unused))unsigned int line)
{
	int i = 0;

	while (op[i])
	{
		if (!(isdigit(op[i])) && (op[0] != '-' && op[0] != '+'))
		{
			return (-1);
		}
		i++;
	}
	return (0);
}
/**
 * pint - entry point
 * @stack: stack_t variable
 * @line_number: unsigned int variable
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(red);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * empty_str - verify is a string is spaces or
 * @str: string.
 * Return: 0 on succesful, 1 if failed.
 */
int empty_str(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		if (str[i] != '\n' && str[i] != ' ')
			return (1);
	return (0);
}
/**
 * err_push - exit error
 * @line: string.
 */
void err_push(unsigned int line)
{
	fprintf(stderr, "L%d: usage: push integer\n", line);
	fclose(red);
	free_dlistint(head);
	exit(EXIT_FAILURE);
}
