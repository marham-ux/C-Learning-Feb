#include <iostream>
#include <cmath>

using namespace std;


int main()
{

    int num , new_num = 0, i = 0;
    cout<<"enter number in range 100-9999\n";
cin>>num;  

while(num < 100 || num > 9999 )
{
    cout<<"error select in the range 100-9999\n";
    cin>>num;
}


int same = num;

while(same)
{
  same = same / 10;
  i++;

}
same = num;

while(num)
{
  new_num = new_num + pow((num % 10),(i));
   num = num / 10;
}
if(new_num == same)
cout<<"Yes it is armstrong number";
else
cout<<"Not armstrong number";
}