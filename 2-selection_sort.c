#include "sort.h"
/**
  * selection_sort - selection sort algorithm
  *
  * @array: array to be sorted
  * @size: size of the array
  *
  * Return: nothing
  */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int x, tmp, y;

	for (i = 0; i < size; i++)
	{
		x = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (x > array[j])
			{
				x = array[j];
				y = j;
			}
		}
		if (x != array[i])
		{
			tmp = array[i];
			array[i] = x;
			array[y] = tmp;
			print_array(array, size);
		}
	}
}
