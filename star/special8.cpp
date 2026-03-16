#include <iostream>

using namespace std;
int main()
{

int i,j,k,x;
i = j = k = x = 0 ;


cout<<"enter the number : "<<endl;
cin>> x;

for(i = 1; i <= x ; ++i)
     {
        k = 64 + i;
        for(j = 1 ; j <= x ; ++j)
        {
            if(i >= j)
               {
                cout<<char(k);
                k--;
            }
            else
            {cout<<" ";}
        }
    cout<<endl;
     }

}