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
