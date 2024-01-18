#include "monty.h"

/**
  *ip - Execute Monty ByteCode operation based on opcode
  *@token: Opcode to execute
  *@stack: Pointer to the stack
  *@line_number: Current line number in the file
  *@file_type: Pointer to the file
  *Return: 0 if successful, 1 if not.
  */

int ip(char *token, stack_t **stack,
		unsigned int line_number, FILE *file_type)
{
	instruction_t instructions[] = {
		{"push", node_push},
		{"	push", node_push},
		{"		push", node_push},
		{"pall", print_all},
		{"pint", top_pint},
		{"pop", pop_sicle},
		{"nop", no_nop},
		{"swap", swap_op},
		{"add", add_op},
		{NULL, NULL}
	};

	int count = 0;
	char *character;

	character = strtok(module.information, " \t\n");
	if (character == NULL || character[0] == '#')
	{
		return (0);
	}
	module.argument = strtok(NULL, " \n\t");
	while (instructions[count].opcode != NULL)
	{
		if (strcmp(token, instructions[count].opcode) == 0)
		{
			instructions[count].f(stack, line_number);
			return (0);
		}
		count++;
	}
	if (character && instructions[count].opcode == NULL)
	{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, character);
	fclose(file_type);
	free(token);
	release_stack(*stack);
	exit(EXIT_FAILURE);
	}
	return (1);
}
