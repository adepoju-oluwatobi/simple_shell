#include "main.h"

/** 
 * parse_cmd - identifies the cmd type
 * @cmd: shows to the cmd that is to be passed
 * Return: The constant showing the type of the cmd
 */
int parse_cmd(char *cmd)
{
	int i;
	char *internal_cmd[] = {"env", "exit", NULL};
	char *path = NULL;

	for (i = 0; cmd[i] != '\0'; i++)
	{
		if (cmd[i] == '/')
			return (EXTERNAL_CMD);
	}
	for (i = 0; internal_cmd[i] != NULL; i++)
	{
		if (str_cmp(cmd, internal_cmd[i]) == 0)
			return (INTERNAL_CMD);
	}
	/**
	 * @find_path - checks the path  of the program file
	 *
	 */
	path = find_path(cmd);
	if (path != NULL)
	{
		free(path);
		return (PATH_CMD);
	}

	return (INVALID_CMD);
}
