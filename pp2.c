#include<stdio.h>
#include<string.h>
int strend(char s[],char t[])
{
	int k=0,i;
	char c[500];
	int len1=strlen(s);
	int len2=strlen(t); 
	for(i=len1-(len2);i<=len1;i++) 
	{
		c[k]=s[i]; 
		k++;
	}
	c[k]='\0'; 
	if(strcmp(t,c)==0) 
		return 1; 
	else 
		return 0; 
}