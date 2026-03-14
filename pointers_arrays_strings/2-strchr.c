#include "main.h"
#include <stddef.h>

/**
 * _strchr - locates a character in a string.
 * @s: the string to be searched.
 * @c: the character to locate.
 *
 * Return: a pointer to the first occurrence of c,
 * or NULL if the character is not found.
 */
char *_strchr(char *s, char c)
{
	while (*s >= '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		if (*s == '\0')
		{
			return (NULL);
		}
		s++;
	}
	return (NULL);
}
