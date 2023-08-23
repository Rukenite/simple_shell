#include "main.h"

/**
 * _strdup - duplicates str (safe)
 *
 * @str: string to duplicate
 * Return: duplicated string
 */
char *_strdup(char *str)
{
	int len = strlen(str), i = 0;
	char *buf;

	buf = malloc(len + 1);
	while (i <= len)
	{
		buf[i] = '\0';
		i++;
	}
	for (i = 0; str[i] != '\0'; i++)
		buf[i] = str[i];

	return (buf);
}
