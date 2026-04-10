#include <iostream>
using namespace std;

int main()
{
    double F, K;

    // Taking input
    cout << "Enter temperature in Fahrenheit: ";
    cin >> F;

    // Conversion formula
    K = (F - 32) * 5.0 / 9.0 + 273.15;

    // Output result
    cout << "Temperature in Kelvin: " << K << endl;

    return 0;
}