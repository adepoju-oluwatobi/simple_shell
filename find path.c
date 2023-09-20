#include "main.h"
/**
 * find_path - Finds the path of the cmd
 * @cmd: used cmd
 *
 * Return: path of cmd
 *
 */
char *find_path(char *cmd)
{
	char **path_array = NULL;
	char *temp, *temp2, *path_cpy;
	char *path = get_env("PATH");
	int i;

	if (path == NULL || string_length(path) == 0)
		return (NULL);
	path_cpy = malloc(sizeof(*path_cpy) * (string_length(path) + 1));
	string_copy(path, path_cpy);
	path_array = cmd_tokenizer(path_cpy, ":");
	for (i = 0; path_array[i] != NULL; i++)
	{
		temp2 = str_cat(path_array[i], "/");
		temp = str_cat(temp2, cmd);
		if (access(temp, F_OK) == 0)
		{
			free(temp2);
			free(path_array);
			free(path_cpy);
			return (temp);
		}
		free(temp);
		free(temp2);
	}
	free(path_cpy);
	free(path_array);
	return (NULL);
}
