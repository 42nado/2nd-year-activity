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

     int last;
} LIST;
LIST L;
float computeAverage(int q1, int q2, int q3);
void makenull();
int insert(char x[50],int q1, int q2, int q3);
int locatename (char x[50]);
void update(char x[50]);
void del(char x[50]);
int locate(char x[50]);
int isfull();
int isempty();
void display();
int menu();

int main(){
char x[50];
int  option,g,qq1[MAX],qq2[MAX],qq3[MAX];
makenull();
while(1){
    option = menu();
    switch(option){
        case 1 : system("cls");printf("Insert Mode\n");
        //do{
                printf("First Name: ");
                scanf(" %s",x);
               /*  g=locatename(x);
                 if(g==1)
                    printf("Name is already in the records.\nInput another one.\n");
                 }while(g==1);*/
                printf("Quiz #1: ");
                scanf("%d",&qq1);
                printf("Quiz #2: ");
                scanf("%d",&qq2);
                printf("Quiz #3: ");
                scanf("%d",&qq3);
                insert(x,qq1,qq2,qq3);
                break;
        case 2 : system("cls");display();printf("Delete Mode\n");printf("Input nume to delete: ");scanf("%s",x);del(x);break;
        case 3 : printf("Enter name of student to update: ");scanf("%s", x);update(x);break;
        case 4 : display();getch();break;
        case 5 : exit(0);
        default: printf("1-4 lang!");getch();
    }
  }
}
int menu(){
int i, opt;
char *m[] = {"Insert","Delete","Update","Display","Exit"};
system("cls");
printf("M E N U\n");
for(i=0;i<5;i++)
    printf("%d.) %s\n",i+1,m[i]);
printf("\nSelect(1-5): ");
scanf("%d",&opt);
return(opt);

}
void makenull(){
     L.last = 0;
}
int insert (char x[50],int q1, int q2, int q3){
   if (isfull())  {
       printf("List is full.");
       getch();
      }
   else {
                L.last++;
                strcpy(x,L.name[L.last]);
                L.quiz1[L.last] = q1;
                L.quiz2[L.last] = q2;
                L.quiz3[L.last] = q3;


      }
}
int isfull(){
  return (L.last == MAX-1);
}
void del (char x[50]){
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
int locate (char x[50]) {
    int j,i;
for (i = 0; i<= L.last; i++){
    j=strcmp(x,L.name[i]);
     if (j==0)
            return (i);}
return(-1);
}
int isempty ( ) {
  return ( L.last == -1);
}


void update(char x[50])
{
    system("cls");
    int p,i,qq1,qq2,qq3,updatechoice;
    int counter=0;
    char nam[50];
    if(isempty()){
        printf("Empty");
        getch();

    }
    else{
        p=locate(x);
        if(p<0){
           printf("Not found");
           getch();
           }
        else {
                i=p;
            do{
            printf("Input number to update:\n [1]quiz1\n [2]quiz2\n [3]quiz3\n [4]name\n [5]Exit\n ");
            scanf("%d", &updatechoice);
            switch(updatechoice){
                case 1: printf("Input quiz1: ");scanf("%d", &qq1);
                        L.quiz1[i]=qq1;break;
                case 2: printf("Input quiz2: ");scanf("%d", &qq2);
                        L.quiz2[i]=qq2;break;
                case 3: printf("Input quiz3: ");scanf("%d", &qq3);
                        L.quiz3[i]=qq3;break;
                case 4: printf("Enter name: ");scanf("%s", nam);
                        strcpy(L.name[i],nam);break;
                case 5: counter = 1;
                        }
            }while(counter==0);
        }
        display();
 }
}/*
int locatename(char x[31])
{
   int i,j,k;
for(i=0;i<=L.last;i++)
    {j=strcmp(x,L.name[i]);
        if(j==1){
            printf("*Surname has a similar data in the records.*\n");
            getch();
            system("cls");
                return 1;
        }
    }

return-1;
}*/
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
