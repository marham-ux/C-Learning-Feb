#include <iostream>
#include <limits>

using namespace std;

int main()
{
const long long maxFact = numeric_limits<long long>::max();

bool checker = false;
long long last_valid_k =0;
long long factorialNumber = 1;
int number =0;

do {
        cout << "Enter n (1-20): ";
        cin >> number;
        if (number < 1 || number > 25) {
            cout << "Invalid! Please enter number between 1 and 20.\n";
        }
    } while (number < 1 || number > 25);


for(int i = 1; i <= number; ++i)
{
     if(factorialNumber > maxFact / i)
   {
    checker = true;
    last_valid_k = i - 1;
            break;
   }
 factorialNumber *= i;
}
if(checker)
{
   cout<< "n value causes overflow!\n";
   cout<< "last valid value : "<<  last_valid_k << "="<< factorialNumber<<"/n";
    cout << "nax long long value :"<< maxFact;

}
else{cout<<"result : " << factorialNumber;}


}