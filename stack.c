#include "monty.h"
#include <string.h>


void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);


/**
 * free_stack - fres stack_t stack.
 * @stack: ptr to top or bottom of stack_t.
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * init_stack - initilizes stack_t stack with begining stack and ending queue nodes.
 * @stack: ptr to unitialized stack_t stack.
 * Return: If ever error occurs - EXIT_FAILURE.
 * Otherwise - EXIT_SUCCESS.
 */
int init_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (malloc_error());

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;


	return (EXIT_SUCCESS);
}

/**
 * check_mode - checks if stack_t linked list is in a stack mod or queue mod.
 * @stack: pointr to the top or bottom of stack_t linked list.
 * Return: If the stack_t is in stack mode - stack (0).
 * If the stack_t is in queue mode - queue (1).
 * Otherwise - 2.
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}

