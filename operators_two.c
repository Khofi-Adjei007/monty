#include "monty.h"

/**
 * push_to_stack - Function that adds a new node to the stack.
 * @head: Double pointer to the head of the stack.
 * @counter: Line count in the Monty file.
 *
 * Return: Nothing.
 */
void push_to_stack(stack_t **head, unsigned int counter)
{
	int is_negative = 0;
	int has_non_numeric = 0;
	int value;

	int i;
	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			is_negative++;
		for (i = is_negative; bus.arg[i] != '\0'; i++)
		{
			if (bus.arg[i] > '9' || bus.arg[i] < '0')
				has_non_numeric = 1;
		}
		if (has_non_numeric)
		{
			fprintf(stderr, "Error: L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "Error: L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	value = atoi(bus.arg);
	if (bus.lifi == 0)
		push_to_stack(head, value);
	else
		addqueue(head, value);
}
