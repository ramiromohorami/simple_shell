#include "main.h"
/**
 * _strcmp - compare two strings
 * @string1: first string
 * @string2: second string
 * Return: nmbr of difference if there are
 */
int _strcmp(char *string1, char *string2)
{
	int difference;

	difference = (int)*string1 - (int)*string2;
	while (*string1)
	{
		if (*string1 != *string2)
			break;
		string1++;
		string2++;
		difference = (int)*string1 - (int)*string2;
	}

	return (difference);
}
/**
 * _strlen - returns length of string
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
	int length = 0;

	while ((*s)++)
		length++;
	return (length);
}
/**
 * _strdup - dupilcate string
 * @str: string
 * Return: pointer of the string
 */
char *_strdup(const char *str)
{
	char *pointer;
	int i, length = 0;

	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		length++;
		str++;
	}
	str = str - length;
	pointer = malloc(sizeof(char) * (length + 1));
	if (pointer == NULL)
		return (NULL);
	for (i = 0; i <= length; i++)
		pointer[i] = str[i];
	return (pointer);
}
/**
 * _strcat - concatunate strings
 * @dest: destination string
 * @src: source string
 * Return: destination
 */
char *_strcat(char *dest, char *src)
{
	char *pointer = dest;

	while (*pointer)
		pointer++;
	while (*src)
	{
		*pointer = *src;
		pointer++;
		src++;
	}
	*pointer = *src;
	return (dest);
}
/**
 * _strcopy - compare two strings
 * @dest: destination
 * @src: source
 * Return: destination
 */
char *_strcopy(char *dest, char *src)
{	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
