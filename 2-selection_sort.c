#include "sort.h"

/**
 * swap_ints - Sthe struct to swap int in array.
 * @a: one of the value.
 * @b: The other value to excahnge.
 */
void swap_ints(int *a, int *b)
{
	int swp;

	swp = *a;
	*a = *b;
	*b = swp;
}

/**
 * selection_sort - the function to sort the array from the low
 *                  the algorith select sort.
 * @array: the value of the arrays.
 * @size: The assign memory of array.
 *
 * Description: output each of the interchanged val.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}
