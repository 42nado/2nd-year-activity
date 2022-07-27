#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <malloc.h>

struct node{
  int data;
  struct noden *link;
};
struct node *top=NULL;
int main(){
  int choice;
  int i;
  while(1){
    system("cls");
    printf("\nMENU \n[1]Push\n[2]Pop\n[3]Display\n[4] Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:system("cls");push();break;
      case 2:system("cls");pop();getch();break;
      case 3:system("cls");display();getch();break;
      case 4:exit(1);break;
      default:printf("\nYour choice is invalid.\n");break;
    }
  }
}
void push(){
    struct node *tmp;
    int pushed;
    tmp=(struct node*)malloc(sizeof(struct node));
    printf("Enter x:");
    scanf("%d",&pushed);
    tmp->data=pushed;
    tmp->link=top;
    top=tmp;
}
void pop()
{
  struct node *tmp;
  if (top==NULL)
  printf("STACKS IS EMPTY");
  else{
tmp=top;
  top=top->link;
  free(tmp);
  }
}
void display()
{
  struct node *ptr;
  ptr=top;
  int i=1;
  system("cls");
  if(top==NULL)
    printf("\n stack is empty");
  else{
  printf("The list contains…\n");
  while(ptr!=NULL)
  {
    printf("%d).%d\n",i++,ptr->data);
    ptr=ptr->link;
  }
}
}
