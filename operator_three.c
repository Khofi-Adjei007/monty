#include "monty.h"

/**
 * f_pop - Function that removes the top element of the stack
 * @stack: Double pointer to the stack
 * @line_count: Line count
 *
 * Return: Nothing
 */

void f_pop(stack_t **stack, unsigned int line_count)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = temp->next;
	free(temp);
}

/**
 * f_pint - Function that prints the top element of the stack
 * @stack: Double pointer to the stack
 * @line_count: Line count
 *
 * Return: Nothing
 */

void f_pint(stack_t **stack, unsigned int line_count)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * f_nop - Function that performs no operation
 * @stack: Double pointer to the stack
 * @line_count: Line count
 *
 * Return: Nothing
 */

void f_nop(stack_t **stack, unsigned int line_count)
{
	(void)stack;
	(void)line_count;
}
