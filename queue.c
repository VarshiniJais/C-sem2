#include<stdio.h>
#include<stdlib.h>
#include<string.h>	
typedef struct node
{
	int priority;
	char name[20];
	struct node *link;
}node;
node *front=NULL;
void enqueue(char str[],int priority)
{
	node *tmp;
	tmp = (node *)malloc(sizeof(node));
	strcpy(tmp->name,str);
	tmp->priority = priority;
	if( front == NULL || priority<front->priority )
	{
		tmp->link = front;
		front = tmp;
	}
	else
	{
		node *pres = front;
		node *prev=NULL;
		while( pres!= NULL && pres->priority <= priority )
		{
			prev=pres;
			pres=pres->link;
		}
		tmp->link = pres;
		prev->link = tmp;
	}
}
void dequeue() 
{
	node *tmp;
	if(front == NULL)
		printf("Queue Underflow\n");
	else
	{
		tmp = front;
		printf("Dequeued item is %s\n",tmp->name);
		front = front->link;
		free(tmp);
	}
}
void display()
{
	node *ptr;
	ptr = front;
	if(front == NULL)
		printf("Queue is empty\n");
	else
	{
		printf("Queue is :\n");
		printf("Name\tPriority\n");
		while(ptr != NULL)
		{
			printf("%s\t%d\n",ptr->name,ptr->priority);
			ptr = ptr->link;
		}
	}
}