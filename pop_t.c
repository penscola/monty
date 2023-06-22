#include "monty.h"

/**
 * _pop - removes the top elements of the stack.
 * @stack: double pointer to header (top) of the stack.
 * @line_number: counter for line number of the file.
 *
 * Return: void.
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_stack_t(*stack);
		exit(EXIT_FAILURE);
	}

	stack_t *current = *stack;
	*stack = (*stack)->next;

	if (*stack)
		(*stack)->prev = NULL;

	free(current);
}
