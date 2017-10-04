#include <stdlib.h>
#include <stdio.h>
#define ARRAY_SZ 20

int array[ARRAY_SZ]; 

int reverse(int m, int n)
{
	int i;
	int temp;
	for(i=m; i<(m+n)/2+1; i++)
	{
		temp = array[i];
		array[i] = array[m+n-i]; 
		array[m+n-i] = temp;
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
	int i = 5;

	create_array();

	print_array();

	reverse(0, i-1);//because the split is in-between
	print_array();
	reverse(i, n-1);
	print_array();
	reverse(0, n-1);

	print_array();
	return 0;
}
