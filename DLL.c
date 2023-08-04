#include<stdio.h>
#include <stdlib.h>

typedef struct dl
{
        int val;
        struct dl *prev, *next;
}dll;
dll* createNode(int el)
{ 
	dll *newnd;
	newnd=(dll*)malloc(sizeof(dll));
	newnd->val=el;
	newnd->next=NULL;
	newnd->prev=NULL;
	return newnd;
}
dll* insertBeg(dll *st, int el)
{
	dll *newnd;
	newnd=createNode(el);
	if(st==NULL)
		st=newnd;
	else
	{
		newnd->next=st;
		st->prev=newnd;
		st=newnd;
	}
    return st;
}
dll* insertEnd(dll *st, int el)
{
	dll *newnd,*q=st;
	newnd=createNode(el);
	if(st==NULL)
		st=newnd;
	else
	{
		while(q->next)
			q=q->next;
		newnd->prev=q;
		q->next=newnd;
	}
	return st;
}
void displayForward(dll *st)
{
	dll *p;
	if(st==NULL)
	{
		printf("LINKED LIST IS EMPTY\n");
		return;
	}
	else
	{
		printf("\nLINKED LIST :");
		for(p=st; p!=NULL; p=p->next)
			printf("%d\t",p->val);
	}
}

dll* deleteEnd(dll *st)
{
	dll *q=st;
	if(st==NULL)
		printf("\nList is empty");
	else
	{
		if(st->next==NULL)
			st=NULL;
		else
		{
  		 	while(q->next)
  		 		q=q->next;
			q->prev->next=NULL;		
  	}
  }
	free(q);
	return st;
}

dll* deleteBeg(dll *st)
{
	dll *q=st;
	if(st==NULL)
		printf("\nList is empty");
	else
	{
		if(st->next==NULL)
			st=NULL;
		else
		{
			st=q->next;
			st->prev=NULL;
		}
	}
	free(q);
    return st;
}
int main()
{
	dll *st=NULL;	
	int ch, el;
	while(1)
	{
		printf("\n1: Insert at Beginning\n2: Insert at End\n3: Delete at Beginning\n4: Delete at End\n5: Forward Display\n6: Exit\n");
		printf("Enter your Choice:");
		scanf("%d", &ch);
		switch(ch)
		{			
		 case 1:
		 	printf("Enter the Value:");
			scanf("%d", &el);
			st=insertBeg(st,el);
			break;
		 case 2:
		 	printf("Enter the Value:");
			scanf("%d", &el);
			st=insertEnd(st,el);
			break;
		 case 3:
			st=deleteBeg(st);
			break;
		 case 4:			
			st=deleteEnd(st);
			break;
		 case 5:
			displayForward(st);
			break;
		 case 6:
			 exit(0);
			 break;
		 default:
			 printf("Wrong choice");
		}
	}
}