#include <stdio.h>
#include <conio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 2

typedef struct list{
 char name[MAX][50];
  int quiz1[MAX];
  int quiz2[MAX];
  int quiz3[MAX] ;
     int DATA[MAX];
     int last;
} LIST;
LIST L;
float computeAverage(int q1, int q2, int q3);
void makenull();
void insert();
void del(int x);
int locate(int x);
int isfull();
int isempty();
void display();
int menu();

int main(){
int x, option;
makenull();
while(1){
    option = menu();
    switch(option){
        case 1 : system("cls");printf("Insert Mode\n");insert();break;
        case 2 : system("cls");display();printf("Delete Mode\n");printf("Input number to delete: ");scanf("%d",&x);del(x);break;
        case 3 : display();getch();break;
        case 4 : exit(0);
        default: printf("1-4 lang!");getch();
    }
  }
}
int menu(){
int i, opt;
char *m[] = {"Insert","Delete","Display","Exit"};
system("cls");
printf("M E N U\n");
for(i=0;i<4;i++)
    printf("%d.) %s\n",i+1,m[i]);
printf("\nSelect(1-4): ");
scanf("%d",&opt);
return(opt);

}
void makenull(){
     L.last = 0;
}
void insert (){
   if (isfull())  {
       printf("List is full.");
       getch();
      }
   else {
                printf("First Name: ");
                scanf(" %[^\n]",L.name[L.last]);
                printf("Quiz #1: ");
                scanf("%d",&L.quiz1[L.last]);
                printf("Quiz #2: ");
                scanf("%d",&L.quiz2[L.last]);
                printf("Quiz #3: ");
                scanf("%d",&L.quiz3[L.last]);
                L.last++;

             }
      }
int isfull(){
  return (L.last == MAX);
}
void del (int x){
    int p;
    if (isempty()){
         printf("List is empty.");
         getch();
        }
      else{
        p = locate(x);
            if (p<0){
                printf("Not found.");
                getch();
            }
            else {
                for (int i = p;i<L.last;i++){
                  strcpy(L.name[i],L.name[i+1]);
                  L.quiz1[i] = L.quiz1[i+1];
                  L.quiz2[i] = L.quiz2[i+1];
                  L.quiz3[i] = L.quiz3[i+1];

            }
            L.last--;
            }
      }
}
int locate ( int x) {
for (int i = 0; i<= L.last; i++)
     if (x==i+1)
            return (i);
return(-1);
}
int isempty ( ) {
  return ( L.last == 0);
}
float computeAverage(int q1, int q2, int q3){
 return((q1+q2+q3)/3.0);
}
void display(){
 int i;
 float ave;
system("cls");
printf("\n");
    printf("\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 RECORD \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("======================================================================================\n");
    printf(" \tNAME\tQuiz1\tQuiz2\tQuiz3\tAverage\t Remarks  ");
    printf("\n======================================================================================\n");
    for(i=0;i<L.last;i++){
        ave = computeAverage(L.quiz1[i], L.quiz2[i], L.quiz3[i]);
        printf("%d.)\t%-s\t%-5d\t%-d\t%-d\t%6.2f\t",i+1,L.name[i],L.quiz1[i],L.quiz2[i],L.quiz3[i],ave);
        if (ave >= 75.00)
        printf("PASSED\n");
        else
        printf("FAILED\n");

    }
    printf("\n\t\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\n");
}
