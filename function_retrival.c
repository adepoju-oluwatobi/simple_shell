#include "main.h"
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
/**
 * get_function - retrives function
 *
 * @cmd: checks mapping against the string
 *
 * Return: proper function pointer
 *
 */
void (*get_function(char *cmd))(char **)
{
	int i;
	func_map mapping[] = {
		{"env", env}, {"exit", quit}
	};

	for (i = 0; i < 2; i++)
	{
		if (str_cmp(cmd, mapping[i].cmd_name) == 0)
			return (mapping[i].func);
	}
	return (NULL);
}
