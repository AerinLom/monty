#include "monty.h"

/**
  *swap_op - Swaps the top two elements of the stack.
  *@stack_head: Pointer to the head of the stack
  *@line_number: Line number in the Monty bytecode file
  */

void swap_op(stack_t **stack_head, unsigned int line_number)
{
	stack_t *temp_node;

	if (*stack_head == NULL || (*stack_head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		fclose(module.file_type);
		free(module.information);
		release_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	temp_node = (*stack_head)->next;
	(*stack_head)->next = temp_node->next;

	if (temp_node->next != NULL)
	{
		temp_node->next->prev = *stack_head;
	}
	temp_node->prev = NULL;
	temp_node->next = *stack_head;
	(*stack_head)->prev = temp_node;
	*stack_head = temp_node;
}
