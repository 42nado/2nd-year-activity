#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<string.h>
#define MAX 20

int last;
void update();
void makempty();
void insert();
void del(int x);
void display();
int isfull();
int isempty();
int locate();
int menu();
char name[MAX][31];
int q1[MAX], q2[MAX],q3[MAX];
float average[MAX];
int i, d, p, x;
int sum=0;

int main(){
makempty();
   while(1){
        switch(menu()){
        case 1 : system("cls");insert();break;
        case 2 : system("cls");display();printf("\nDelete Data\n");printf("Input the number to be deleted:");scanf("%d",&d);del(d);break;
        case 3 : system("cls");display();getch();break;
        case 4 : exit(0);
        default: printf("1-4 ONLY!");getch();

        }
    }
}
void makempty(){
last=0;
}
void insert(){
    printf("\nInsert Data\n");
    if (isfull()){
        printf("There is no space left!");
        getch();
    }
        else {
        printf("First Name: ");
        scanf(" %[^\n]",name[last]);
        printf("Quiz #1: ");
        scanf("%d",&q1[last]);
        printf("Quiz #2: ");
        scanf("%d",&q2[last]);
        printf("Quiz #3: ");
        scanf("%d",&q3[last]);
        last++;
    }

}
void del(int x){

    if (isempty()){
        printf("Empty space!");
        getch();
    }
    else {
    p=locate(x);
    if (p<0){
        printf("Not found.");
        getch();
    }
    else{
      for(i=p;i<last;i++){
                strcpy(name[i],name[i+1]);
                q1[i]=q1[i+1];
                q2[i]=q2[i+1];
                q3[i]=q3[i+1];
        }
        last--;
    }

}
}
void ave()
{
            sum=q1[i]+q2[i]+q3[i];
            average[i] = sum/3.0;
            printf("%6.2f",average[i]);
            if (average[i]>=75.0){
                        printf(" PASSED");
                    }else{
                        printf(" FAILED");
                    }
                    printf("\n");

}
void display(){
    printf("\n");
    printf("\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 RECORD \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("======================================================================================\n");
    printf("  NAME\tQuiz1\tQuiz2\tQuiz3\tAverage\t Remarks  ");
    printf("\n======================================================================================\n");
    for(i=0;i<last;i++){

        printf("%d.)\t%-s\t\t%-5d\t%-d\t%-d\t ",i+1,name[i],q1[i],q2[i],q3[i]);
        ave();
    }
    printf("\n\t\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\n");

}
int isfull(){
   return(last==MAX);
}
int isempty(){
    return(last==0);
}
int locate(int x){
    for(i=0;i<=last;i++){
        if(x==i+1){
            return(i);
        }
    }
    return(-1);
}
int menu(){
    int op;
    system("cls");
    printf("\n");
    printf("\xb2\xb2\xb2\xb2\xb2 MENU \xb2\xb2\xb2\xb2\n");
    printf("1.) Insert\n");
    printf("2.) Delete\n");
    printf("3.) Display\n");
    printf("4.) Exit\n");
    printf("Select(1-4): ");
    scanf("%d",&op);
    return op;
}
