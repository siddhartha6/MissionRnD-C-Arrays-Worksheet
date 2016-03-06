/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

Ex 2: [4,4,2,2,1,5] output : [4,2,1,5]

INPUTS: Integer array and length of the array .

OUTPUT: Update input array by removing duplicate values and return the final array length

ERROR CASES: Return -1 for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>
void quicksort(int *Arr, int first, int last);

void quicksort(int *Arr, int first, int last){
	int pivot=0, j=0, temp=0, i=0;

	if (first<last){
		pivot = first;
		i = first;
		j = last;

		while (i<j){
			while (Arr[i] <= Arr[pivot] && i<last)
				i++;
			while (Arr[j]>Arr[pivot])
				j--;
			if (i<j){
				temp = Arr[i];
				Arr[i] = Arr[j];
				Arr[j] = temp;
			}
		}

		temp = Arr[pivot];
		Arr[pivot] = Arr[j];
		Arr[j] = temp;
		quicksort(Arr, first, j - 1);
		quicksort(Arr, j + 1, last);

	}
}
int removeArrayDuplicates(int *Arr, int len)
{
	if (Arr == NULL || len < 0)
		return -1;
	quicksort(Arr, 0, len-1);

	int res = 1, i = 0, len1 = len;
	for (i = 1; i<len; i++)
	{
		if (Arr[i] != Arr[i - 1])
		{
			Arr[res] = Arr[i];
			res++;
		}
		else
			len1 = len1 - 1;
	}
	return len1;
}
