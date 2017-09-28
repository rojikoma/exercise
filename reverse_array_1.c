#include <stdlib.h>
#include <stdio.h>
#define ARRAY_SZ 3

int array[ARRAY_SZ]; 

int reverse(int start, int end)
{
	int temp;
	if ((end - start) >= 2)
	{
		temp = array[start];
		array[start] = array[end];
		array[end] = temp;
	}
}

void print_array()
{	
	int j;
	for(j=0; j<ARRAY_SZ; j++)
	{
		printf("%d ", array[j]);
	}
	printf("\n");
}

int main()
{
	// i = swift node, n = size of array
	int i = 1;
	int n = ARRAY_SZ;

	int j;

	for(j=0; j<ARRAY_SZ; j++)
	{
		array[j] = j;
	}
	print_array();

	printf("i=%d\n", i);	
	reverse(0, i);
	reverse(i+1, n-1);
	reverse(0, n-1);

	print_array();
	return 0;
}
