#include "main.h"

/**
 * _env_get - get env var
 * @var: string
 * Return: env variables array
 */
char *_env_get(char *var)
{
	int count;
	char *string, *name, *val, *ok;

	for (count = 0; environ[count]; count++)
	{
		string = _strdup(environ[count]);
		name = strtok(string, "=");
		if (_strcmp(name, var) == 0)
		{
			val = strtok(NULL, "\n");
			ok = _strdup(val);
			free(string);
			return (ok);
		}
		free(string), string = NULL;
	}
	return (NULL);
}
