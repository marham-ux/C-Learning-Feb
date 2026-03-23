#include <iostream>
using namespace std;

int main(){

  int sum;
    cout << "Enter a number: ";
    cin >> sum;

while(sum)
  {
   cout<<sum % 10;
   sum = sum/10;

  }
}