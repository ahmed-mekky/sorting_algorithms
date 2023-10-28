#include "sort.h"


/**
 * bubble_sort - sorting array using bubble sort
 *
 * @array: array of int(s) to sort
 * @size: size to be sorted
 *
 * Return: Always 0
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, size_x = size;
	int tmp, flag = 0;

	if (array == NULL || size < 2)
		return;
	for (i = 1; i < size; i++)
	{
		for (j = 1; j < size_x; j++)
		{
			if (array[j - 1] > array[j])
			{
				tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
				print_array(array, size);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
		flag = 0;
		size_x--;
	}
}
