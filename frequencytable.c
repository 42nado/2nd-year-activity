#include <stdio.h>
#include <stdlib.h>
int chars[256];
void initArray(){
for(int i = 0;i<256;i++)
    chars[0];
}
int main(){
FILE *fp;
char ch,*fn;
int count = 0;
initArray();
system("cls");
printf("Input file: ");
gets(fn);
fp=fopen(fn,"r");
if (fp==NULL)
    printf("File Error.");
else{
    while(!feof(fp)){
        ch = fgetc(fp);//bof
        chars[ch]++;
        putchar(ch);
        count++;
    }
    fclose(fp);
for (int i =0;i<256;i++){
    if(chars[i]>0)
        printf("\n%d  :  %c   :  %d ",i,i,chars[i]);
}
printf("\nFile size: %d bytes.",count-1);
}


}
