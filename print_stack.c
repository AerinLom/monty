#include "monty.h"

/**
  *
  *
  *
  *
  */

void print_all(stack_t **stack_head, unsigned int line_count)
{
	stack_t *component;

	(void)line_count;

	component = *stack_head;

	if (component == NULL)
		return;
	while (component)
	{
		printf("%d\n", component->n);
		component = component->next;
	}
}
