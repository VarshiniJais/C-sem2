#include<stdio.h>
void read(int a[],int n)
{
	int i;
	printf("Enter the values :\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}

void rev(int *p,int n)
{
	int i;
	printf("Array elements:\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",*p++);
	}
	printf("\nReversed array:\n");
	for(i=n-1;i>=0;i--)
	{
		printf("%d ",*--p);
	}
}