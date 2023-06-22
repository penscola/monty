#include "monty.h"

/**
 * _queue - select stack mode (default).
 * @stack: double pointer to header (top) of the stack.
 * @line_number: counter for line number of the file.
 *
 * Return: void.
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	stack_queue = 'q';
}
