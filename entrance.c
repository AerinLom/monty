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
	ssize_t read = 1;

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

	while (read > 0)
	{
		token = NULL;
		read = getline(&token, &len, file_type);
		module.information = token;
		line_number++;

		if (read > 0)
		{
			ip(token, &stack, line_number, file_type);
		}
		free(token);
	}
	release_stack(stack);
	fclose(file_type);
	return (0);
}
