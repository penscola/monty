#include "monty.h"

/**
 * _mul -  multiply top element of the stack with the second top element
 * @head: top of the stack
 * @line_number: line number where a wrong command was found
 * Return: void
 */
void _mul(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	int nnodes = 1; /*number of elements in stack*/

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_stack_t(*head);

		exit(EXIT_FAILURE);
	}


	while (current->next != NULL)
	{
		current = current->next;
		nnodes++;
	}

	if (nnodes + 1 <= 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_stack_t(*head);

		exit(EXIT_FAILURE);
	}

	current = *head; /*current equals to head to make mul*/

	current->next->n = current->next->n * current->n; /*do the mul*/

	*head = current->next;
	free(current);
	current->prev = NULL;

}
