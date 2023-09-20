#include "main.h"
/**
 *strtok_cmd - function: tokenizes a string in the program
 *@string: shows the string
 *@delim: delimiter: tokenizer
 *@save_ptr: pointer: keeps tracks of the tokens
 *Return: returns next token in line for tokenization
 */
char *strtok_cmd(char *string, char *delim, char **save_ptr)
{
	char *finish;

	if (string == NULL)
		string = *save_ptr;

	if (*string == '\0')
	{
		*save_ptr = string;
		return (NULL);
	}

	string += str_spn(string, delim);
	if (*string == '\0')
	{
		*save_ptr = string;
		return (NULL);
	}

	finish = string + str_comp_spn(string, delim);
	if (*finish == '\0')
	{
		*save_ptr = finish;
		return (string);
	}

	*finish = '\0';
	*save_ptr = finish + 1;
	return (string);
}
