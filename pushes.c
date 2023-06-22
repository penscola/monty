#include "monty.h"

/**
 * _pall - prints all the elements of the stack.
 * @stack: double pointer to header (top) of the stack.
 * @line_number: counter for line number of the file.
 *
 * Return: void.
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
