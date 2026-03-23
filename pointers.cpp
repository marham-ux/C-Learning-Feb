#include<iostream>
using namespace std;

int change(int x)
{
   return x = 20;
}

int main(){

 int intVar1 {10};
 int* p_numb = &intVar1;

cout<<intVar1<<endl<<p_numb<<endl<<*p_numb<<endl;
int a = 10;
cout << change(a) <<endl;
cout<< a;

const char* P_charString {"heloo world"};
cout<< P_charString<<endl;
cout<< *P_charString<<endl;




}