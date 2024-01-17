#include "monty.h"

/**
  *print_all - function that prints the stack
  *@stack_head: pointer to head of stack
  *@line_count: line number
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
