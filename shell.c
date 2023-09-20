#include "main.h"
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <string.h>
/**
 * main - This is the Simple_Shell Main Code
 * @argc: arguments passed in program
 * @argv: arguments inj the programm yet to be parsed
 * Return: 0 on when the program is success
 */
int main(int argc __attribute__((unused)), char **argv)
{
    char **current_cmd = NULL;
    char **cmds = NULL;
    char *line = NULL;
    int status = 0;
    int sh_name = argv[0];  // Assign a value to sh_name
    int i, type_cmd = 0;
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

            /* initializer -   */
            init(current_cmd, type_cmd);
            free(current_cmd);
        }
        free(cmds);
    }
    free(line);

    return (status);
}
