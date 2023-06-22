#include "monty.h"

/**
 * _mul - multiply top element of the stack with the second top element
 * @head: double pointer to header (top) of the stack.
 * @line_number: counter for line number of the file.
 *
 * Return: void.
 */
void _mul(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_stack_t(*head);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n *= (*head)->n;
	stack_t *temp = *head;
	*head = (*head)->next;
	free(temp);
	(*head)->prev = NULL;
}
