#include<stdio.h>
int fact(int n)
{
	float f;
	if(n==0)
		return 1;
	else
		return n*fact(n-1);
}