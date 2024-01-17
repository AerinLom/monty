#include "monty.h"
/**
 * release_stack - function releases a linked list
 * @stack_head: head of the stack
 */
void release_stack(stack_t *stack_head)
{
	stack_t *node_node;

	node_node = stack_head;

	while (stack_head)
	{
		node_node = stack_head->next;
		free(stack_head);
		stack_head = node_node;
	}
}
