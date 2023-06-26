#include "monty.h"

/**
 * add_top_two_elements - Adds the top two elements of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty file.
 *
 * Return: Nothing.
 */

void add_top_two_elements(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int length = 0, result;

	current = *stack;
	while (current)
	{
		current = current->next;
		length++;
	}

	if (length < 2)
	{
		fprintf(stderr, "Error: L%d: can't add, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	result = current->n + current->next->n;
	current->next->n = result;
	*stack = current->next;
	free(current);
}

/**
 * subtract_top_from_second - Subtracts the top element
 * from the second top element of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty file.
 *
 * Return: Nothing.
 */
void subtract_top_from_second(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int difference, count;

	temp = *stack;
	for (count = 0; temp != NULL; count++)
		temp = temp->next;

	if (count < 2)
	{
		fprintf(stderr, "Error: L%d: can't sub, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	difference = temp->next->n - temp->n;
	temp->next->n = difference;
	*stack = temp->next;
	free(temp);
}

/**
 * multiply_top_two_elements - Multiplies the top
 * two elements of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty file.
 *
 * Return: Nothing.
 */
void multiply_top_two_elements(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int length = 0, result;

	current = *stack;
	while (current)
	{
		current = current->next;
		length++;
	}

	if (length < 2)
	{
		fprintf(stderr, "Error: L%d: can't mul, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	result = current->next->n * current->n;
	current->next->n = result;
	*stack = current->next;
	free(current);
}

/**
 * divide_second_by_top - Divides the second top element
 * by the top element of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty file.
 *
 * Return: Nothing.
 */
void divide_second_by_top(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int length = 0, result;

	current = *stack;
	while (current)
	{
		current = current->next;
		length++;
	}

	if (length < 2)
	{
		fprintf(stderr, "Error: L%d: can't div, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	if (current->n == 0)
	{
		fprintf(stderr, "Error: L%d: division by zero\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	result = current->next->n / current->n;
	current->next->n = result;
	*stack = current->next;
	free(current);
}

/**
 * compute_remainder - Computes the remainder of the
 * division of the second top element by the
 * top element of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty file.
 *
 * Return: Nothing.
 */
void compute_remainder(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int length = 0, result;

	current = *stack;
	while (current)
	{
		current = current->next;
		length++;
	}

	if (length < 2)
	{
		fprintf(stderr, "Error: L%d: can't mod, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	if (current->n == 0)
	{
		fprintf(stderr, "Error: L%d: division by zero\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	result = current->next->n % current->n;
	current->next->n = result;
	*stack = current->next;
	free(current);
}
