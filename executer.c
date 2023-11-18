#include "main.h"
/**
 * _execute - executes cmd
 * @cmd: command to be run
 * @argv: list of args
 * @k: nmbr
 * Return: status code
 */
int _execute(char **cmd, char **argv, int k)
{
	pid_t child;
	int stat;
	char *string;

	string = _path(cmd[0]);
	if (!string)
	{
		prerror(argv[0], cmd[0], k);
		freeptr_ptr(cmd);
		return (127);
	}
	child = fork();
	if (child == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			free(string), string = NULL;
			freeptr_ptr(cmd);
		}
	}
	else
	{
		waitpid(child, &stat, 0);
		freeptr_ptr(cmd);
		free(string), string = NULL;
	}
	return (WEXITSTATUS(stat));
}
