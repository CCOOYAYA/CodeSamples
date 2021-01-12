#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
typedef struct{
	char name[20];
	float score;
}STD;//the data of a student contains his name and score
typedef struct{
	STD *data;
	int length;
	int listsize;
}sqlist;//This is used to storage all the student's data
int menu();
int initsqlist(sqlist *L,int max);
int insertsqlist(sqlist *L,int i,STD x);
int deletesqlist(sqlist *L,int i,STD *x);
int locatesqlist(sqlist L,STD x);
int dispsqlist(sqlist L);
int updatesqlist(sqlist *L,int i,STD x);
int lengthsqlist(sqlist L);
int ranksqlist(sqlist *L);
int main()//these are all the functions used in this program
{
	int n,i,t=1,maxsize;
	STD s;
	sqlist L;
	while(t)
	{
		n=menu();
		switch(n)//switch statement is used to select the instruction
		{
		case 1:
			printf("Please enter the number of student data to be created£º");
			scanf("%d",&maxsize);
			initsqlist(&L,maxsize);
			printf("Initialization completed, press any key to continue\n");
			getch();
			break;
		case 2:
			printf("Please enter the name and grade of the students to be inserted, separated by spaces\n");
			scanf("%s%f",s.name,&s.score);
			printf("Please enter the position you want to insert(1-%d):",lengthsqlist(L));
			scanf("%d",&i);
			insertsqlist(&L,i,s);
			printf("Insert completed, press any key to continue\n");
			getch();
			break;
		case 3:
			printf("Please enter the name of the student to be deleted:");
			scanf("%s",s.name);
			n=locatesqlist(L,s);
			if(n==L.length+1)
				printf("There is no such data");
			else
			{
				deletesqlist(&L,n,&s);
				printf("The name of the deleted student is£º%-10s grade£º%5.2f",s.name,s.score);
			}
			printf("Delete completed, press any key to continue\n");
			getch();
			break;
		case 4:
			printf("*****All students' data*****\n");
			dispsqlist(L);
			printf("Press any key to continue\n");
			getch();
			break;
		case 5:
			printf("Please enter the name and grade of the students to be updated, separated by spaces\n");
			scanf("%s%f",s.name,&s.score);
			n=locatesqlist(L,s);
			if(n==L.length+1)
				printf("There is no such data\n");
			updatesqlist(&L,n,s);
			printf("Update completed, press any key to continue\n");
			getch();
			break;
		case 6:
			ranksqlist(&L);
			printf("Sort completed, press any key to continue\n");
			getch();
			break;
		case 0:
			t=0;
			break;
		default:
			printf("Wrong input\n");
			printf("Press any key to continue\n");
			getch();
		}
	}
}
int menu()
{
	int n;
	system("cls");
	printf("******Welcome to the freshman score management system******\n");
	printf("1¡¢Initialize student data             2¡¢Insert new data\n");
	printf("3¡¢Delete student data                 4¡¢Show student data\n");
	printf("5¡¢Update student data                 6¡¢Reorder by score\n");
	printf("0¡¢Exit\n");
	printf("***********************************************************\n");
	printf("Please select function number:");
	scanf("%d",&n);
	getchar();
	return n;
}
int initsqlist(sqlist *L,int max)
{
	L->data=(STD *)malloc(max*sizeof(STD));
	if(L->data==NULL)
	{
		printf("Allocation failed\n");
		return 0;
	}
	L->length=0;
	L->listsize=max;
	return 1;
}
int insertsqlist(sqlist *L,int i,STD x)
{
	int k;
	if(L->length>=L->listsize)
	{
		printf("There is no space to insert\n");
		return 0;
	}
	for(k=L->length;k>=i;k--)
		L->data[k]=L->data[k-1];
	L->data[i-1]=x;
	++L->length;
	return 1;
}
int deletesqlist(sqlist *L,int i,STD *x)
{
	int k;
	if(L->length==0)
	{
		printf("There is no data to delete\n");
		return 0;
	}
	(*x)=L->data[i-1];
	for(k=i;k<=L->length;k++)
		L->data[k-1]=L->data[k];
	--L->length;
	return 1;
}
int locatesqlist(sqlist L,STD x)
{
	int k;
	if(L.length==0)
	{
		printf("There is no such data\n");
		return 0;
	}
	for(k=1;k<=L.length;k++)
		if(strcmp(L.data[k-1].name,x.name)==0)
			break;//compare two names in the strings and loacte it
	return k;
}
int dispsqlist(sqlist L)
{
	int k;
	if(L.length==0)
	{
		printf("There is no such data\n");
		return 0;
	}
	for(k=1;k<=L.length;k++)
		printf("name£º%-10s grade£º%5.2f\n",L.data[k-1].name,L.data[k-1].score);
	return 1;
}
int updatesqlist(sqlist *L,int i,STD x)
{
	if(L->length==0)
	{
		printf("There is no data to update\n");
		return 0;
	}
	L->data[i-1]=x;
	return 1;
}
int lengthsqlist(sqlist L)
{
	int k;
	for(k=1;k<=L.length;++k);
	return k;
}
int ranksqlist(sqlist *L)
{
	int i,j;
	STD k;
	if(L->length==0)
	{
		printf("There is no such data\n");
		return 0;
	}
	for(i=1;i<=L->length;i++)
	{
		for(j=1;j<=L->length-i;j++)
		{
			if(L->data[j-1].score<=L->data[j].score)
			{
				k=L->data[j-1];
				L->data[j-1]=L->data[j];
				L->data[j]=k;//swap the two variables
			}
		}
	}
	return 1;

}
