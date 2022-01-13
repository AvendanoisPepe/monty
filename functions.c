#include "monty.h"
/**
 *push:-function add new nod doublylinked list
 *@head:-Dlink
 *@line:-int
 * Return: long linked list
 */
void push(__attribute__((unused))stack_t **head,
			__attribute__((unused))unsigned int line)
{
	char *op = NULL;

	op = strtok(NULL, " \t \n");
	if (check_push(op, line) != -1)
	{
		line = atoi(op);
		add_dnodeint(head, line);
	}
	else
	{
		err_push(line);
	}
}
/**
 *pall:-function print doublylinked list
 *@head:-Dlink
 *@line:-int
 * Return: long linked list
 */
void pall(__attribute__((unused))stack_t **head,
			__attribute__((unused))unsigned int line)
{
	/*stack_t *head2 = *head; */
	print_dlistint(*head);

}

/**
 *add_dnodeint:-function add new nod doublylinked list
 *@head:-Dlink
 *@n:-int
 * Return: long linked list
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_nodo;

	new_nodo = malloc(sizeof(stack_t));
	if (!new_nodo)
		return (NULL);
	new_nodo->n = n;
	new_nodo->next = NULL;
	new_nodo->prev = NULL;
	if (!*head)
	{
		*head = new_nodo;
	}
	else
	{
		new_nodo->next = *head;
		(*head)->prev = new_nodo;
		*head = new_nodo;
	}
	return (new_nodo);
}

/**
 *print_dlistint:-function print doublylinked list
 *@h: linked list
 * Return: long linked list
 */
size_t print_dlistint(const stack_t *h)
{
	if (h)
	{
		int elmets = 0;

		while (h)
		{
			printf("%d\n", h->n);
			elmets++;
			h = h->next;
		}
		return (elmets);
	}
	return (0);
}

/**
 * free_dlistint - free doublylinklist.
 * @head: doubly linkt list
 *
 */
void free_dlistint(stack_t *head)
{
	if (head)
	{
		stack_t *tmp;

		while (head)
		{
			tmp = head->next;
			free(head);
			head = tmp;
		}
	}
}
