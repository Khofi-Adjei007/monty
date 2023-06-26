#include "monty.h"

/**
* execute - Executes the opcode specified in the content.
* @content: Line content.
* @stack: Pointer to the head of the stack.
* @counter: Line count.
* @file: Pointer to the Monty file stream.
*
* This function searches for the opcode
* specified in the 'content' string
* and executes the corresponding function.
* It iterates through the 'opst'
* array of instruction structures,
* compares the opcode with each entry,
* and calls the associated function if a
* match is found. If no matching
* opcode is found, it prints an error
* message and terminates the program.
*
* Return: None.
*/

void execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
instruction_t opst[] = {
{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
{"pop", f_pop},
{"swap", f_swap},
{"add", f_add},
{"nop", f_nop},
{"sub", f_sub},
{"div", f_div},
{"mul", f_mul},
{"mod", f_mod},
{"pchar", f_pchar},
{"pstr", f_pstr},
{"rotl", f_rotl},
{"rotr", f_rotr},
{"queue", f_queue},
{"stack", f_stack},
{NULL, NULL}
};
unsigned int i = 0;
char *op;

op = strtok(content, " \n\t");
if (op && op[0] == '#')
return; /* Ignore comment lines */

bus.arg = strtok(NULL, " \n\t");

while (opst[i].opcode && op)
{
if (strcmp(op, opst[i].opcode) == 0)
{
	opst[i].f(stack, counter); /* Call the opcode's function */
	return;
}
i++;
}

if (op && opst[i].opcode == NULL)
{
fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
fclose(file);
free(content);
free_stack(*stack);
exit(EXIT_FAILURE);
}
}
