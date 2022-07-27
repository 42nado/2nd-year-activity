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
        case 3 : system("cls"); front();getch();break;
        case 4 : system("cls");rear();getch();break;
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
printf("SIR LINEAR QUEUE ITONG GAWA KO MERON PANG MGA MALI PERO WORKING NAMAN SIYA\n");
printf("PAGAARALAN KO NALAANG PO MUNA CIRCULAR\n");
system("color 0a");
for(i=0;i<6;i++)
    printf("%d.) %s\n",i+1,m[i]);
printf("\nSelect(1-6): ");
scanf("%d",&opt);
return(opt);

}
void makenull(){
    Q.front = Q.rear = 0;
}
void enqueue(int x){
    if (isfull()){
          printf("QUEUE IS FULL");
          getch();
        }
        if (Q.front == -1)
            Q.front = 0;

        Q.rear++;
        Q.DATA[Q.rear] = x;
         //Q.rear++;
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
    return((Q.front==0 && Q.rear==MAX-1) || (Q.front==Q.rear+1));
}

int isempty(){
   return(Q.front== Q.rear);
}
int front()
{
    printf("\n\t The front elements is %d",Q.DATA[Q.front]);
    //return Q.DATA[Q.front];
}
int rear()
{
    printf("\n\t The rear elements is %d",Q.DATA[Q.rear]);
}
void display(){
int i;
    system("cls");
    printf("The queue contain...\n");
    for(i=Q.front;i<=Q.rear;i++)
         printf("%d\n",Q.DATA[i]);
}

