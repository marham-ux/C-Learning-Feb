#include <iostream>
using namespace std;

int main()
{
    int num1 = 15, num2 = 83;
    char op;

    // Ask user for operation
    cout << "Enter operation (+, -, *, /): ";
    cin >> op;

    // Switch statement
    switch(op)
    {
        case '+':
            cout << "Result = " << num1 + num2 << endl;
            break;

        case '-':
            cout << "Result = " << num1 - num2 << endl;
            break;

        case '*':
            cout << "Result = " << num1 * num2 << endl;
            break;

        case '/':
            cout << "Result = " << (double)num1 / num2 << endl;
            break;

        default:
            cout << "Invalid operation!" << endl;
    }

    return 0;
}