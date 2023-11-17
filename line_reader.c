#include "main.h"

/**
 * line_reader - reads line from stdin
 * Return: string if true otherwise NULL if does not read or reaching EOF
 */

char *line_reader(void)
{
	char *string = NULL;
	int nmbr_of_chars;
	size_t l = 0;
	if(isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, "$ ", 2);
	nmbr_of_chars = getline(&string, &l, stdin);
	if (nmbr_of_chars == -1)
	{
		free(string);
		return (NULL);
	}

	return (string);
}
