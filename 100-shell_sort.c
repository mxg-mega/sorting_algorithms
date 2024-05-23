#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using
 *              the Shell sort algorithm and the Knuth sequence.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (array == NULL || size < 2)
	{
		return;
	}

	/* Initialize gap using Knuth sequence */
	gap = 1;
	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}

	/* Perform the shell sort using the gap sequence */
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		/* Print the array after each gap reduction */
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
