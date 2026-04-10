#include <iostream>
using namespace std;

int main()
{
    double monthlySalary, annualSalary, taxRate, annualTax, monthlyTax, remainingSalary;

    // Input monthly salary
    cout << "Enter monthly salary: ";
    cin >> monthlySalary;

    // Calculate annual salary
    annualSalary = monthlySalary * 12;

    // Determine tax rate
    if(annualSalary <= 600000)
        taxRate = 0;
    else if(annualSalary <= 1000000)
        taxRate = 0.10;
    else if(annualSalary <= 1500000)
        taxRate = 0.125;
    else
        taxRate = 0.15;

    // Calculate tax
    annualTax = annualSalary * taxRate;
    monthlyTax = annualTax / 12;

    // Remaining salary after tax
    remainingSalary = monthlySalary - monthlyTax;

    // Output
    cout << "Annual Salary: " << annualSalary << endl;
    cout << "Annual Tax: " << annualTax << endl;
    cout << "Monthly Tax: " << monthlyTax << endl;
    cout << "Remaining Monthly Salary: " << remainingSalary << endl;

    return 0;
}