#include "monty.h"

module_t module = {NULL, NULL, NULL, 0};

/**
 * main - Entry point for Monty ByteCode Interpreter
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *file_type;
	char *token;
	size_t len = 0;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_type = fopen(argv[1], "r");
	module.file_type = file_type;

	if (!file_type)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free(token);
		exit(EXIT_FAILURE);
	}

	while (getline(&token, &len, file_type) > 0)
	{
		module.information = token;
		line_number++;
		ip(token, &stack, line_number, file_type);
	}
	free(token);
	release_stack(stack);
	fclose(file_type);
	return (0);
}

/**
  *close_free - Performs cleanup
  *@stack_head: Pointer to the head of the stack
  *@exit_code: Exit code to use
  */

void close_free(stack_t **stack_head, unsigned int exit_code)
{
	fclose(module.file_type);
	free(module.information);
	release_stack(*stack_head);
	exit(exit_code);
}

/**
 * newnode - function adds new node to stack
 * @stack_head: head of the stack
 * @n: new node
 * Return: nothing
 */
void newnode(stack_t **stack_head, int n)
{
	stack_t *fresh_node;

	fresh_node = malloc(sizeof(stack_t));
	if (!fresh_node)
	{
		printf("Error\n");
		exit(0);
	}

	fresh_node->n = n;
	fresh_node->next = *stack_head;
	fresh_node->prev = NULL;

	if (*stack_head)
	{
		(*stack_head)->prev = fresh_node;
	}

	*stack_head = fresh_node;
}

/**
 * release_stack - function releases a linked list
 * @stack_head: head of the stack
 */
void release_stack(stack_t *stack_head)
{
	stack_t *node_node;

	for (node_node = stack_head; stack_head; node_node = stack_head)
	{
		stack_head = stack_head->next;
		free(node_node);
	}
}
