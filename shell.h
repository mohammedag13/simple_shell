#ifndef SHELL
#define SHELL

#include <limits.h>
#include <sys/errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <stddef.h>
#include <signal.h>
#include <stdlib.h>
#include <stddef.h>

#define INITIAL_BUFFER_SIZE 64
#define GROWTH_FACTOR 2


extern char **environ;

/**
 * struct DynamicString - contains dynamic strings and functions
 * @str:pointer to character
 * @len:size_t variable
 * @capacity:size_t variable
 * @append_char: a function that appends character
 * @append_string: a function that appends string
 * @free: a function that sets the string to free
 * @clear: a function that clears the memory.
 */
typedef struct DynamicString
{
	char *str;
	size_t len;
	size_t capacity;

	void (*append_char)(struct DynamicString *, char);
	void (*append_string)(struct DynamicString *, const char*);
	void (*free)(struct DynamicString *);
	void (*clear)(struct DynamicString *);
} DynamicString;

/**
 * struct memory - a struct representing a change in memory
 *
 * @command: a string representing the name of the command
 * @agv: a string pointer represents the arguments
 * @env: a string pointer represents the arguments
 * @command_number: an integer
 * @program_args: a string for arrguments
 * @program_arg_count: an integer that counts the args.
 * struct built_in - a struct representing a built_in function
 * @builtIn: a built_in struct
 * @current_process_id: represents the pid
 * @last_exit_code: represents the exit code.
 * @current_status_code: represents the exit code.
 * @current_command: the current command.
 * @command_count: the command count.
 * @commands: the command.
 */
typedef struct memory
{
	char *command;
	char *current_command;
	int command_count;
	char **agv;
	char **commands;
	int command_number;
	int current_status_code;
	char **program_args;
	char **env;
	int program_arg_count;
	struct built_in *builtIn;
	pid_t current_process_id;
	int last_exit_code;
} memory;

/**
 * struct built_in - a struct representing a built-in command
 *
 * @command: a string representing the name of the command
 * @handler: a function pointer to the handler function for the command
 */

typedef struct built_in
{
	char *command;
	void (*handler)(struct memory *m);
} built_in;


/**
 * struct ArgsHandler - a struct representing arguments handlers
 * @name: name of the argument
 * struct handler - a struct representing arguments
 * @handler: a function pointer to the handler function for the     command
 */
typedef struct ArgsHandler
{
	char *name;
	void (*handler)(struct memory *m, int i);
} ArgsHandler;



/**shell_helpers**/
/* count_of_tok - counts the number of tokens */
int count_of_tok(char *command, char *del);
/* arr_of_tokens - copies the tokens into array of strings */
char **arr_of_tokens(char *command, char *del);
/* string_array_cp - copies the array of string  */
void string_array_cp(char ***des, char **src);
/* converts int to string */
void int_to_string(int number, char *str);


/**real_string**/
/* appends the string */
void append_string(DynamicString *ds, const char *str);
/* appends the character */
void append_char(DynamicString *ds, char ch);
/* free the dynamic variable */
void free_ds(DynamicString *ds);
/* gives values to the struct */
void clear(DynamicString *ds);
/* initialize the dynamic string */
void init_dynamic_string(DynamicString *ds, char *init);



/**debugger**/
/* Prints a string */
void print_string(char *s);
/* Prints array of strings */
void print_array_of_strings(char **s);



/**string**/
/* returns a written string */
int write_charV(int fd, const char *buffer, size_t size);
/* free the array of string */
void free_array_of_strings(char **a);
/* concatinate 2 strings */
char *concatenate_string(char *s1, char *s2);



/**env**/
/* Divides the string into tokens */
char *_getenv(char *name);



/**shell2**/
/* Fork and execute the command */
int execute_commandV(memory *m);
/* Handles the built_in commands */
int handle_built_in(struct memory *m);
/* Handles args */
int handle_args(memory *m);



/**shell**/
/* Control the (ctrl+c) */
void sigintHandler(int signal);
/* check_command_exit - checks the command */
int check_command_exit(char **args);
/* check_built_ins - checks the built_in commands */
int check_built_ins(char **args);
/* the main function */
/*int main(int argc, char **argv)*/



/**string_helpers**/
/* measures the lenght of the string */
size_t _strlen(char *s);
/* copies the string from one pointer to another */
char *_strcpy(char *m, char *n);
/* compares the strings */
int _strcmp(char *s, char *x);
/* copies the string from one pointer to another */
char *_strncpy_size(char *destination, const char *source, size_t num);
/* finding the errors value */
int _atoi_with_error(char *s);


/**Memory**/
/* copies a block of memory from one place to another */
void _memcpy(void *destination, void *source, size_t number_of_bytes);
/* re-allocate the memory */
void *_memset(void *ptr, int value, size_t num);
/* fill a block of memory with a specific value */
void *_realloc(void *ptr, size_t size, size_t old_size);


/**handle_args**/
/* handle the hash for non interactive mode */
void handle_hash(struct memory *m, int i);
/* handles the double dollar sign */
void handle_double_dollar(struct memory *m, int i);
/* handles the double mark */
void handle_double_mark(struct memory *m, int i);


/**handle_build_in**/
/* handles exit command */
void handle_exit(struct memory *m);
/* handles the environments */
void handle_env(struct memory *m);


/**_getline.c**/
/* custom get_line function */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
/* copies the string into the buffer */
size_t get(char *buf, char **lineptr, size_t *n, size_t buf_s, FILE *stream);


/**multi_commands**/
/* remove the leading space */
void removeLeadingSpaces(char *str);
/* execute the multi commands */
int execute_multi_command(memory *m);

#endif

