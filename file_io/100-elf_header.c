#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * main - displays ELF header information
 * @argc: number of arguments
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd, i;
	unsigned char e_ident[EI_NIDENT];
	Elf64_Ehdr header;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1 || read(fd, &header, sizeof(header)) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cannot read file\n");
		exit(98);
	}

	for (i = 0; i < EI_NIDENT; i++)
		e_ident[i] = header.e_ident[i];

	if (e_ident[EI_MAG0] != ELFMAG0 ||
		e_ident[EI_MAG1] != ELFMAG1 ||
		e_ident[EI_MAG2] != ELFMAG2 ||
		e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		close(fd);
		exit(98);
	}

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%s", e_ident[i], i == EI_NIDENT - 1 ? "\n" : " ");

	printf("  Class:                             %s\n",
		e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" :
		e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "none");

	printf("  Data:                              %s\n",
		e_ident[EI_DATA] == ELFDATA2LSB ?
		"2's complement, little endian" :
		e_ident[EI_DATA] == ELFDATA2MSB ?
		"2's complement, big endian" : "none");

	printf("  Version:                           %d (current)\n",
		e_ident[EI_VERSION]);

	printf("  OS/ABI:                            %s\n",
		e_ident[EI_OSABI] == ELFOSABI_SYSV ?
		"UNIX - System V" : "<unknown>");

	printf("  ABI Version:                       %d\n",
		e_ident[EI_ABIVERSION]);

	printf("  Type:                              %x\n", header.e_type);
	printf("  Entry point address:               %#lx\n",
		(unsigned long)header.e_entry);

	close(fd);
	return (0);
}
