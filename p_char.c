#include "monty.h"

/**
* f_pchar - Function that prints the
* character at the top of the stack,
* followed by a newline character.
* @head: Pointer to the head of the stack.
* @counter: Line count.
*
* Return: Nothing.
*/

void f_pchar(stack_t **head, unsigned int counter)
{
stack_t *current;

current = *head;
if (!current)
{
/* Empty stack */
fprintf(stderr, "L%d: can't print char, stack empty\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
if (current->n > 127 || current->n < 0)
{
/* Value out of range */
fprintf(stderr, "L%d: can't print char, value out of range\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
/* Print character */
printf("%c\n", current->n);
}
