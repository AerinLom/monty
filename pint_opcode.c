#include "monty.h"
/**
 * top_pint - prints the value at the top of stack
 * @stack_head: stack of the head
 * @num_count: line number
 * Return: nothing
 */
void top_pint(stack_t **stack_head, unsigned int num_count)
{
	if (*stack_head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", num_count);
		fclose(move.file);
		free(move.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack_head)->a);
}
