#include "monty.h"

/**
 * _mod - get the module of the second top element of the stack and top element
 * @head: double pointer to header (top) of the stack.
 * @line_number: counter for line number of the file.
 *
 * Return: void.
 */
void _mod(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_stack_t(*head);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n %= (*head)->n;
	stack_t *temp = *head;
	*head = (*head)->next;
	free(temp);
	(*head)->prev = NULL;
}
