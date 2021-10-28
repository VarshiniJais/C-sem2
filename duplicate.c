void removeAll(char *str, const char toRemove, int index)
{
	int i;
	while(str[index]!='\0')
	{
		if(str[index]==toRemove)
		{
			i=index;
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
}
void remove_d(char *str)
{
	int i=0;
	while(str[i]!='\0')
	{
		removeAll(str,str[i],i+1);
		i++;
	}
}

