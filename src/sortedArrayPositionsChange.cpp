/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{

	if (Arr == NULL || len < 0)
		return NULL;
	int i = 0, j = len, loc1 = 0, loc2 = 0, m = 0, n = 0;
	if (Arr[0]>Arr[len - 1]){
		loc1 = len - 1;
		loc2 = 0;
		m = 1;
		n = 1;
	}
	if (Arr[1]<Arr[0]){
		loc1 = 0;
		m = 1;
	}
	if (Arr[len - 1]<Arr[len - 2]){
		loc2 = len - 1;
		n = 1;
	}

	if (n != 1 || m != 1){
		for (i = 0, j = len - 1; i != j, i<j; i++, j--)
		{

			if (Arr[i + 1]>Arr[i])
				loc1 = i + 1;
			if (Arr[j] >Arr[j - 1])
				loc2 = j - 1;
		}
	}
	i = Arr[loc1];
	Arr[loc1] = Arr[loc2];
	Arr[loc2] = i;
}