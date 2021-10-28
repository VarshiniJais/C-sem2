#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <stdlib.h>
#include"user_s.h"
#include"bk.h"
int log_in();
int borrow(int);
void lib_info()
{
	system("cls");
    printf("\t\tWELCOME\n\n");
    printf(" Contact number:080-2239819\n");
    printf(" Email:costomercare@lms.com\n");
    printf(" Visit us at:\n");
    printf(" 80/81,\n");
    printf(" 2nd Phase,Anugrahalayout,\n");
    printf(" Bilekahalli,\n");
    printf(" Bangalore-560076.\n");
	getch();
}
void main_menu() 
{ 
	system("cls"); 
	int op,i=1,k; 
	while(i==1) 
	{ 
		system("cls");  
		printf("MAIN MENU\n"); 
		printf("1.LOG IN\n");
		printf("2.CREATE ACCOUNT\n");  
		printf("3.INFORMATION\n");
		printf("4.EXIT\n"); 
		printf("Please enter your choice: "); 
		scanf("%d",&op); 
		switch(op) 
		{ 
			case 1: k=log_in(); 
					home(k); 
					break; 
			case 2: create(); 
					break; 
			case 3: lib_info(); 
					break; 
			case 4:exit(1); 
			default:printf("Invalid input!Try again."); 
					getch(); 
		} 
	}
}	
int check(char usna[] , char pass[]) 
{  
	FILE *f_user=fopen("users.txt","r");
	struct user u;
	if(f_user==NULL)
	{
		return -1;
	}
	int h=0;
	fseek(f_user,sizeof(u)*h ,SEEK_SET);
	while(!feof(f_user))
	{	
		fseek(f_user,sizeof(u)*h ,SEEK_SET);
		fread(&u,sizeof(u),1, f_user);
		if ((strcmp(usna,u.username)==0)&&(strcmp(pass,u.password)==0)) 
		{
			fclose(f_user);
			return h; 
		}
		h++;
	}
	fclose(f_user);
	return -1; 
} 

int log_in() 
{  
	char usna[30],pass[30]; 
	inva: 
	system("cls"); 
	printf("LOG IN\n"); 
	printf("USERNAME:" );
	scanf("%s",&usna);
	printf("\nPASSWORD:"); 
	scanf("%s",&pass);
	int i=check(usna,pass);
 	if (i>=0)
	{ 
		return i; 
	}  
	start: //label for go to 
	system("cls"); 
	int c; 
	printf("\n\t\tInvalid user name and password! \n\t\t1.Try again "); 
	printf("\n\t\t2.Create an account \n\t\t3.Main menu : "); 
	fflush(stdin);
	scanf("%d",&c); 
	switch(c) 
	{ 
		case 1:goto inva; 
		case 2:create(); 
				return 0; 
		case 3:main_menu(); 
				return 0; 
		default:printf("Option does not exist"); 
				getch(); 
				goto start; 
    } 
} 
int borrow(int k)
{ 
	struct user u;
	FILE *f_user=fopen("users.txt","r+");
	fseek(f_user,sizeof(u)*k ,SEEK_SET);
	fread(&u,sizeof(u),1, f_user);
	system("cls");
	if (u.no_borrowed>=u.no_bk) 
	{
		printf("\n More books cannot be borrowed. Please return a book to be able to borrow."); 
		fclose(f_user);
		getch(); 
		return 0; 
	} 
	int borsno; 
	printf("AVAILABLE BOOKS:\n "); 
	display_books(); 
	printf("\n Enter serial number of the book you want to borrow:"); 
	scanf("%d",&borsno); 
	int n=book_borrow(borsno);
	if (n>=0)
	{
		u.borrowed[u.no_borrowed]=borsno-1; 
		u.no_borrowed++; 
		fseek(f_user,sizeof(u)*k ,SEEK_SET);
		fwrite(&u,sizeof(struct user),1,f_user);
		fclose(f_user);
		printf("\n Book successfully borrowed."); 
		getch(); 
		return 1;  
	} 
 //Enters here only if book not available
	fclose(f_user); 
	printf("\n Book not available."); 
	getch(); 
	return 0; 
} 
int returnn(int k)
{
	struct user u;
	FILE *f_user=fopen("users.txt","r+");
	fseek(f_user,sizeof(u)*k ,SEEK_SET);
	fread(&u,sizeof(u),1, f_user);
	system("cls");
	//getch();
	if(u.no_borrowed==0)
	{
		printf("You have not borrowed any books");
		getch();
		fclose(f_user);
		return 0;
	}
	up:
	printf("Books borrowed are : \n ");
	int i;
	for(i=0;i<u.no_borrowed;i++)
	{
		display_ind(u.borrowed[i]);
	}
	printf("\n Enter serial number of the book you want to return:"); 
	fflush(stdin);
	int resno;
	scanf("%d",&resno);
	for(i=0;i<u.no_borrowed;i++)
	{
		if((resno-1)==u.borrowed[i])
		{
			break;
		}
	}
	if(i==u.no_borrowed)
	{
		printf("Invalid input. Try again");
		getch();
		system("cls");
		goto up;
		return 1;
	}
	return_book(resno-1);
	while(i<u.no_bk && i!=3)
	{
	//	printf("inside while ");
	//	printf("\t borrowed : %d \n",u.borrowed[i]);
		u.borrowed[i]=u.borrowed[i+1];
		i++;
	}
	u.borrowed[3]=-1;
	u.no_borrowed--;
	fseek(f_user,sizeof(u)*k ,SEEK_SET);
	fwrite(&u,sizeof(struct user),1,f_user);
	fclose(f_user);
	return 1;
}	
