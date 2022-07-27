#include <stdio.h>
#include <conio.h>
#include <malloc.h>


struct queue
{
    int info;
    struct queue *next;
}*front,*rear,*New,*ptr;

void display();
int underflow();
void enqueue(int);
void dequeue();

int main()
{
    int choice,item;
     while(1){
    system("cls");
    printf("MENU\n[1] Enqueque\n[2] Dequeue\n[3] Display\n[4] Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:system("cls");printf("\nEnter x: ");scanf("%d",&item);enqueue(item);break;
        case 2:system("cls");
        if(underflow()==1)
        dequeue();
        getch();
        break;
        case 3:system("cls");display();break;
        case 4:exit(1);
        default:system("cls");printf("Your choice is wrong\n\n");
    }
     }
}
int underflow()
{
    if((front==NULL)&&(rear==NULL))
    {
        printf("\nQueue is empty");
        return(0);
    }
    else
    {
        return(1);
    }
}
void enqueue(int item)
{
    New=(struct queue*)malloc(sizeof(struct queue));
    New->info=item;
    if((front==NULL)&&(rear==NULL))
    {
        front=New;
        rear=New;
        New->next=NULL;
    }
    else
    {
        rear->next=New;
        New->next=NULL;
        rear=New;
    }
}

void dequeue()
{
    if(front==rear)
    {
        front=NULL;
        rear=NULL;
    }
    else
    {
        front=front->next;
    }
}
void display()
{
    int i;
    ptr=front;
    i=1;
    printf("The list contains…\n");
    while(ptr!=NULL)
    {
        printf(" %d). %d\n",i,ptr->info);
        ptr=ptr->next;
        i++;
    }
}
