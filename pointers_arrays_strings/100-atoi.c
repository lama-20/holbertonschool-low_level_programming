#include "main.h"

/**
 * _atoi - converts a string to an integer.
 * @s: the string to be converted.
 *
 * Return: the integer value of the string.
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	unsigned int res = 0;
	int found = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			sign *= -1;
		}

		if (s[i] >= '0' && s[i] <= '9')
		{
			found = 1;
			res = (res * 10) + (s[i] - '0');
		}
		else if (found)
		{
			break;
		}
		i++;
	}

	if (found == 0)
		return (0);

	return (res * sign);
}
