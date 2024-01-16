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
	
	if (move.argument)
	{
		if (move.argument[0] == '-')
			b++;
		for (; move.argument[b] != '\0'; b++)
		{
			if (move.argument[b] > 57 || move.argument[b] < 48)
				flag = 1;
		}
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", num_count);
			fclose(move.file_type);
			free(move.information);
			release_stack(*stack_head);
			exit(EXIT_FAILURE);
		}
	}
		else
		{ fprintf(stderr, "L%d: usage: push integer\n", num_count);
			fclose(move.file_type);
			free(move.information);
			release_stack(*stack_head);
			exit(EXIT_FAILURE);
		}
		n = atoi(move.argument);
		if (move.turnstyle == 0)
			newnode(stack_head, n);
		else
			addnew(stack_head, n);
}
