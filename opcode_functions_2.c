#include "monty.h"

/**
  *add_op - Adds the top two elements of the stack.
  *@stack_head: Pointer to the head of the stack
  *@line_number: Line number in the Monty bytecode file
  */

void add_op(stack_t **stack_head, unsigned int line_number)
{
	if (!*stack_head || !(*stack_head)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		close_free(stack_head, EXIT_FAILURE);
	}

	(*stack_head)->next->n += (*stack_head)->n;
	free(*stack_head);
	*stack_head = (*stack_head)->next;
	(*stack_head)->prev = NULL;
}
#include "monty.h"
/**
 * no_nop - function has no usage
 * @stack_head: stack of the head
 * @num_count: line number
 * Return: nothing
 */
void no_nop(stack_t **stack_head, unsigned int num_count)
{
	(void) stack_head, (void) num_count;
}
