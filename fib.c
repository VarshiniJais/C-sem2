#include<stdio.h>
void fib(int n,int a[])
{
    int i,temp,t1 = 0, t2 = 1;
    a[0]=t1;
    for (i = 2; i <= n; ++i) 
    {
       a[i-1]=t2;
       temp=t1;
       t1=t2;
       t2= temp+t2;
    }
}
