#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints the alphabet in lowercase and then in uppercase
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char letter;

	/* الحلقة الأولى للحروف الصغيرة */
	for (letter = 'a'; letter <= 'z'; letter++)
	{
		putchar(letter);
	}

	/* الحلقة الثانية للحروف الكبيرة */
	for (letter = 'A'; letter <= 'Z'; letter++)
	{
		putchar(letter);
	}

	/* المرة الثالثة لطباعة السطر الجديد */
	putchar('\n');

	return (0);
}
