#include "sort.h"

/**
 * swap - Swaps two elements in an array
 * @a: First element
 * @b: Second element
 */
void swap(int *a, int *b)
{
	int temp = *a;


	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Partitions the array using the Lomuto partition scheme
 * @array: The array to partition
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 * 
 * Return: The index of the pivot after partitioning
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_recursive - Recursively sorts the array using quicksort algorithm
 * @array: The array to sort
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pi = 0;

	if (low < high)
	{
		pi = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, pi - 1, size);
		quick_sort_recursive(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using the Quick
 *              sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	quick_sort_recursive(array, 0, size - 1, size);
}
