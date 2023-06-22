#include "monty.h"

/**
 * _sub - subtracts top element of the stack from the second top element.
 * @head: double pointer to header (top) of the stack.
 * @line_number: counter for line number of the file.
 *
 * Return: void.
 */
void _sub(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *current = *head;
	int result = current->next->n - current->n;
	*head = (*head)->next;
	free(current);
	(*head)->prev = NULL;
	(*head)->n = result;
}
