#include <iostream>
#include <string>
using namespace std;

bool isDone[30] = {false};
string tasks[30]; // global array
int i = 0;        // global counter

void takeString(void)
{
if(i >= 30)
    {cout<<"max task are 30\n";
   return;}

    cin.clear();    
    cin.ignore(1000, '\n');
    cout << "enter the new task"<<endl;  
    getline(cin, tasks[i]);
   
    if(tasks[i]=="") 
    {cout<<"Error: Task cannot be empty!\n";
    return;
    } 
    else   
    cout << "Task added: " << tasks[i];
    i++;
}
void checker(void)
{
    if (i == 0)
    {
        cout << "No tasks to mark!\n";
        return;
    }
    
    int num;
    cout << "enter task number you want to be sone or undone";
    cin >> num;
    if (num < 1 || num > i)
    {
        cout << "Invalid task number!\n";
        return;
    }
    isDone[num - 1] = !isDone[num - 1];
    cout << "Task " << num << " status updated!\n";
}

void viewTask(void)
{
    for (int j = 0; j < i; j++)
    {
    cout << (j + 1) << ". ";    
    cout << (isDone[j] ? "[X]" : "[ ]") << " "<< tasks[j]<< endl;
    }    
}

void deleter(void)
{
    if (i == 0)
    {
        cout << "No tasks to delete!\n";
        return;
    }
    viewTask();
    int num;
    cout << "enter task number you want to be sone or undone";
    cin >> num;
    if ( num < 1 || num > i)
    {
        cout << "Invalid task number!\n";
        return;
    }
 for (int j = num - 1; j < i - 1; j++)
    {
        tasks[j] = tasks[j + 1];
        isDone[j] = isDone[j + 1];
    }

    i--;
    cout << "Task deleted successfully!\n";
}


int main()
{
    int input;
    do
    { 

        input = 0;   
        cout << "== TASK LIST ==\n"
             << "1. Add new task\n"
             << "2. View all tasks\n"
             << "3. Mark task as done/undone\n"
             << "4. Delete task\n"
             << "5. Exit\n\n"
             << "Enter your choice: \n";
        cin >> input;

        if (cin.fail())
        {
            cin.clear();                                    // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore bad input
            cout << "Invalid input! Please enter a number (1-5).\n";
            continue;                                       // Go back to menu
        }

    switch (input)
    {
    case 1:
    {
        takeString();
        break;
    }
    case 2:
        viewTask();
        break;

    case 3:
        checker();
        break;

    case 4:
        deleter();
        break;

    case 5:
        cout << "exited";
        break;

    default:{
        cout << "invalid input";
        cin.ignore();
        break;
    }
    }
} while (input != 5);
}