#include "monty.h"
/**
 * node_push - func plaes node to a stack
 * @stack_head: the stack of the head
 * @num_count: counts number of lines
 * Return: nothing
 */
void node_push(stack_t **stack_head, unsigned int num_count)
{
	int a = 0;

	int b = 0;

	flag = 0;

	if (move.arg[0] == '-')
		b++;
	for (; move.arg[b] != '\0'; b++)
	{
		if (move.arg[b] > 57 || move.arg[b] < 48)
			flag = 1;
	}
	if (flag == 1)
	{ fprintf(stderr, "L%d: usage: push integer\n", num_count);
		fclose(move.file);
		free(move.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", num_count);
		fclose(move.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	a = atoi(move.arg);
	if (move.lifi == 0)
		addnode(stack_head, a);
	else
		addqueue(stack_head, a);
}
