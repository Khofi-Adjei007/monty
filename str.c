#include "monty.h"

/**
* print_string - Function that prints the string
* starting at the top of the stack,
* followed by a newline character
* @stack: Double pointer to the head of the stack
* @counter: Line count (unused)
*
* Return: Nothing
*/

void print_string(stack_t **stack, unsigned int counter)
{

stack_t *current_node;
(void)counter;

current_node = *stack;

while (current_node)
{

/* Check if the value is outside the ASCII printable range */
if (current_node->n > 127 || current_node->n <= 0)
{
break;
}

/* Print the character corresponding to the value */
printf("%c", current_node->n);
current_node = current_node->next;
}
printf("\n");
}
