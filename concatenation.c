#include<stdio.h>
#include<string.h>
void cocant(char d[], const char s[])
{
	int n=strlen(d);
	int i;
	for(i=0;i<strlen(s);i++)
	{
		d[n]=s[i];
		n++;
	}
	d[n]='\0';
}

char* my_concat(char d1[],const char s1[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		cocant(d1,s1);
	}
	return d1;
}