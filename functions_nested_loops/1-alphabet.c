#include "main.h"

/**
 * print_alphabet - Prints the lowercase alphabet
 *
 * Description: Uses a loop to print a-z followed by a newline
 *
 * Return: void
 */
void print_alphabet(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
	{
		_putchar(letter);
	}
	_putchar('\n');
}
