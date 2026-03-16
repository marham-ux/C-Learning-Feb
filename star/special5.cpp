#include <iostream>

using namespace std;
int main()
{

int i,j,k,x;
i = j = k = x = 1 ;


cout<<"enter the number : "<<endl;
cin>> x;

for(i = 1; i <= x ; ++i)
     {
        k ='1';
        for(j = 1 ; j <= x + i - 1 ; ++j)
        {
            if((j >= (x - i + 1))&& (j <=(x + i -1)))
            {
                if(j == x + 1 )
                k='A';
                cout<<char(k);
                k++;
            }
            else
            {cout<<" ";}
        }
    cout<<endl;
     }

}