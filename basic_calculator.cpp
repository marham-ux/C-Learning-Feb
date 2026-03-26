#include<iostream>
#include<limits>

using namespace std;
int main() {
    char op;
    double a, b, res;

    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    if (op == '+')
        res = a + b;
    else if (op == '-')
        res = a - b;
    else if (op == '*')
        res = a * b;
    else if (op == '/')
        res = a / b;
    else {
        cout << "Error! Operator is not correct";
        return 0;
    }
        cout << "Result: " << res;
    return 0;
}