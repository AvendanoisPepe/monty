#include "monty.h"
/**
 * sub - subs the top two elements of the stack..
 * @stack: double linked list
 * @line_number: number of evaluated line
 */
void sub(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack && (*stack)->next)
    {
        temp = (*stack)->next;
        (*stack)->next->n = (*stack)->next->n - (*stack)->n;
        pop(stack, line_number);
        *stack = temp;
    }
    else
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        fclose(red);
        exit(EXIT_FAILURE);
    }
}

/**
 * div - divs the top two elements of the stack..
 * @stack: double linked list
 * @line_number: number of evaluated line
 */
void divi(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack && (*stack)->next)
    {
        temp = (*stack)->next;
        if ((*stack)->n == 0)
        {
            fprintf(stderr, "L%d: division by zero\n", line_number);
            fclose(red);
            exit(EXIT_FAILURE);
        }
        (*stack)->next->n = (*stack)->next->n / (*stack)->n;
        pop(stack, line_number);
        *stack = temp;
    }
    else
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
        fclose(red);
        exit(EXIT_FAILURE);
    }
}

/**
 * mul - muls the top two elements of the stack..
 * @stack: double linked list
 * @line_number: number of evaluated line
 */
void mul(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack && (*stack)->next)
    {
        temp = (*stack)->next;
        (*stack)->next->n = (*stack)->next->n * (*stack)->n;
        pop(stack, line_number);
        *stack = temp;
    }
    else
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
        fclose(red);
        exit(EXIT_FAILURE);
    }
}

/**
 * mod - mods the top two elements of the stack..
 * @stack: double linked list
 * @line_number: number of evaluated line
 */
void mod(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack && (*stack)->next)
    {
        temp = (*stack)->next;
        if ((*stack)->n == 0)
        {
            fprintf(stderr, "L%d: division by zero\n", line_number);
            fclose(red);
            exit(EXIT_FAILURE);
        }
        (*stack)->next->n = (*stack)->next->n % (*stack)->n;
        pop(stack, line_number);
        *stack = temp;
    }
    else
    {
        fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
        fclose(red);
        exit(EXIT_FAILURE);
    }
}
