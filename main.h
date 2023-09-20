#ifndef __SHELL_H
#define __SHELL_H

#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <string.h>

/*alx-simple_shell constants*/
#define INVALID_CMD -1
#define EXTERNAL_CMD 1
#define INTERNAL_CMD 2
#define PATH_CMD 3

/*define prompts*/
#define min(x, y) (((x) < (y)) ? (x) : (y))

typedef struct map
{
	char *cmd_name;
	void (*func)(char **cmd);
} func_map;


/***extern global****/
extern char **environ;
extern char *line;
extern char **cmds;
extern char *sh_name;
extern int status;


/**Helpers_1**/
void rm_newline(char *);
int string_length(char *);
void string_copy(char *, char *);
void print(char *, int);
char **cmd_tokenizer(char *, char *);
ssize_t readline(char **lineptr, size_t *n, FILE *stream);

/**Helpers_2**/
int str_comp_spn(char *, char *);
char *str_chr(char *, char);
int str_cmp(char *, char *);
char *str_cat(char *, char *);
int str_spn(char *, char *);

/**Helpers_3**/
void ctrl_c_handler(int);
void rm_comment(char *);
void *_realloc(void *ptr, unsigned int old_sz, unsigned int new_sz);
char *strtok_cmd(char *, char *, char **);
int _atoi(char *);

/**Utilities**/
void exec_cmd(char **, int);
char *find_path(char *);
void (*get_function(char *))(char **);
char *get_env(char *);
int parse_cmd(char *);

/**Buletins**/
void quit(char **);
void env(char **);

/**Main_funcs**/
extern void init(char **current_cmd, int type_cmd);
extern void non_interactive_mode(void);
#endif

/********************HEADER FILE************************/
