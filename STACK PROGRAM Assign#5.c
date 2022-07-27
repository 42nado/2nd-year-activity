#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define MAX 5
typedef struct stack {
        int S[MAX];
        int top;
} STACK;
STACK S;
void display();
int isempty();
int isfull();
void pop();
int menu();
void makenull();
void push(int x);
int main(){
int x, option;
makenull();
while(1){
    option = menu();
    switch(option){
        case 1 : system("cls");printf("Push\n");printf("Input x: ");scanf("%d",&x);push(x);break;
        case 2 : system("cls");pop();getch();break;
        case 3 : display();getch();break;
        case 4 : exit(0);
        default: printf("1-4 lang!");getch();
    }
  }
}
int menu(){
int i, opt;
char *m[] = {"Push","Pop","Display","Exit"};
system("cls");
printf("M E N U\n");
for(i=0;i<4;i++)
    printf("%d.) %s\n",i+1,m[i]);
printf("\nSelect(1-4): ");
scanf("%d",&opt);
return(opt);

}
void makenull(){
    S.top = MAX;
}
void push(int x){
    if (isfull()){
          printf("Stack Overflow.");
          getch();
        }
    else {
          S.top--;
          S.S[S.top] = x;
    }
}
void pop(){
   if (isempty()){
       printf("Stack is empty.");
       getch();
      }
   else
       printf("\n\t The popped elements is %d",S.S[S.top]);
       S.top++;
}
int isfull(){
    return(S.top==0);
}

int isempty(){
   return(S.top==MAX);
}
void display(){
 int i;
system("cls");
printf("The stack contain...\n");
for(i=S.top;i<MAX;i++)
     printf("%d\n",S.S[i]);
}
