#include<stdio.h>
void unique(int a[])
{
	int i,j,b[5],c=0;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(a[i]==a[j] && i!=j)
				break;
		}
		if(j==5)
		{
			b[c]=a[i];
			c++;
		}
	}
	if(c==0)
	{
		printf("\nNo unique elements");
	}
	else
	{
		printf("\nThe unique elements are :\n");
		for(i=0;i<c;i++)
		{
			printf("%d ",b[i]);
		}
	}
}