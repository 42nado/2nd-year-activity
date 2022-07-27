#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define MAX 5
typedef struct queue {
          int DATA[MAX];
           int front;
          int rear;
          int count;
} QUEUE;
QUEUE Q;

void display();
int isempty();
int isfull();
void dequeue();
int menu();
void makenull();
void enqueue(int x);
int main(){
int x, option;
makenull();
while(1){
    option = menu();
    switch(option){
        case 1 : system("cls");printf("Enqueue\n");printf("Input x: ");scanf("%d",&x);enqueue(x);break;
        case 2 : system("cls");dequeue();getch();break;
        case 3 : system("cls");
        case 4 : system("cls");
        case 5 : display();getch();break;
        case 6 : exit(0);
        default: printf("1-6 lang!");getch();
    }
  }
}
int menu(){
int i, opt;
char *m[] = {"Enqueue","Dequeue","Front","Rear","Display","Exit"};
system("cls");
printf("M E N U\n");
for(i=0;i<6;i++)
    printf("%d.) %s\n",i+1,m[i]);
printf("\nSelect(1-6): ");
scanf("%d",&opt);
return(opt);

}
void makenull(){
    Q.rear = MAX;
}
void enqueue(int x){
    if (isfull()){
          printf("QUEUE IS FULL");
          getch();
        }
    if (rear ==  - 1)
    {
        rear++;
        front++;
    }
    else if (rear == size - 1 && front > 0)
    {
        rear = 0;
    }
    else
    {
        Q.rear++;
    }
    Q.DATA[Q.rear] = x;
}
void dequeue(){
   if (isempty()){
       printf("Queue is empty.");
       getch();
      }
   else
       printf("\n\t The dequeue elements is %d",Q.DATA[Q.front]);
       Q.front++;
        if (Q.front==Q.rear)
        Q.front = Q.rear = -1;
}
int isfull(){
    return((Q.front == 0 && Q.rear == size - 1) || (Q.front == rear + 1));
}

int isempty(){
   return(Q.front== Q.rear);
}
void display(){
if (isfull()){
          printf("QUEUE IS FULL");
          getch();
        }
else{
    int i;
    system("cls");
    printf("The queue contain...\n");
    for(i=Q.front;i<=Q.rear;i++)
         printf("%d\n",Q.DATA[i]);
}
}
