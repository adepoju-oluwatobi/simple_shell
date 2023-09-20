#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
/**
 *env - function: displays the current env.
 *@tokenized_cmd: shows the command entered in terminal
 *Return: nothing
 */
void env(char **tokenized_cmd __attribute__((unused)))
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		print(environ[i], STDOUT_FILENO);
		print("\n", STDOUT_FILENO);
	}
}
/**
 * quit - command that is used to exit the shell
 * @tokenized_cmd: shows the command enterd
 *
 * Return: nothing
 */
void quit(char **tokenized_cmd)
{
	int num_token = 0, arg;
	char **cmds = NULL;
	char *sh_name = NULL;
	char *line = NULL;
	int status = 0;

	for (; tokenized_cmd[num_token] != NULL; num_token++)
		;
	if (num_token == 1)
	{
		free(tokenized_cmd);
		free(line);
		free(cmds);
		exit(status);
	}
	else if (num_token == 2)
	{
		arg = _atoi(tokenized_cmd[1]);
		if (arg == -1)
		{
			print(sh_name, STDERR_FILENO);
			print(": 1: exit: Illegal number: ", STDERR_FILENO);
			print(tokenized_cmd[1], STDERR_FILENO);
			print("\n", STDERR_FILENO);
			status = 2;
		}
		else
		{
			free(line);
			free(tokenized_cmd);
			free(cmds);
			exit(arg);
		}
	}
	else
		print(":)>: exit doesn't take more than one argument\n", STDERR_FILENO);
}
