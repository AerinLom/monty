#include "monty.h"
/**
 * pop_sicle - prints pop to the top
 * @stack_head: stack of the head
 * @num_count: line number
 * Return: nothing
 */
void pop_sicle(stack_t **stack_head, unsigned int num_count)
{
	stack_t *component;

	if (*stack_head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", num_count);
		fclose(module.file_type);
		free(module.information);
		release_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	component = *stack_head;
	*stack_head = component->next;
	free(component);
}
