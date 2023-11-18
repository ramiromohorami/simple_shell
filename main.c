#include "main.h"

/**
 * main - main function
 * @arg_cnt: count of arguments
 * @arg_val: values of arguments
 * Return: 0 if it is ok,1 if something wrong
*/

int main(int arg_cnt, char **arg_val)
{
	char *string = NULL;
	char **executable = NULL;
	int code = 0, k;
	(void) arg_cnt;

	while (1)
	{
		string = line_reader();
		if (string == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (code);
		}
		k++;
		executable = sep_strings(string);
		if (!executable)
			continue;
		code = _execute(executable, arg_val, k);
	}

	return (0);
}
