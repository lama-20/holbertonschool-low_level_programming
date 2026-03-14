#include "main.h"

int actual_prime(int n, int i);

/**
 * is_prime_number - checks if a number is prime.
 * @n: the number to check.
 *
 * Return: 1 if n is prime, 0 if not.
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (actual_prime(n, 2));
}

/**
 * actual_prime - calculates if a number is prime recursively.
 * @n: the number to check.
 * @i: iterator.
 *
 * Return: 1 if n is prime, 0 if not.
 */
int actual_prime(int n, int i)
{
	if (i == n)
		return (1);
	if (n % i == 0)
		return (0);
	return (actual_prime(n, i + 1));
}
