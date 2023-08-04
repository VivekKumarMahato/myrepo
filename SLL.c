#include<stdio.h>
#include<stdlib.h>

struct node    
{
    int value;            
    struct node *next;    
};

struct node *head;   

void init()
{
    head=NULL;    //initialize the beginning(head) of list to NULL
}

void insertfirst(int element)   
{
    struct node *New;
    New=(struct node*)malloc(sizeof(struct node));    
    New->value=element;       
    New->next=NULL;           
    New->next=head;          
    head=New;              
}

void print()
{
    if(head==NULL)    
    {
        printf("list is empty\n");
        return;
    }
    struct node *cur=head;            
    int count;
    count=0;
    while(cur!=NULL)                  
    {
        printf("%d->",cur->value);    
        count++;                      
        cur=cur->next;                
    }
    printf("NULL\n");
    printf("number of nodes %d\n",count);
}

void deleteitem(int ele)
{
    if(head==NULL)
        printf("list is empty and nothing to delete\n");
    struct node* cur=head;
    struct node* prev=NULL;
    while(cur->value!=ele)
    {
        prev=cur;
        cur=cur->next;
    }
    if(prev!=NULL)
        prev->next=cur->next;       
    free(cur);                      
}



void insertlast(int ele)   
{
    struct node *New, *temp;
    New = (struct node*)malloc(sizeof(struct node));
    if(New== NULL)
    {
        printf("Unable to allocate memory.");
        return;
    }
    else
    {
        New->value = ele;
        New->next = NULL;
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = New;
        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}

void deletelast()   
{
    if(head==NULL)
    {
        printf("list is empty and nothing to delete\n");
    }
    struct node* cur=head;
    struct node* prev=NULL;
    while(cur->next!=NULL)
    {
        prev=cur;
        cur=cur->next;
    }
    if(prev->next!=NULL)
        prev->next=NULL;
    free(cur);
}

void deletefirst()  
{
    struct node* cur;
    if(head==NULL)
        printf("list is empty and nothing to delete\n");
    cur=head;
    head=head->next;
    free(cur);
}

void insertafter(int elem, int num)   
{
    struct node* New;
    New=(struct node*)malloc(sizeof(struct node));
    New->value=elem;
    New->next=NULL;
    struct node* prev=head;
    while(prev->value!=num)
    {
        prev=prev->next;
    }
    New->next=prev->next;
    prev->next=New;
}








int main()
{
    init();

    int ch,element;
    while(1)
    {
        printf("\n1. Insert new item. \n2. Delete item. \n3. Insert Last. \n4. Print. \n5.Delete Last \n6.Delete First \n7.Insert After. \n8.Exit\n");
        printf("enter choice of input: ");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("enter element to list: ");
            scanf("%d",&element);
            insertfirst(element);
        }
        else if(ch==2)
        {
            int de;
            printf("enter element to delete ");
            scanf("%d",&de);
            deleteitem(de);
        }
        
        else if(ch==3)
        {
            int le;
            printf("enter element to insert at last ");
            scanf("%d",&le);
            insertlast(le);
        }
        else if(ch==4)
        {
            print();
        }
        else if(ch==5)
        {
            deletelast();
        }
        else if(ch==6)
        {
            deletefirst();
        }
        else if(ch==8)
        {
            int ie,p;
            printf("enter element to insert: ");
            scanf("%d",&ie);
            printf("enter after which element to insert: ");
            scanf("%d",&p);
            insertafter(ie,p);
        }
        
        else if(ch==8)
            return 0;
        else
            return 0;
    }
    return 0;
}