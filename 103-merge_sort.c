#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending orde
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
 * merge_arrays - Merges two sorted arrays into one sorted
 * @array: Pointer to the resulting array
 * @l: Pointer to the left array
 * @left_s: Size of the left array
 * @r: Pointer to the right array
 * @right_s: Size of the right array
 */
void merge_arrays(int *array, int *l, size_t left_s, int *r, size_t right_s)
{
	size_t i = 0, j = 0, k = 0;
	int *temp_array = malloc((left_s + right_s) * sizeof(int));

	while (i < left_s && j < right_s)
	{
		if (l[i] <= r[j])
			temp_array[k++] = l[i++];
		else
			temp_array[k++] = r[j++];
	}

	while (i < left_s)
		temp_array[k++] = l[i++];

	while (j < right_s)
		temp_array[k++] = r[j++];

	for (i = 0; i < left_s + right_s; i++)
		array[i] = temp_array[i];

	free(temp_array);
}

