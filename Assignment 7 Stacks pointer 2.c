#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct st_point{
  int ele;
  struct st_point *l;
}
*t;
int i;
void push(int j);
int pop();
void display();
void main()
{
  char choice,num1=0,num2=0;
  int i;
  while(1){
    system("cls");
    printf("\n\tMENU ");
    printf("\n[1]Push ");
    printf("\n[2]Pop");
    printf("\n[3]Display");
    printf("\n[4] Exit\n");
    printf("\n\tEnter your choice: ");
    fflush(stdin);
    scanf("%c",&choice);
    switch(choice-'0')
    {
      case 1:system("cls");printf("\n\tElement to be pushed:");scanf("%d",&num1);push(num1);
	break;
      case 2:system("cls");num2=pop(1);printf("\n\tElement to be popped: %d\n\t",num2);getch();
	break;
      case 3:system("cls");printf("\n\tElements present in the stack are:\n");display();getch();
	break;
      case 4:exit(1);
	break;
      default:
	printf("\nYour choice is invalid.\n");
	break;
    }
  }
}
void push(int j)
{
  struct st_point *m;
  m=(struct st_point*)malloc(sizeof(struct st_point));
  m->ele=j;
  m->l=t;
  t=m;
  return;
}
int pop()
{
  if(t==NULL)
  {
    printf("\nSTACK is Empty.");
    getch();
    exit(1);
  }
  else{
    int i=t->ele;
    t=t->l;
    return (i);
  }
return 0;
}
void display()
{
  struct st_point *pointer=NULL;
  pointer=t;
  int i=1;
  while(pointer!=NULL)
  {
    printf("%d).%d\n",i++,pointer->ele);
    pointer=pointer->l;
  }
}
