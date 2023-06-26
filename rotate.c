#include "monty.h"


/**
* f_rotr - Function that rotates the stack to the bottom.
* @head: Pointer to the head of the stack.
* @counter: Line count (unused).
*
* Description: This function rotates the stack by moving the bottom
*              element to the top of the stack.
*
* Return: Nothing.
*/
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
stack_t *last; /* Pointer to the last node in the stack */
stack_t *current; /* Pointer to traverse the stack */

current = *head;
if (*head == NULL || (*head)->next == NULL)
{
return; /* Nothing to rotate */
}

/* Find the last node in the stack */
while (current->next)
{
current = current->next;
}

last = current;

/* Perform rotation */
last->next = *head;
last->prev->next = NULL;
last->prev = NULL;
(*head)->prev = last;
(*head) = last;
}
