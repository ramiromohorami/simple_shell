#include "main.h"
/**
 * freeptr_ptr - free the char array pointer
 * @a: array of strings
 */
void freeptr_ptr(char **a)
{
	int i;

	if (!a)
		return;

	for (i = 0; a[i]; i++)
	{
		free(a[i]), a[i] = NULL;
	}
	free(a), a = NULL;
}
/**
 * prerror - print error
 * @name: string
 * @cmd: command
 * @index: index
 */
void prerror(char *name, char *cmd, int index)
{
	char *ind, msg[] = ": not found\n";

	ind = _itoa(index);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, ind, _strlen(ind));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, msg, _strlen(msg));
	free(ind);
}

/**
 * _itoa - int to char
 * @n: number
 * Return: char
 */
char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buffer[i] = '\0';
	reverse_string(buffer, i);
	return (_strdup(buffer));
}

/**
 * reverse_string - reverse string
 * @str: string
 * @len: length
 */
void reverse_string(char *str, int len)
{
	char one;
	int i = 0;
	int j = len - 1;

	while (i < j)
	{
		one = str[i];
		str[i] = str[j];
		str[j] = one;
		i++;
		j--;

	}
}
