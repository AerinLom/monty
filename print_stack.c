#include "monty.h"

/**
  *
  *
  *
  *
  */

void print_all(stack_t **stack, unsigned int line_count)
{
	(void)line_count;

	stack_t *component = *stack;

	if (*stack == NULL)
	{
		return;
	}

	while (component != NULL)
	{
		printf("%d\n", component->n);
		component = component->next;
	}
}
