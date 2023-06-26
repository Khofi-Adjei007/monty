#include "monty.h"

/**
 * f_pall - Function that prints all elements in the stack
 * @head: Double pointer to the head of the stack
 * @counter: Unused line count
 *
 * Return: Nothing
 */
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *current;
	(void) counter;

	current = *head;
	if (current == NULL)
		return;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * f_swap - Function that swaps the top two elements of the stack
 * @head: Double pointer to the head of the stack
 * @counter: Line count
 *
 * Return: Nothing
 */
void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *current;
	int length = 0;
	int temp;

	current = *head;
	while (current)
	{
		current = current->next;
		length++;
	}

	if (length < 2)
	{
		fprintf(stderr, "L%d: unable to perform swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	current = *head;
	temp = current->n;
	current->n = current->next->n;
	current->next->n = temp;
}
