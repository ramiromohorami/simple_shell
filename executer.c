#include "main.h"
/**
 * _executer - executes cmd
 * @cmd: command to be run
 * @argv: list of args
 * Return: status code
 */
int _execute(char **cmd, char **argv)
{
	pid_t child;
	int stat;
	
	child = fork();
	if (child == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			perror(argv[0]);
			freeptr_ptr(cmd);
		}
	}
	else
	{
		waitpid(child, &stat, 0);
		freeptr_ptr(cmd);
	}
	return (WEXITSTATUS(stat));
}
