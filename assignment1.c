#include <stdio.h>
#include <conio.h>
#define MAX 2
#define NAMELENGTH 30

//Arrays as Global variables

char name[MAX][NAMELENGTH];
int quiz1[MAX];
int quiz2[MAX];
int quiz3[MAX];

void getRecord();
float computeAverage(int q1, int q2, int q3);
void displayAll();

int main(){
getRecord();
displayAll();
}

void getRecord(){
system("cls");
for (int i = 0;i<MAX;i++){
        printf("Enter Name of Student #%d: ",i+1);
 //       scanf("%s",name[i]);
        scanf(" %[^\n]s", name[i]);
        printf("\nQuiz 1 : ");
        scanf("%d",&quiz1[i]);
        printf("\nQuiz 2 : ");
        scanf("%d",&quiz2[i]);
        printf("\nQuiz 3 : ");
        scanf("%d",&quiz3[i]);
 //       getchar();
}

}


float computeAverage(int q1, int q2, int q3){
 return((q1+q2+q3)/3.0);
}

void displayAll(){
float average;
system("cls");
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 RECORD \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
printf("============================================================\n");
printf("No.NAME\tQuiz1\tQuiz2\tQuiz3\tAverage\t Remarks  \n");
for (int i =0;i<MAX; i++){
   average = computeAverage(quiz1[i],quiz2[i],quiz3[i]);

   printf("%d.) %s\t%d\t%-d\t%-d\t%6.2f\t",i+1,name[i],quiz1[i],quiz2[i],quiz3[i],average);
      if (average >= 75.00)
        printf("PASSED\n");
     else
        printf("FAILED\n");

 }
}
