#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - the array swapper of struct.
 * @a: first integer value to swap.
 * @b: The other integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - function to swap array using algorith
 *                    the lomuto partition scheme.
 * @array: an array of the integer value.
 * @size: The memory allocated to the array.
 * @left: the begining location of the array.
 * @right: the last position of the array.
 *
 * Return: give the end partion location.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - the function to sort using lomuto algorith.
 * @array: the input array.
 * @size: memory allocated to array.
 * @left: the beginig poition of array.
 * @right: the end locatio of the array.
 *
 * Description: lomuto sort algorith.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - the function to sort in ascending
 *              order with quick sort algorith.
 * @array: the value of the array.
 * @size: memory allocated to array.
 *
 * Description: swap and print the value. 
 *              
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
