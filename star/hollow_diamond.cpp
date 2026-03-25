#include <iostream>

using namespace std;
int main()
{

int i,j,k,rows,n;
i = j = k = rows = 0 ;

cout<<"enter the hight for diamond: "<<endl;
cin>> rows;

n = ( rows +1) /2;
for( i =1 ;i <= rows ; i++)
{
  if(rows % 2 == 0)
  {
    if(i <= n) k++;
    if(i > n+1) k--;
  }
else i<=n?k++:k--;
for(j = 1; j <= rows ;j++)
{
    if(j == n - k + 1 || j == n + k - 1 )
        cout<<"*";
    else
        cout<<" ";
}
cout<<endl;
}
}