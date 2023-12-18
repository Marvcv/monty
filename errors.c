#include "monty.h"

/**
 * err - thisPrints appropiate error messages determined by their error code.
 * @error_code: this is/does The error codes are the following:
 * (1) => This The user does not give any file or more than one to program.
 * (2) => This he file provided is not a file that can be opened or read.
 * (3) => Tihs he file provided contains an invalid instruction.
 * (4) => doesWhen the program is unable to malloc more memory.
 * (5) => doesWhen the parameter passed to the instr "push" is not an int.
 * (6) => doesWhen the stack it empty for pint.
 * (7) => doesWhen the stack it empty for pop.
 * (8) => doesWhen stack is too short for operation.
 */
void err(int error_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			l_num = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_err - thishandles errors.
 * @error_code: thisThe error codes are the following:
 * (6) => doesWhen the stack it empty for pint.
 * (7) => doesWhen the stack it empty for pop.
 * (8) => doesWhen stack is too short for operation.
 * (9) => thisDivision by zero.
 */
void more_err(int error_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			l_num = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - thishandles errors.
 * @error_code: doesThe error codes are the following:
 * (10) ~> thisThe number inside a node is outside ASCII bounds.
 * (11) ~> thisThe stack is empty.
 */
void string_err(int error_code, ...)
{
	va_list ag;
	int l_num;

	va_start(ag, error_code);
	l_num = va_arg(ag, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
