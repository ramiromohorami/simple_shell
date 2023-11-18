#include "main.h"
/**
 * _path - give path
 * @cmd: command entered
 * Return: NULL
 */
char *_path(char *cmd)
{
	char *path, *string, *link;
	struct stat t;
	int i;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &t) == 0)
				return (_strdup(cmd));
			return (NULL);
		}
	}
	path = _env_get("PATH");
	if (!path)
		return (NULL);
	link = strtok(path, ":");
	while (link)
	{
		string = malloc(_strlen(link) + _strlen(cmd) + 2);
		if (string)
		{
		_strcopy(string, link);
		_strcat(string, "/");
		_strcat(string, cmd);
			if (stat(string, &t) == 0)
			{
				free(path);
				return (string);
			}
			free(string), string = NULL;

			link = strtok(NULL, ":");
		}
	}
	free(path);
	return (NULL);
}
