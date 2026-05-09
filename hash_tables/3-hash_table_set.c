#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * update_value - updates value of existing key
 * @node: node to update
 * @value: new value
 *
 * Return: 1 if success, 0 otherwise
 */

int update_value(hash_node_t *node, const char *value)
{
	char *dup_value;

	dup_value = strdup(value);

	if (dup_value == NULL)
		return (0);

	free(node->value);
	node->value = dup_value;

	return (1);
}

/**
 * create_node - creates a new node
 * @key: key
 * @value: value
 *
 * Return: pointer to new node
 */

hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *node;

	node = malloc(sizeof(hash_node_t));

	if (node == NULL)
		return (NULL);

	node->key = strdup(key);
	node->value = strdup(value);

	if (node->key == NULL || node->value == NULL)
	{
		free(node->key);
		free(node->value);
		free(node);

		return (NULL);
	}

	return (node);
}

/**
 * hash_table_set - adds element to hash table
 * @ht: hash table
 * @key: key
 * @value: value
 *
 * Return: 1 if success, 0 otherwise
 */

int hash_table_set(hash_table_t *ht, const char *key,
	const char *value)
{
	unsigned long int index;
	hash_node_t *node, *temp;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	temp = ht->array[index];

	while (temp)
	{
		if (strcmp(temp->key, key) == 0)
			return (update_value(temp, value));

		temp = temp->next;
	}

	node = create_node(key, value);

	if (node == NULL)
		return (0);

	node->next = ht->array[index];
	ht->array[index] = node;

	return (1);
}
