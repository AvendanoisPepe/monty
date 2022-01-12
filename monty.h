#ifndef MONTY_H
#define MONTY_H
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

stack_t *add_dnodeint(stack_t **head, const int n);
void tok(char *buffer);
size_t print_dlistint(const stack_t *h);
void free_dlistint(stack_t *head);
void check_push(char *op, unsigned int line);
void is_opt(char *buffer, stack_t **head, unsigned int line);
/**
 *push:-function add new nod doublylinked list
 *@head:-Dlink
 *@line:-int
 * Return: long linked list
 */
void push(__attribute__((unused)) stack_t **head,
		  __attribute__((unused)) unsigned int line);
/**
 *pall:-function print doublylinked list
 *@head:-Dlink
 *@line:-int
 * Return: long linked list
 */
void pall(__attribute__((unused)) stack_t **head,
		  __attribute__((unused)) unsigned int line);
stack_t *head;
#endif
