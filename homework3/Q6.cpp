#include<iostream>
using namespace std;

int main(){
int x ,n;
cout<<"enter the value of x and n\n";
cin>>x>>n;


double sum = 1.0;
double term = 1.0;



for(int i = 1; i <= n; i++)
{
    term = term * x / i;
    sum = sum + term;
}

cout<<sum;


}