#include <iostream>
#define MAX 5
using namespace std;
class Myqueque{
private:
    int DATA[MAX];
    int Front;
    int Rear;
    int Count;
public:
    void makenull();
    void enqueue(int x);
    void dequeue();
    int tops();
    void display();
    bool isempty();
    bool isfull();
    bool displayf();
    bool displayr();

};
void Myqueque::makenull(){
   Front =-1; Rear = -1;
}
void Myqueque::enqueue(int x){
   if (isfull()){
       std::cout<<"Queue Overflow."<<std::endl;
       system("pause");
   }
   if (Front == -1)
        Front = 0;

        Rear++;
        DATA[Rear] = x;
}
void Myqueque::dequeue(){
   if (isempty()){
    std::cout<<"Queue is empty."<<std::endl;
    system("pause");
   }
   else{
     printf("\n\t The dequeue elements is %d\n",DATA[Front]);
    Front++;
    if (Front==Rear)
        Front = Rear = -1;
    system("pause");
   }
}
void Myqueque::display(){
int i,j=1;
system("cls");
std::cout<<"The Queue contains"<<std::endl;
for (i=Front;i<=Rear;i++){
    std::cout<<j++<<".) "<<DATA[i]<<std::endl;
}
system("pause");
}
bool Myqueque:: isfull(){
  return(Front==0 && Rear==MAX-1);
}
bool Myqueque:: isempty(){
  return(Front== -1);
}
bool Myqueque::displayf()
{
    printf("\n\t The front elements is %d\n",DATA[Front]);
    system("pause");
    //return Q.DATA[Q.front];
}
bool Myqueque:: displayr()
{
    printf("\n\t The rear elements is %d\n",DATA[Rear]);
    system("pause");
}
int menu(){
int op;
system("cls");
cout << "Menu"<<endl;
cout <<"1. Enqueue"<<endl;
cout <<"2. Dequeue"<<endl;
cout <<"3. Front "<<endl;
cout <<"4. Rear "<<endl;
cout <<"5. Display"<<endl;
cout <<"6. Exit"<<endl;
cout <<"Select (1-6): ";
cin >> op;
return(op);
}
int main(){
  int num;
  Myqueque Q;
  Q.makenull();
  while(true){
    switch(menu()){
    case 1 : system("cls");cout<<"Input Number: ";cin>>num;Q.enqueue(num);break;
    case 2 : Q.dequeue();break;
    case 3 : Q.displayf();break;
    case 4 : Q.displayr();break;
    case 5 : Q.display();break;
    case 6 : exit(0);break;
    }

  }
}
