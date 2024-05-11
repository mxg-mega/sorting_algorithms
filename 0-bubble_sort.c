#include "sort.h"

/**
  * bubble_sort - sorts an array of integers
  * in ascending order using the Bubble sort algorithm
  * @array: the Array to Sort
  * @size: size of the array
  *
  * Return:
  */
void bubble_sort(int *array, size_t size)
{
	unsigned int i = 0, j = 0;

	if (array == NULL || size == 0)
	{
		return;
	}
	for (i = 0; i < (size - 1); i++)
	{
		for (j = 0; j < (size - i - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				int swap = 0;

				swap = array[j];
				array[j] = array[j + 1];
				array[j + 1] = swap;
				print_array(array, size);
			}
		}
	}
}
