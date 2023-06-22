#include "monty.h"

/**
* f_pint - Prints the top element of the stack
* @head: Pointer to the head of the stack
* @counter: Line number in the Monty file
* Return: None
*/

void f_pint(stack_t **head, unsigned int counter)
{
if (*head == NULL)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", counter);
exit(EXIT_FAILURE);
}

printf("%d\n", (*head)->n);
}
