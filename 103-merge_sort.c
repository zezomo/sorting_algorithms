#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending order using
 *              the Merge sort algorithm.
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (size > 1)
	{
		size_t mid = size / 2;
		int *left = array;
		int *right = array + mid;
		size_t left_size = mid;
		size_t right_size = size - mid;

		printf("Merging...\n");
		printf("[left]: ");
		print_array(left, left_size);
		printf("[right]: ");
		print_array(right, right_size);

		merge_sort(left, left_size);
		merge_sort(right, right_size);

		merge_arrays(array, left, left_size, right, right_size);

		printf("[Done]: ");
		print_array(array, size);
	}
}

/**
 * merge_arrays - Merges two sorted arrays into one sorted array
 * @array: Pointer to the resulting array
 * @left: Pointer to the left array
 * @left_size: Size of the left array
 * @right: Pointer to the right array
 * @right_size: Size of the right array
 */
void merge_arrays(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;
	int *temp_array = malloc((left_size + right_size) * sizeof(int));

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			temp_array[k++] = left[i++];
		else
			temp_array[k++] = right[j++];
	}

	while (i < left_size)
		temp_array[k++] = left[i++];

	while (j < right_size)
		temp_array[k++] = right[j++];

	for (i = 0; i < left_size + right_size; i++)
		array[i] = temp_array[i];

	free(temp_array);
}

