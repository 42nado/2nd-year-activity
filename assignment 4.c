#include <stdio.h>
#include <conio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 5
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
void upload();
void download();
int insert(char x[50]);
void checkname (char x[50]);
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
download();
while(1){
    option = menu();
    switch(option){
        case 1 : system("cls");system("color 0a");printf("Insert Mode\n");insert(x);break;
        case 2 : system("cls");display();printf("Delete Mode\n");printf("Input nume to delete: ");scanf("%s",x);del(x);break;
        case 3 : printf("Enter name of student to update: ");scanf("%s", x);update(x);break;
        case 4 : display();getch();break;
        case 5 : upload();exit(0);
        default: printf("1-5 lang!");getch();menu();
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
     L.last = -1;//0 kanina
}
int insert (char x[50]){
    int f=0,i;
    char name1[50];
   if (isfull())  {
       printf("List is full.");
       getch();
      }
   else {
                printf("First Name: ");
                scanf(" %[^\n]",L.name[L.last]);
                checkname(L.name[L.last]);
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
  return (L.last == MAX);//max laang
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
            return i;}
return(-1);
}
int isempty ( ) {
  return ( L.last == -1);//0 ito
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
                        checkname(nam);
                        strcpy(L.name[i],nam);break;
                case 5: counter = 1;
                        }
            }while(counter==0);
        }
        display();
 }
}
void checkname(char x[50]){
    int p;
   L.last--;
   p = locate(x);
      if (p >= 0){
         system("cls");
         printf("Name is duplicated!!\n");
         getch();
         main();
      }
      else{
         L.last++;
          strcpy(x, L.name[L.last]);
      }
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
void upload(){
FILE *fp;
int i;
fp=fopen("file.txt","w+");
for (i=0;i<=L.last;i++){
    fprintf(fp,"%s\n",L.name[i]);
    fprintf(fp,"%d\n",L.quiz1[i]);
    fprintf(fp,"%d\n",L.quiz2[i]);
    fprintf(fp,"%d\n",L.quiz3[i]);

    }
fclose(fp);
}
void download(){
FILE *fp;
//int i=0;
fp=fopen("file.txt","r+");
while(!feof(fp)){
    L.last++;
    fscanf(fp,"%s\n",L.name[L.last]);
    //strcpy(L.name[i],L.name[L.last]);
    fscanf(fp,"%d\n",&L.quiz1[L.last]);
   // L.quiz1[i]=L.quiz1[L.last];
    fscanf(fp,"%d\n",&L.quiz2[L.last]);
   // L.quiz2[i]=L.quiz2[L.last];
    fscanf(fp,"%d\n",&L.quiz3[L.last]);
    //L.quiz3[i]=L.quiz3[L.last];
   // i++;
}
fclose(fp);
}

