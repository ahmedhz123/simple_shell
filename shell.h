#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3

/* to convert number() */
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/* 1 if using system getline() */

#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 4096

extern char **environ;

/**
 * struct liststr - singly linked list
 *
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 *
 * description: linked lists
*/

typedef struct liststr
{
	int len;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - contain pseudo-arguments to pass into a function
 *		allowing uniform prototype for function pointer struct
 *
 * @arg: a string generated from getline containing arguments
 * @argv: an array of strings generated from arg
 * @path: a string path for the cuurent command
 * @argc: the argument count
 * @line_count: the error count
 * @linecount_flag: if no count this line of input
 * @fname: the program filename
 * @env: linked list local copy of environ
 * @err_num: the error code for exit()s
 * @environ: custom modified copy of environ from LL env
 * @history: the history mode
 * @alias: the alias node
 * @env_changed: on if environ was changed
 * @status: the return status of the last exec'd command
 * @cmd_buf: address of pointer to cmd_buf, on if chaining
 * @cmd_buf_type: CDM_type ||, &&, semicolon
 * @readfd: the fd from which to read line input
 * @histcount: the history line number count
*/

typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 * struct builtin - contains a builtin string and related function
 *
 * @type: the bulit command flag
 * @func: the function
*/

typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

void _puts(char *str);
char *_strcpy(char *dest, char *src);
int _putchar(char c);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
char *_strchr(char *s, char c);
char *_strdup(char *str);
char *starts_with(const char *haystack, const char *needle);
char **strtow2(char *str, char d);
char **strtow(char *str, char *d);
char *_getenv(info_t *info, const char *name);
int _mysetenv(info_t *info);
int _myunsetenv(info_t *info);
int populate_env_list(info_t *info);
int _setenv(info_t *info, char *var, char *value);
int _unsetenv(info_t *info, char *var);
char **get_environ(info_t *info);
size_t print_list(const list_t *h);
size_t list_len(const list_t *h);
list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);
list_t *add_node(list_t **head, const char *str);
char **list_to_strings(list_t *head);
ssize_t get_node_index(list_t *head, list_t *node);
list_t *node_starts_with(list_t *node, char *prefix, char c);
size_t print_list_str(const list_t *h);
int delete_node_at_index(list_t **head, unsigned int index);
int _myhelp(info_t *info);
int _mycd(info_t *info);
int _myexit(info_t *info);
int _myhistory(info_t *info);
int unset_alias(info_t *info, char *str);
int set_alias(info_t *info, char *str);
int print_alias(list_t *node);
int _myalias(info_t *info);
void ffree(char **pp);
char *_memset(char *s, char b, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int bfree(void **ptr);
int renumber_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int read_history(info_t *info);
int write_history(info_t *info);
char *get_history_file(info_t *info);
void fork_cmd(info_t *info);
void find_cmd(info_t *info);
int find_builtin(info_t *info);
int hsh(info_t *info, char **av);
int is_cmd(info_t *info, char *path);
char *dup_chars(char *pathstr, int start, int stop);
char *find_path(info_t *info, char *pathstr, char *cmd);
int is_chain(info_t *info, char *buf, size_t *p);
void check_chain(info_t *info, char *buf, char *p, size_t i, size_t len);
int replace_alias(info_t *info);
int replace_vars(info_t *info);
int replace_string(char **old, char *new);
int interactive(info_t *info);
int is_delim(char c, char *delim);
int _atoi(char *s);
int _isalpha(int c);
void remove_comments(char *buf);
char *converter_number(long int num, int base, int flags);
int _erratoi(char *s);
void print_error(info_t *info, char *estr);
int print_d(int input, int fd);
void _eputs(char *str);
int _eputchar(char c);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);
void clear_info(info_t *info);
void free_info(info_t *info, int all);
void set_info(info_t *info, char **av);
#endif
