#include "monty.h"

/**
* f_queue - Function that switches the stack mode to queue mode.
* @head: Pointer to the head of the queue.
* @counter: Line count.
*
* Description: This function sets the stack mode to queue mode,
* indicating that elements should be added to the
* tail of the queue.
*
* Return: Nothing.
*/

void f_queue(stack_t **head, unsigned int counter)
{
(void)head;
(void)counter;
bus.lifi = 0; /* Set stack mode to queue (lifo = 0) */
}

/**
* addqueue - Function that adds a node to the tail of the queue.
* @value: New value to be added.
* @head: Pointer to the head of the queue.
*
* Description: This function creates a new node with the given value
* and adds it to the tail of the queue.
*
* Return: Nothing.
*/
void addqueue(stack_t **head, int value)
{
stack_t *new_node, *temp;

temp = *head;
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
printf("Error\n");
/* Handle error case: unable to allocate memory for new node */
}
new_node->n = value;
new_node->next = NULL;
if (temp)
{
while (temp->next)
temp = temp->next;
}
if (!temp)
{
/* Empty queue: Set new node as the head */
*head = new_node;
new_node->prev = NULL;
}
else
{
/* Non-empty queue: Add new node to the tail */
temp->next = new_node;
new_node->prev = temp;
}
}
