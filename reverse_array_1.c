#include <stdlib.h>
#include <stdio.h>
#define ARRAY_SZ 10

int array[ARRAY_SZ]; 

int reverse(int n)
{
	int i;
	int temp;
	for(i = 0; i < n/2; i++)
	{
		temp = array[i];
		array[i] = array[n - i - 1]; 
		array[n - i - 1] = temp;
	}
	printf("i stopped at %d\n", i);
}

void create_array()
{
	int i;
	for(i=0; i<ARRAY_SZ; i++)
	{
		array[i] = i;
	}
}

void print_array()
{	
	int i;
	for(i=0; i<ARRAY_SZ; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main()
{
	int n = ARRAY_SZ;
	int j;

	create_array();

	print_array();
	reverse(n);
	print_array();
	return 0;
}
