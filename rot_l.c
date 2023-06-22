#include "monty.h"

/**
 * _rotl - rotates the stack to the top.
 * @stack: double pointer to header (top) of the stack.
 * @line_number: counter for line number of the file.
 *
 * Return: void.
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	stack_t *first = *stack;
	stack_t *second = first->next;

	while (second->next != NULL)
		second = second->next;

	first->prev = second;
	second->next = first;
	first->next = NULL;
	*stack = second;
}
