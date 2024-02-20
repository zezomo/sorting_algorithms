#include "sort.h"

/**
 * lomuto_partition - Partitions the array using the Lomuto partition scheme
 * @array: The array to be partitioned
 * @low: The low index of the partition
 * @high: The high index of the partition
 * @size: The size of the array
 *
 * Return: The pivot index
 */
size_t lomuto_partition(int *array, ssize_t low, ssize_t high, int size)
{
        int pivot, temp;
        ssize_t i, j;

        pivot = i;
        i = low, j = high;


        while(true)
        {
                while(array[pivot] <= array[j] && pivot != j)
                        j--;
                if(pivot == j)
                        break;
                else if(array[pivot] > array[j])
                {
                        temp = array[j];
                        array[j] = array[pivot];
                        array[pivot] = temp;
                print_array(array, size);
                        pivot = j;
                }
                while(array[pivot] >= array[i] && pivot != i)
                        i++;
                if(pivot == i)
                        break;
                else if(array[pivot] < array[i]){
                temp = array[i];
                array[i] = array[pivot];
                array[pivot] = temp;
                pivot = i;
                print_array(array, size);
                }
 
               }
        return (pivot);
}

/**
 * quicksort - Recursive function to sort the array using Quick sort
 * @array: The array to be sorted
 * @low: The low index of the partition
 * @high: The high index of the partition
 * @size: The size of the array
 */
void quicksort(int *array, ssize_t low, ssize_t high, size_t size)
{
        size_t pivot;

        if (low < high)
        {
                pivot = lomuto_partition(array, low, high, size);
                quicksort(array, low, pivot - 1, size);
                quicksort(array, pivot + 1, high, size);
         }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Q
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
        if (array == NULL || size <= 1)
                return;
        quicksort(array, 0, size - 1, size);
}
