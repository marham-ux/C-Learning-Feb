#include <iostream>
#include <array>
#include <string>

using namespace std;
int main()
{
/*
int getArraySum(int array[], int size)
{
   int sum = 0;
    for(int index = 0 ; index < size; index++ )
   {sum += array[index];}
    return sum;
}
int main() {
 
    int arr[5] = {65 , 66 , 67 , 68 , 70}; 
    int array2[5] ={1,2,3,4,5};
    cout<<getArraySum(arr,5);
    return 0;
}
    */
array <int,5> nums ={0,1,2,3,4};

cout << nums[0];

cout << nums.size();

char name[] ="helllo";
cout<< name;
}
