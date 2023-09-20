#include "main.h"
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * non_interactive_mode - handler for non-interaction
 *
 * Return: nothing
 */
void non_interactive_mode(void)
{
	char **current_cmd = NULL;
	int i, type_cmd = 0;
	size_t n = 0;

	if (!(isatty(STDIN_FILENO)))
	{
		while (getline(&line, &n, stdin) != -1)
		{
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
		exit(status);
	}
}
