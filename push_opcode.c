#include "monty.h"
/**
 * node_push - func plaes node to a stack
 * @stack_head: the stack of the head
 * @num_count: counts number of lines
 * Return: nothing
 */
void node_push(stack_t **stack_head, unsigned int num_count)
{
	int n = 0;

	int b = 0;

	int flag = 0;

	if (module.argument)
	{
		if (module.argument[0] == '-')
			b++;
		for (; module.argument[b] != '\0'; b++)
		{
			if (module.argument[b] > 57 || module.argument[b] < 48)
				flag = 1;
		}
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", num_count);
			fclose(module.file_type);
			free(module.information);
			release_stack(*stack_head);
			exit(EXIT_FAILURE);
		}
	}
		else
		{ fprintf(stderr, "L%d: usage: push integer\n", num_count);
			fclose(module.file_type);
			free(module.information);
			release_stack(*stack_head);
			exit(EXIT_FAILURE);
		}
		n = atoi(module.argument);
		if (module.turnstyle == 0)
			newnode(stack_head, n);
}
