#include<string.h>
#include<stdio.h>
void str_rev(const char s[],char rev[])
{
	int len=strlen(s);
	int l=len-1;
	int i=0;
	for(i=0;i<len;i++)
	{
		rev[i]=s[l];
		l--;
	}
	rev[len]='\0';
}
int check_palin(char *s1,char *s2)
{
	while(*s1&&*s2 &&*s1==*s2)
	{
		++s1;
		++s2;
	}
	return *s1-*s2;
}