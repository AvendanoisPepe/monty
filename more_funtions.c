#include "monty.h"
/**
 *delete_dnodeint_at_index:-funt shearch n nodo
 *@head: linked list
 *@index: index nodo
 * Return: long linked list
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *tmp = *head;

	if (*head == NULL)
		return (-1);

	for (; index != 0; index--)
	{
		if (tmp == NULL)
			return (-1);
		tmp = tmp->next;
	}

	if (tmp == *head)
	{
		*head = tmp->next;
		if (*head != NULL)
			(*head)->prev = NULL;
	}

	else
	{
		tmp->prev->next = tmp->next;
		if (tmp->next != NULL)
			tmp->next->prev = tmp->prev;
	}

	free(tmp);
	return (1);
}
/**
 *pop:-funt shearch n nodo
 *@head: linked list
 *@line: index nodo
 * Return: long linked list
 */
void pop(stack_t **head, unsigned int line)
{
	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		fclose(red);
		exit(EXIT_FAILURE);
	}
	line = 0;
	delete_dnodeint_at_index(head, line);
}
