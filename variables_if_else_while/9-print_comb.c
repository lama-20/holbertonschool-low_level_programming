#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all possible combinations of single-digit numbers
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;

	for (n = 48; n <= 57; n++)
	{
		putchar(n); /* المرة الأولى */
		if (n != 57)
		{
			putchar(','); /* المرة الثانية */
			putchar(' '); /* المرة الثالثة */
		}
	}
	putchar('\n'); /* المرة الرابعة */

	return (0);
}
