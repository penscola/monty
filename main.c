#include "monty.h"

char stack_queue = 's';

/**
 * main - Entry point
 * @argc: number of arguments passed as parameter to main program.
 * @argv: array of strings with the parameters passed to main program
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on any failure.
 */
int main(int argc, char *argv[])
{
	FILE *stream = NULL;
	size_t len = 0;
	unsigned int line_number = 1;
	char *line = NULL;
	char *code = NULL;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, stream) != -1)
	{
		code = strtok(line, " \t\r\n\v\f");
		if (code != NULL && code[0] != '#')
			get_opcode(&stack, line_number, code);
		line_number++;
	}

	free_stack_t(stack);
	stack = NULL;
	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}

/**
 * get_opcode - reads opcode and verifies if is valid.
 * @stack: double pointer to header (top) of the stack.
 * @line_number: counter for line number of the file.
 * @code: opcode to excecute.
 *
 * Return: void.
 */
void get_opcode(stack_t **stack, unsigned int line_number, char *code)
{
	int i = 0;
	instruction_t opcode_func[] = {
		{"add", _add},
		{"div", _div},
		{"mod", _mod},
		{"mul", _mul},
		{"nop", _nop},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"push", _push},
		{"sub", _sub},
		{"swap", _swap},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotr", _rotr},
		{"rotl", _rotl},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}
	};

	while (opcode_func[i].opcode)
	{
		if (strcmp(opcode_func[i].opcode, code) == 0)
		{
			opcode_func[i].f(stack, line_number);
			return;
		}
		i++;
	}
	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", line_number, code);
	free_stack_t(*stack);
	/**
	 * close_file
	 */
	exit(EXIT_FAILURE);
}

/**
 * free_stack_t - function that free a list of type dlistint_t
 * @head: pointer to a list type stack_t
 *
 * Return: void.
 */
void free_stack_t(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
