#include "monty.h"
/**
 * main - check the code
 *@argc:-n arguments
 *@argv:-argunets
 * Return: Always EXIT_SUCCESS.
 */
int main(int argc, char *argv[])
{

	stack_t *head = NULL;
	unsigned int line = 1;
	char buffer[1024];

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	red = fopen(argv[1], "r");
	if (!red)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, 1024, red) != NULL)
	{
		if (empty_str(buffer))
			is_opt(buffer, &head, line);
		line++;
	}
	fclose(red);
	free_dlistint(head);
	return (0);
}
/**
 * is_opt - check the options
 *@buffer:-n arguments
 *@head:-dublelinkt
 *@line:-int argument
 * Return: Always EXIT_SUCCESS.
 */
void is_opt(char *buffer, __attribute__((unused))stack_t **head,
			__attribute__((unused))unsigned int line)
{
	int idx = 0;
	char *op = NULL;

	instruction_t opts[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {NULL, NULL}};
	op = strtok(buffer, " \t \n");
	while (opts[idx].opcode)
	{
		if (strcmp(opts[idx].opcode, op) == 0)
		{
			op = strtok(NULL, " \t \n");
			if (op)
			{
				if (check_push(op, line) != -1)
				{
					line = atoi(op);
					opts[idx].f(head, line);
					break;
				}
				else
				{
					fprintf(stderr, "L%d: usage: push integer\n", line);
					fclose(red);
					free_dlistint(*head);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				opts[idx].f(head, line);
				break;
			}
		}
		idx++;
	}
	if (!(opts[idx].opcode))
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, op);
		free_dlistint(*head);
		fclose(red);
		exit(EXIT_FAILURE);
	}
}
