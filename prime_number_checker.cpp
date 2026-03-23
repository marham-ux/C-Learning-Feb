#include <iostream>
using namespace std;

int main(){
  int number;
    cout<<"enter the number ";
    cin>>number;
    int X = number;
    float compare = number;


   bool sum = false;


   for(int i = 2 ; X > i ;i++)
    {
      int p = number/i;
      float p2 = compare/i;

    if(p2 == p && p != 1)
    {
        cout<<"not prime number";
        sum = true;
        break;
    }

    }
    if( sum == false )
    {
        cout<< "prime number";
    }
}