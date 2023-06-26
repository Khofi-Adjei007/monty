#include "monty.h"

/**
* free_stack - Frees a doubly linked list.
* @head: Pointer to the head of the stack.
*
* This function iterates through the doubly linked list starting from the
* head node and frees each node until the end is reached. It properly updates
* the next and previous pointers of each node to maintain the integrity of
* the linked list structure.
*
* Return: None.
*/

void free_stack(stack_t *head)
{
stack_t *temp;

temp = head;
while (head)
{
temp = head->next;
free(head);
head = temp;
}
}

/**
* f_stack - Sets the stack mode to LIFO (stack).
* @head: Pointer to the head of the stack.
* @counter: Line count.
*
* This function sets the 'lifi' flag in the 'bus' structure to 0, indicating
* that the stack should operate in LIFO (stack) mode. It is used to switch
* the stack mode from queue (FIFO) to stack (LIFO) if necessary.
*
* Return: None.
*/

void f_stack(stack_t **head, unsigned int counter)
{
(void)head;
(void)counter;
bus.lifi = 0;
}
