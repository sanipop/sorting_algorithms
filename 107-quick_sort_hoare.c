#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - strsuct to sewap integer.
 * @a: one of the value to swap.
 * @b: the other value to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - fxn to sort the subset
 *                    hoare partition algorithm .
 * @array: input of the array.
 * @size: memory allocated to the array.
 * @left: The beging position of the struct.
 * @right: Tail position of the struct.
 *
 * Return: the end partion of the sort.
 *
 * Description: release the partion sort.
 * Poutput the value after sort.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - using the algorith to sort.
 * @array: input to be sorted.
 * @size: memory allocated to the sorted.
 * @left: begining position of the partion.
 * @right: Tail position of the partition.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - from the lowest usse the quick
 *                    quicksort algorith.
 * @array: the input array.
 * @size: memory allocated to array.
 *
 * Description: Uses hte given algorithm. 
 * print hte value of the sort.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}

