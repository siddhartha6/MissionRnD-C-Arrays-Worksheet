/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int findLocation(int *Arr, int left, int right, int num);
int findLocation(int *Arr, int left, int right, int num)
{
	while (left<right)
	{
		int mid = (left + right) / 2;

		if (Arr[mid]<num && Arr[mid + 1]>num)
			return mid + 1;
		else if (Arr[mid]<num)
			left = mid + 1;
		else if (Arr[mid]>num && Arr[mid - 1]<num)
			return mid;
		else
			right = mid - 1;
	}

}
int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	int loc, i = 0;
	if (len <= 0|| Arr == NULL)
		return NULL;
	Arr = (int*)realloc(Arr, (len + 1)*sizeof(int));
	if (Arr[len - 1]<num){
		Arr[len] = num;
		return Arr;
	}

	loc = findLocation(Arr, 0, len, num);
	for (i = len; i >= loc; i--)
	{
		if (i == loc)
			Arr[i] = num;
		else
			Arr[i] = Arr[i - 1];
	}
	return Arr;
}
