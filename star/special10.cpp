#include <iostream>

using namespace std;
int main()
{
int i,j,k,x,n,n2;
i = j = k = x = 1 ;
n = n2 = 0;

cout<<"enter the number : "<<endl;
cin>> x;

for(i = 1; i <= x ; ++i)
 {    
      if(i % 2 ==1)
      n = n + 1;
      else
     { 
      n--;
      n = n + i;
     }
      n2 =n;
      k = 1;
        for(j = 1 ; j <= 2*x - 1 ; ++j)
      {
        if(j <=i * 2 - 1)
        {if(k == 1)
            {cout<<n2;
            if(i % 2 )
             {
                n2++;
                n++;             
             }   
             else
             n2--;
           
             k--;}
            else
            {cout<<"*"; 
            k++;}
        }
        else
        cout<<" ";
      }
 cout<<endl;
    }


}