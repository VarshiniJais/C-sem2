#include<stdio.h>
void read(int b[],int n)
{
	int i;
	printf("Enter the values :\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
}

int maxi(int b[],int len)
{
	 int i,m=b[0];
	 for(i=1;i<len;i++)
	 {
		 if(m<b[i])
			 m=b[i];
	 }
	 return m;
}

int mini(int b[],int len)
{
	 int i,m=b[0];
	 for(i=1;i<len;i++)
	 {
		 if(m>b[i])
			 m=b[i];
	 }
	 return m;
}
