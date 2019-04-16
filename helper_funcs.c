#include "shell.h"

/**
 * sigint_handler - doesn't exit in case of Ctrl-C
 * @sig: required for signal cmd to run properly
 *	print newline;
 *	print the prompt;
 *	wipe input stream(?);
 */
void sigint_handler(int sig)
{
	(void)sig;
	 _putchar('\n');
	 print_prompt();
	 fflush(stdout);
}

/**
 * free_everything - frees arrays of strings
 * @args: array of strings to free
 */
void free_everything(char **args)
{
	int i;

	if (!args)
		return;

	for (i = 0; args[i]; i++)
		free(args[i]);

	free(args);
}
