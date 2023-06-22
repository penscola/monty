#include "monty.h"

/**
 * _nop - The opcode nop doesn’t do anything.
 * @head: double pointer to header (top) of the stack.
 * @line_number: counter for line number of the file.
 *
 * Return: void.
 */
void _nop(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;
}
