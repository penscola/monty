#include "monty.h"

/**
 * _push -  pushes an element to the stack.
 * @stack: double pointer to header (top) of the stack.
 * @line_number: counter for line number of the file.
 *
 * Return: void.
 */
void _push(stack_t **stack, unsigned int line_number)
{
	size_t len = 0, i = 0;
	char arg[128] = "";
	char *argument = arg;

	argument = strtok(NULL, " \t\r\n\v\f");

	if (argument == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		free_stack_t(*stack);

		exit(EXIT_FAILURE);
	}

	len = strlen(argument);
	for (i = 0; i < len; i++)
		if (!isdigit(argument[i]) && argument[0] != '-')
		{
			dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
			free_stack_t(*stack);

			exit(EXIT_FAILURE);
		}

	if (stack_queue == 's')
		add_node(stack, atoi(argument));

	if (stack_queue == 'q')
		add_node_queue(stack, atoi(argument));
}

/**
 * add_node -  pushes an element to the stack.
 * @stack: double pointer to header (top) of the stack.
 * @argument: integer push.
 *
 * Return: void.
 */
void add_node(stack_t **stack, int argument)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_stack_t(*stack);

		exit(EXIT_FAILURE);
	}

	new_node->n = argument;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*stack == NULL)
		*stack = new_node;
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}

/**
 * add_node_queue -  pushes an element to the stack.
 * @stack: double pointer to header (top) of the stack.
 * @argument: integer push.
 *
 * Return: void.
 */
void add_node_queue(stack_t **stack, int argument)
{
	stack_t *new_node = NULL, *last = NULL;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_stack_t(*stack);

		exit(EXIT_FAILURE);
	}

	new_node->n = argument;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*stack == NULL)
		*stack = new_node;
	else
	{
		last = *stack;
		while (last->next != NULL)
			last = last->next;
		new_node->next = NULL;
		new_node->prev = last;
		last->next = new_node;
	}
}
