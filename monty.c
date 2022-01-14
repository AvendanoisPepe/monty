#include "monty.h"
/**
 * main - Monty file interpreter.
 *@argc:-n arguments
 *@argv:-argunets
 * Return: Always EXIT_SUCCESS.
 */
int main(int argc, char *argv[])
{

	stack_t *head = NULL;
	unsigned int line = 1;


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
 * is_opt - Validates the options found in the lines of the  file .m
 *@buffer:-n arguments
 *@head:-dublelinkt
 *@line:-int argument
 * Return: Always EXIT_SUCCESS.
 */
void is_opt(char *buffer, stack_t **head, unsigned int line)
{
	int index = 0;
	char *op = NULL;

	instruction_t opts[] = {{"push", push}, {"pall", pall}, {"pint", pint},
	{"pop", pop}, {"swap", swap}, {"add", add}, {"nop", nop}, {"rotr", rotr},
	{"sub", sub}, {"div", divi}, {"mul", mul}, {"mod", mod},
	{"pchar", pchar}, {"pstr", pstr}, {"rotl", rotl}, {NULL, NULL}};
	op = strtok(buffer, " \t \n");
	while (opts[index].opcode)
	{
		if (strcmp(opts[index].opcode, op) == 0)
		{
			opts[index].f(head, line);
			break;
		}
		index++;
	}
	if (op[0] == '#')
	{
		nop(head, line);
	}
	else if (!(opts[index].opcode))
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, op);
		free_dlistint(*head);
		fclose(red);
		exit(EXIT_FAILURE);
	}
}
