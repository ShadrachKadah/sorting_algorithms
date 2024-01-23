#include "sort.h"


/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, x;


	for (max = array[0], x = 1; x < size; x++)
	{
	if (array[x] > max)
	max = array[x];
	}


	return (max);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, y;


	if (array == NULL || size < 2)
	return;


	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
	return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
	free(sorted);
	return;
	}


	for (y = 0; y < (max + 1); y++)
	count[y] = 0;
	for (y = 0; y < (int)size; y++)
	count[array[y]] += 1;
	for (y = 0; y < (max + 1); y++)
	count[y] += count[y - 1];
	print_array(count, max + 1);


	for (y = 0; y < (int)size; y++)
	{
	sorted[count[array[y]] - 1] = array[y];
	count[array[y]] -= 1;
	}


	for (y = 0; y < (int)size; y++)
	array[y] = sorted[y];


	free(sorted);
	free(count);
}

