#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/* The header for the linked lisr */
#define UP 0
#define DOWN 1

/**
 * enum bool - The struct list for boolean.
 * @false: the binary value 0.
 * @true: the binary value 1.
 */
typedef enum bool
{
	false = 0,
	true
} bool;

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: the structure value stored in the list
 * @prev: the value of the last element
 * @next: the value of the future element
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* the prototype for the helper*/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* the prototype used for sort */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

#endif /* SORT_H */

