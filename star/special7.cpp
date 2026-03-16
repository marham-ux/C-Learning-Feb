#include <iostream>

using namespace std;
int main()
{

int i,j,k,x,n;
i = j = x = n = 0 ;
k = 1 ;
cout<<"enter the number: "<<endl;
cin>> x;

for(i = 1; i <= 21 ; ++i)
  { 
    i<=11 ? n++:n--;
     k = n - 1;
      for(j = 1 ; j <=  21; ++j)
    {
        if(j >= 12 - n && j <= 10 + n  )
        {
            cout<<(j < 11 ? k++%10 : k--%10);
        }
        else
        cout<<" ";
    }
    cout<<endl;

  }

}