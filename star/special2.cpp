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
        k ='A';
        for(j = 1 ; j <= ((x*2) - 1) ; ++j)
        {
            if((j <= (x - i + 1)) || (j >=(x + i -1)))
            {
               cout<<char(k);
                j < x ? k++ :k--;
            }
            else
            {
                cout<<" ";
                if(j == x)
                k--;
            }
        }
    cout<<endl;
     }

}