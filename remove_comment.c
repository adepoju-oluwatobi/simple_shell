#include "main.h"
/**
 * rm_comment -function: ignores what is a comment
 *
 * @input: shows the intended input
 *
 * Return: nothing
 *
 */
void rm_comment(char *input)
{
	int i = 0;

	if (input[i] == '#')
		input[i] = '\0';
	while (input[i] != '\0')
	{
		if (input[i] == '#' && input[i - 1] == ' ')
			break;
		i++;
	}
	input[i] = '\0';
}
