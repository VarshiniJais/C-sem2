#include<stdio.h>
void ch_replace(char *s,char c, char r)
{
	int i=0;
	for(i=0;s[i];i++)
	{
		if (s[i]==c)
			s[i]=r;
	}
}