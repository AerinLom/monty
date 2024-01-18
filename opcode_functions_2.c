#include "monty.h"

/**
  *add_op - Adds the top two elements of the stack.
  *@stack_head: Pointer to the head of the stack
  *@line_number: Line number in the Monty bytecode file
  */

void add_op(stack_t **stack_head, unsigned int line_number)
{
	stack_t *temp_node;

	if (*stack_head == NULL || (*stack_head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		fclose(module.file_type);
		free(module.information);
		release_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	temp_node = (*stack_head)->next;
	temp_node->n += (*stack_head)->n;

	*stack_head = temp_node;
	free((*stack_head)->prev);
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
	(void) stack_head;
	(void) num_count;
}
