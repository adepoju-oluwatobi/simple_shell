#include "main.h"

/**
 * exec_cmd - a cmd is executed based on type
 * @tokenized_cmd:cmd with options
 * @cmd_type: shows the type of the cmd
 * Return: void
 */

void exec_cmd(char **tokenized_cmd, int cmd_type)
{
	void (*func)(char **cmd);
	char *sh_name = NULL

	if (cmd_type == EXTERNAL_CMD)
	{
		if (execve(tokenized_cmd[0], tokenized_cmd, NULL) == -1)
		{
			perror(get_env("PWD"));
			exit(2);
		}
	}
	if (cmd_type == PATH_CMD)
	{
		if (execve(find_path(tokenized_cmd[0]), tokenized_cmd, NULL) == -1)
		{
			perror(get_env("PWD"));
			exit(2);
		}
	}
	if (cmd_type == INTERNAL_CMD)
	{
		func = get_function(tokenized_cmd[0]);
		func(tokenized_cmd);
	}
	if (cmd_type == INVALID_CMD)
	{
		print(sh_name, STDERR_FILENO);
		print(": 1: ", STDERR_FILENO);
		print(tokenized_cmd[0], STDERR_FILENO);
		print(": not found\n", STDERR_FILENO);
	}
}
