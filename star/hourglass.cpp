#include <iostream>

using namespace std;
int main()
{

int i,j,k,x;
i = j = k = x = 1 ;


cout<<"enter the number for triangle: "<<endl;
cin>> x;

for(i = 1; i <= x ; ++i)
     {
        k = 1 ;
        for(j = 1 ; j <= ((x*2) - (i*2) + i) ; ++j)
        {
            if(j >=  i && j <=((x*2) - (i*2) + i) && k)
               {cout<<"*"; k = 0;}
            else
            {cout<<" "; k = 1;}
        }
    cout<<endl;
     }

 for(i = 1; i <= x ; ++i)
     {
        k = 1 ;
        for(j = 1 ; j <= x + i - 1 ; ++j)
        {
            if(j >= (x - i + 1) && j <=(x + i -1) && k)
               {cout<<"*"; k = 0;}
            else
            {cout<<" "; k = 1;}
        }
    cout<<endl;
     }
     
}