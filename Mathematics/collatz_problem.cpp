#include <iomanip>
#include <iostream>
using namespace std;


    void collatz(int num ,int counter,int &maxVal)
{
    
   if(num <= 1)
    {
        cout<<counter<<"\n";
        cout<<maxVal;
        return;
       
    }
       if (num > maxVal)
        maxVal = num;

if(num % 2 == 0)
{
collatz(num / 2,counter + 1,maxVal) ;
}
else
{
 collatz(num *3+1,counter + 1,maxVal);
    
}
}

int main() {
 int num;
    cout << "Enter number: ";
    cin >> num;
int maxnum = num;

collatz( num ,0,maxnum);

}