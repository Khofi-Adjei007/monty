#include "monty.h"

/**
* f_rotate_left - Function that rotates the stack to the left.
* @head: Pointer to the head of the stack.
* @counter: Line count (unused).
*
* Description: This function rotates the stack by moving the top
*              element to the bottom of the stack.
*
* Return: Nothing.
*/

void f_rotate_left(stack_t **head,
		__attribute__((unused)) unsigned int counter)
{
stack_t *current = *head;  /* Current node */
stack_t *next_node;  /* Next node */

if (*head == NULL || (*head)->next == NULL)
{
return; /* Nothing to rotate */
}

next_node = (*head)->next;
next_node->prev = NULL;

/* Traverse to the last node */
while (current->next != NULL)
{
current = current->next;
}

/* Make the last node the new head */
current->next = *head;
(*head)->next = NULL;
(*head)->prev = current;
(*head) = next_node;
}
