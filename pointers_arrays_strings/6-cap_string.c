#include "main.h"

/**
 * cap_string - capitalizes all words of a string.
 * @s: string to be modified.
 *
 * Return: pointer to the modified string.
 */
char *cap_string(char *s)
{
	int i = 0, j;
	char sep[] = " \t\n,;.!?\"(){}";

	while (s[i] != '\0')
	{
		/* Check if the first character of the string is lowercase */
		if (i == 0 && (s[i] >= 'a' && s[i] <= 'z'))
		{
			s[i] = s[i] - 32;
		}

		/* Check if the character is a separator */
		for (j = 0; sep[j] != '\0'; j++)
		{
			if (s[i] == sep[j])
			{
				/* If next character is lowercase, capitalize it */
				if (s[i + 1] >= 'a' && s[i + 1] <= 'z')
				{
					s[i + 1] = s[i + 1] - 32;
				}
			}
		}
		i++;
	}

	return (s);
}
