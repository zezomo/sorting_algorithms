#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending order using Bubble sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t m;

	if (size <= 1)
		return;

	m = size / 2;

	merge_sort(array, m);
	merge_sort(array + m, size - m);
	merge(array, 0, m, size - 1);
}
/**
 * merge - Sorts an array of integers in ascending order using Bubble sort
 * @l: The array to be sorted
 * @m: The size of the array
 * @r: The size of the array
 */
void merge(int *array, size_t l, size_t m, size_t r)
{
	size_t n1 = m - l + 1;
	size_t n2 = r - m;

	int *left = (int *)malloc(n1 * sizeof(int));
	int *right = (int *)malloc(n2 * sizeof(int));

	size_t i = 0, j = 0, k = l;

	for (i = 0; i < n1; i++)
		left[i] = array[l + i];
	for (j = 0; j < n2; j++)
		right[j] = array[m + 1 + j];

	i = 0, j = 0, k = l;
	
	while (i < n1 && j < n2)
	{
		if (left[i] <= right[j])
		{
			array[k++] = left[i++];
		}
		else
		{
			array[k++] = right[j++];
		}
	}

	while (i < n1)
		array[k++] = left[i++];
	while (j < n2)
		array[k++] = right[j++];

	free(left);
	free(right);
}

