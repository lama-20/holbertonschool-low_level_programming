#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * hash_table_set - adds an element to the hash table
 * @ht: hash table
 * @key: key
 * @value: value associated with key
 *
 * Return: 1 if success, 0 otherwise
 */

int hash_table_set(hash_table_t *ht, const char *key,
	const char *value)
{
	unsigned long int index;
	hash_node_t *node, *temp;
	char *dup_value;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	temp = ht->array[index];

	while (temp)
	{
		if (strcmp(temp->key, key) == 0)
		{
			dup_value = strdup(value);
			if (dup_value == NULL)
				return (0);

			free(temp->value);
			temp->value = dup_value;

			return (1);
		}

		temp = temp->next;
	}

	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (0);

	node->key = strdup(key);
	node->value = strdup(value);

	if (node->key == NULL || node->value == NULL)
	{
		free(node->key);
		free(node->value);
		free(node);

		return (0);
	}

	node->next = ht->array[index];
	ht->array[index] = node;

	return (1);
}
