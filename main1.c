#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork & wait & execve example
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t child_pid;
    int status;
    size_t len = 256;
    int i;
    char *ch;
    char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	ch = malloc(len + 1);
    	printf("This is the prompt ($) ");
	while((i = getline(&ch, &len, stdin)) != EOF)
	{
		child_pid = fork(); //creation of the child process
    		if (child_pid == -1) //error
    		{
        		perror("Error");
        		return (1);
    		}
    		if (child_pid == 0) //success
    		{
			if (access(ch, X_OK))
			{
				if (execve(argv[0], argv, NULL) == -1)
				{
					perror("Error:");
					return(-1);
				}
    			}
		}
    		else //make the parent wait for the child
    		{
        		wait(&status);
			printf("This is the prompt ($) ");
    		}
	}
    return (0);
}
