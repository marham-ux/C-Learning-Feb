#include <iostream>

using namespace std;

int main()
{

    int option, size = 0, capacity;

    cout << "Enter initial size:";
    cin >> capacity;

    if (capacity <= 0)
        capacity = 10;

    int *array = new int[capacity];

    do
    {
        cout << "menu : \n 1. Add number\n 2. Insert at position \n 3. Delete at position \n 4. Display \n 5. Resize \n 6. Exit\n";
        cin >> option;
    } while (option != 6);
}

void capacityChecker(int &size, int *array, int &capacity)
{

    if (size == capacity)
    {
        size_t newCapacity = capacity * 2;
        int *newArray = new int[newCapacity];

        for (size_t i = 0; i < size; i++)
            newArray[i] = array[i];

        delete[] array;
        array = newArray;
        capacity = newCapacity;

        cout << "Array resized automatically to " << capacity << endl;
    }
}
void numAdder(int &size, int *array, int &capacity, int num)
{
    capacityChecker(size, array, capacity);
    array[size] = num;
    size++;
}

void posInserter(int &size, int *array, int &capacity)
{

    int num, pos;
    cout << "enter your number and its position you want inserted";
    cin >> num >> pos;

    capacityChecker(size, array, capacity);

    for (int i = size; i > pos; i--)
    {

        array[i + 1] = array[i];
    }
    array[pos] = num;
    size++;
}
void posDeleter(int &size, int *array, int &capacity)
{
    int num, pos;
    cout << "enter your number and its position you want deleted";
    cin >> num >> pos;

    capacityChecker(size, array, capacity);
    for (int i = pos; i < size; i++)
    {

        array[i] = array[i + 1];
    }
    size--;
}

void display(int &size, int *array)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << endl;
}

void resizeCapacity(int *&array, size_t &size, size_t &capacity)
{
    size_t newCapacity;
    cout << "Enter new capacity: ";
    cin >> newCapacity;

    if (newCapacity <= 0)
    {
        cout << "Invalid capacity! Must be greater than 0.\n";
        return;
    }

    // If new capacity is same as current, do nothing
    if (newCapacity == capacity)
    {
        cout << "Capacity is already " << capacity << ". No change needed.\n";
        return;
    }

    // Allocate new array
    int *newarray = new int[newCapacity];

    // Copy existing elements (only up to new capacity)
    size_t elementsToCopy = (newCapacity < size) ? newCapacity : size;

    for (size_t i = 0; i < elementsToCopy; i++)
    {
        newarray[i] = array[i];
    }

    // Delete old array
    delete[] array;

    // Update everything
    array = newarray;
    capacity = newCapacity;

    // Important: If shrinking, reduce size
    if (newCapacity < size)
    {
        size = newCapacity;
        cout << "Array shrunk. Last " << (size - newCapacity) << " elements were removed.\n";
    }

    cout << "Successfully resized to capacity: " << capacity << endl;
}