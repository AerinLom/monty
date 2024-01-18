#include "monty.h"
/**
 * node_push - func plaes node to a stack
 * @stack_head: the stack of the head
 * @num_count: counts number of lines
 * Return: nothing
 */
void node_push(stack_t **stack_head, unsigned int num_count)
{
	int n = 0;

	int b = 0;

	int flag = 0;

	if (module.argument)
	{
		if (module.argument[0] == '-')
			b++;
		for (; module.argument[b] != '\0'; b++)
		{
			if (module.argument[b] > 57 || module.argument[b] < 48)
				flag = 1;
		}
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", num_count);
			fclose(module.file_type);
			free(module.information);
			release_stack(*stack_head);
			exit(EXIT_FAILURE);
		}
	}
		else
		{ fprintf(stderr, "L%d: usage: push integer\n", num_count);
			fclose(module.file_type);
			free(module.information);
			release_stack(*stack_head);
			exit(EXIT_FAILURE);
		}
		n = atoi(module.argument);
		if (module.turnstyle == 0)
			newnode(stack_head, n);
}
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
		fclose(module.file_type);
		free(module.information);
		release_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack_head)->n);
}
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
