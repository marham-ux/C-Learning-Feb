#include <iostream>

using namespace std;
int main()
{

int i,j,k,x,p;
i = j = x  = 0 ;
p = 1;

cout<<"enter the number for right triangle: "<<endl;
cin>> x;

for(i = 0; i < x ; ++i)
    {
    p = 1;
        for(j = 0 ; j <= i ; ++j)
        {
               cout<<p<<" ";
             p = p * (i - j) / (j + 1);
     }
     cout<<endl;
    }

}