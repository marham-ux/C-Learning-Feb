#include<iostream>
using namespace std;

int main(){

int num;//declering
int sum;
int temp = 0;

cout<<"enter the a five-digit number"<<endl;
cin>> num;//taking input

do{
while(num)
{
    temp = temp + (num % 10);
    num = num /10;

}
num = temp;
temp = 0;
}while(num > 10);

if(num % 3 == 0)
cout<<"devisible by three";
else
cout<<"not devisible";
}
