#include "main.h"

/**
 * sep_strings - seperate strings to string array using separator
 * @phrase: string to be sliced
 * Return: array of strings
 */

char **sep_strings(char *phrase)
{
	char *word = NULL, *phrase_copy = NULL;
	char **cmd = NULL;
	int counter = 0;
	int index = 0;

	if (!phrase)
		return (NULL);
	phrase_copy = _strdup(phrase);
	word = strtok(phrase_copy, " \t\n");
	if (word == NULL)
	{
		free(phrase_copy), phrase_copy = NULL;
		free(phrase), phrase = NULL;
		return (NULL);
	}
	while (word)
	{
		counter++;
		word = strtok(NULL, " \t\n");
	}
	free(phrase_copy), phrase_copy = NULL;
	cmd = malloc(sizeof(char *) * (counter + 1));
	if (!cmd)
	{
		free(phrase), phrase = NULL;
		return (NULL);
	}
	word = strtok(phrase, " \t\n");
	while (word)
	{
		cmd[index] = _strdup(word);
		word = strtok(NULL, " \t\n");
		index++;
	}
	cmd[index] = NULL;
	free(phrase), phrase = NULL;
	return (cmd);
}
