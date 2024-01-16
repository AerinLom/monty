#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct move_a - variables -argument, file_type, information
 * @argument: arg value
 * @file_type: points to monty file type
 * @turnstyle: change stack
 * @information: data in each line 
 * Description: structure of variables
 */
typedef struct move_a
{
	char *argument;
	FILE *file_type;
	char *information;
	int turnstyle;
} move_b;
extern move_b move;

void node_push(stack_t **head, unsigned int num_count);
void top_pint(stack_t **stack_head, unsigned int num_count);
void no_nop(stack_t **stack_head, unsigned int num_count);
void newnode(stack_t **stack_head, int n);
void addnew(stack_t **stack_head, int n);
void release_stack(stack_t *head);
void print_all(stack_t **stack_head, unsigned int line_count);

#endif
