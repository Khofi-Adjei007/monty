#include "monty.h"

/**
 * add_node_to_stack - Function that adds a
 * new node to the head of the stack
 * @stack: Double pointer to the head of the stack
 * @value: Value to be stored in the new node
 *
 * Return: Nothing
 */

void add_node_to_stack(stack_t **stack, int value)
{
	stack_t *fresh_node, *temp;

	temp = *stack;
	fresh_node = malloc(sizeof(stack_t));
	if (fresh_node == NULL)
	{
		printf("Error: Failed to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	if (temp)
		temp->prev = fresh_node;

	fresh_node->n = value;
	fresh_node->next = *stack;
	fresh_node->prev = NULL;
	*stack = fresh_node;
}
