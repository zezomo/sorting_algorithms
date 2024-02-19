#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - Recursive helper function for Quick sort
 * @array: The array to be sorted
 * @low: The low index of the partition to be sorted
 * @high: The high index of the partition to be sorted
 * @size: The size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int partition;

	if (low < high)
	{
		partition = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, partition - 1, size);
		quick_sort_recursive(array, partition + 1, high, size);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort
 * @array: The array to be sorted
 * @low: The low index of the partition to be sorted
 * @high: The high index of the partition to be sorted
 * @size: The size of the array
 *
 * Return: The final pivot position
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	print_array(array, size);
	return (i + 1);
}

