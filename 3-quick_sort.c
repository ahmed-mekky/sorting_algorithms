#include "sort.h"

/**
  * quick_sort - quicksort algorithm
  *
  * @array: array to be sorted
  * @size: size of the array
  *
  * Return: nothing
  */
void quick_sort(int *array, size_t size)
{
	int pivot;

	if (array == NULL || size <= 1)
		return;
	sort_fun(array, 0, size - 1, size);
}

/**
  * sort_fun - recursive sorting algorithm
  *
  * @array: array to be sorted
  * @left: the first index on the left
  * @right: the first index on the right
  * @size: full array size
  *
  * Return: Nothing
  */
void sort_fun(int *array, int left, int right, size_t size)
{
	int pivot;

	if (left < right)
	{
		pivot = split(array, left, right, size);
		sort_fun(array, left, pivot - 1, size);
		sort_fun(array, pivot + 1, right, size);
	}
}

/**
  * split - split array
  *
  * @array: array
  * @left: the first index on the left
  * @right: the first index on the right
  * @size: full array size
  *
  * Return: pivot index
  */
int split(int *array, int left, int right, size_t size)
{
	int i, j, pivot, tmp;

	pivot = array[right];
	i = left;

	for (j = left; j < right; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				tmp = array[j];
				array[j] = array[i];
				array[i] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] != array[right])
	{
		tmp = array[i];
		array[i] = array[right];
		array[right] = tmp;
		print_array(array, size);
	}

	return (i);
}
