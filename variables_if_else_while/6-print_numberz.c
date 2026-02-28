#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints numbers 0-9 using putchar and int variables only
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;

	for (n = 48; n < 58; n++)
	{
		putchar(n);
	}
	putchar('\n');

	return (0);
}
