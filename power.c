#include<stdio.h>
float power(int a,int n)
{
	if(n==0)
		return 1;
	else
		return a*power(a,n-1);
}
