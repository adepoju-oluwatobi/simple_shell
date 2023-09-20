#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
/**
 * _realloc - function: re allocated the memmory
 *
 * @ptr: shows previously allocated memmory
 * @old_sz: function: size of pointer
 * @new_sz: function: shows the new size of memmory
 *
 * Return: returns memmory address
 *
 *
 */
void *_realloc(void *ptr, unsigned int old_sz, unsigned int new_sz)
{
	void *temp_block;
	unsigned int i;

	if (ptr == NULL)
	{
		temp_block = malloc(new_sz);
		return (temp_block);
	}
	else if (new_sz == old_sz)
		return (ptr);
	else if (new_sz == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		temp_block = malloc(new_sz);
		if (temp_block != NULL)
		{
			for (i = 0; i < min(old_sz, new_sz); i++)
				*((char *)temp_block + i) = *((char *)ptr + i);
			free(ptr);
			return (temp_block);
		}
		else
			return (NULL);

	}
}


/**
 * ctrl_c_handler - function: handles the signal [CTRL + C]
 *
 * @signum:shows the number of the signal
 *
 * Return: nothing
 */
void ctrl_c_handler(int signum)
{
	if (signum == SIGINT)
		print("\n :)> ", STDIN_FILENO);
}



