#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * close_file - closes file descriptor
 * @fd: file descriptor
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * copy_file - copies content from one fd to another
 * @from: source file descriptor
 * @to: destination file descriptor
 * @file_from: source file name
 * @file_to: destination file name
 */
void copy_file(int from, int to, char *file_from, char *file_to)
{
	ssize_t r, w;
	char buffer[1024];

	r = read(from, buffer, 1024);
	while (r > 0)
	{
		w = write(to, buffer, r);
		if (w == -1 || w != r)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			exit(99);
		}
		r = read(from, buffer, 1024);
	}

	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}
}

/**
 * main - copies content of one file to another
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int from, to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	from = open(argv[1], O_RDONLY);
	if (from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	copy_file(from, to, argv[1], argv[2]);
	close_file(from);
	close_file(to);

	return (0);
}
