#include <iostream>
#include<string>
#include<iomanip>
using namespace std;

bool isPhilandrope(string word);
void process(bool isPhilandrope, string word);
void philandrope (const string& user_text);
int main()
{

  string user_text;  
cout<<"Enter your text: ";
getline(cin , user_text);

philandrope (user_text);




}
void philandrope (const string& user_text)
{
    string word ="";
  for(char ch : user_text)
  {
    if(isspace(ch))
    {

        if(!word.empty())
        {
        process(isPhilandrope(word),word);
        word ="";
        }
    }
    else
    word += ch;
  }
if(!word.empty())
{
process(isPhilandrope(word),word);
}

}

bool isPhilandrope(string word)
{
    // Step 1: Convert entire word to lowercase
    for(char &ch : word) {          
        ch = tolower(ch);
    }

    // Step 2: Check palindrome using two pointers (left and right)
    int left = 0;
    int right = word.length() - 1;

    while (left < right)
    {
        if (word[left] != word[right])
            return false;           

        left++;
        right--;
    }

    return true;                   
}


int counter = 0;

void process(bool isPhilandrope, string word)
{
  
 if(isPhilandrope && counter == 0) 
 {
  cout<<"yes"<<setw(10)<<word;
  counter++;
 }
 else if(isPhilandrope)
 cout<<"  "<<word;
}

