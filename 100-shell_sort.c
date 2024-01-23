#include "sort.h"


/**
 * swap_ints - Swap two integers in an array.
 * @x: The first integer to swap.
 * @y: The second integer to swap.
 */
void swap_ints(int *x, int *y)
{
	int tmp;


	tmp = *x;
	*x = *y;
	*y = tmp;
}


/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, f, g;


	if (array == NULL || size < 2)
	return;


	for (gap = 1; gap < (size / 3);)
	gap = gap * 3 + 1;


	for (; gap >= 1; gap /= 3)
	{
	for (f = gap; f < size; f++)
	{
		g = f;
	while (g >= gap && array[g - gap] > array[g])
		{
		swap_ints(array + g, array + (g - gap));
		g -= gap;
		}
	}
	print_array(array, size);
	}
}

