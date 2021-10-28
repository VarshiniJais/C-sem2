#include<stdio.h>
int count_ch(char *str, const char ch, int index)
{
	int i,c=1;
	while(str[index]!='\0')
	{
		if(str[index]==ch)
		{
			i=index;
			c++;
			while(str[i]!='\0')
			{
				str[i]=str[i+1];
				i++;
			}
		}
		else
		{
			index++;
		}
	}
	return c;
}
void occur(char s[])
{
	int i=0;
	while(s[i]!='\0')
	{
		printf("\nNumber of Occurrence of '%c' :%d ",s[i],count_ch(s,s[i],i+1));
		i++;
	}
}