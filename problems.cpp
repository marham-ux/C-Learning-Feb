#include <iostream>

using namespace std;
/*
const int &max(const int &a, const int &b)
{
    return (a > b) ? a : b;
}

int main()
{
    const int &m = max(10, 20);
    std::cout << m;
}
*/
void process(int *ptr)
{
    if (ptr != nullptr)
        *ptr += 10;
}

int main()
{
    int x = 5;
    int *p = nullptr;
    process(p);

    int &ref = *p; // Line X
    ref = 100;

    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr + 5;
    std::cout << *ptr; // Line Y
}