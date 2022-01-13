#include "monty.h"
/**
 * main - check the code
 *@argc:-n arguments
 *@argv:-argunets
 * Return: Always EXIT_SUCCESS.
 */
int main(int argc, char *argv[])
{
	FILE *red = NULL;
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
	while (fscanf(red, "%[^\n] ", buffer) != EOF)
	{
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
		{"push", push}, {"pall", pall}, {NULL, NULL}};
	op = strtok(buffer, " \t");
	while (opts[idx].opcode)
	{
		if (strcmp(opts[idx].opcode, op) == 0)
		{
			op = strtok(NULL, " \t \n");
			if (op)
			{
				check_push(op, line);
				line = atoi(op);
				opts[idx].f(head, line);
				break;
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
		fprintf(stderr, "L<%d>: unknown instruction <%s>\n", ++line, op);
		free_dlistint(*head);
		exit(EXIT_FAILURE);
	}
}
