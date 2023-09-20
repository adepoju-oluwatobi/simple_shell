#include "main.h"
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>

/**
 * init -function: intializes execution
 * @current_cmd: checks the recent or current cmd
 *
 * @type_cmd: shows the type cmd parse token
 *
 * Return: nothing
 */
void init(char **current_cmd, int type_cmd)
{
	pid_t PID;
	int status = 0;

	if (type_cmd == EXTERNAL_CMD || type_cmd == PATH_CMD)
	{
		PID = fork();
		if (PID == 0)
			exec_cmd(current_cmd, type_cmd);
		else
		{
			waitpid(PID, &status, 0);
			status >>= 8;
		}
	}
	else
		exec_cmd(current_cmd, type_cmd);
}
