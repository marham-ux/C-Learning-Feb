#include<iostream>
using namespace std;

int main()
{
    int i,j,k,x,l;
i = j = k = x = l =1 ;


cout<<"enter the number : "<<endl;
cin>> x;

k = (x + 1)/2 + 1;

for(i = 1; i <= x ; ++i)
    {
        i < (x + 1)/2 +1 ? k-- :k++;
        l = 1;

        for(j = 1 ; j<= (x + 1)/2 ; j++ )
        {
            if(j >=k)
            {cout<<l;
            l++;}
            else
            cout<<" ";
        }
    cout<<endl;

    }


}