#include "main.h"
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <string.h>
/**
 * main - This is the Simple_Shell Main Code
 * Return: 0 on when the program is success
 */
int main(void)
{
	char **current_cmd = NULL, **cmds = NULL, *line = NULL;
	int status = 0, i, type_cmd = 0;
	size_t n = 0;

	signal(SIGINT, ctrl_c_handler);

	while (1)
	{
		non_interactive_mode();
		print(" :)> ", STDOUT_FILENO);
		if (getline(&line, &n, stdin) == -1)
		{
			free(line);
			exit(status);
		}
		rm_newline(line);
		rm_comment(line);
		cmds = cmd_tokenizer(line, ";");

		for (i = 0; cmds[i] != NULL; i++)
		{
			current_cmd = cmd_tokenizer(cmds[i], " ");
			if (current_cmd[0] == NULL)
			{
				free(current_cmd);
				break;
			}

			type_cmd = parse_cmd(current_cmd[0]);
			init(current_cmd, type_cmd);
			free(current_cmd);
		}
		free(cmds);
	}
	free(line);
	return (status);
}
