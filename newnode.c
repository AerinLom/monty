#include "monty.h"
/**
 * newnode - function adds new node to stack
 * @stack_head: head of the stack
 * @n: new node
 * Return: nothing
 */
void newnode(stack_t **stack_head, int n)
{
	stack_t *fresh_node, *node_node;

	node_node = *stack_head;
	fresh_node = malloc(sizeof(stack_t));
	if (fresh_node == NULL)
	{ printf("Error\n");
		exit(0);
	}
	if (node_node)
		node_node->prev = fresh_node;
	fresh_node->n = n;
	fresh_node->next = *stack_head;
	fresh_node->prev = NULL;
	*stack_head = fresh_node;
}
