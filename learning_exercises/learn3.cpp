#include<iostream>
#include<string>
#include<cctype>
#include<iomanip>

using namespace std;

bool  ispalindrope(string word);
void process(bool  ispalindrope, string word);
void checkForPalindrome (const string& user_text);
int countWords(const string& user_text);
int countUpper(const string& user_text);
int countVowel(const string& user_text);
int countRepeated(const string& user_text);

int main()
{
string user_text;

cout<<"Enter your text: ";
getline(cin , user_text);// getting user input

cout<<"=== TEXT ANALYSIS REPORT ===\n";
cout<<"Total Characters         :"<<user_text.length()<<endl;
cout<<"Total Words              :"<<countWords(user_text)<<endl;
cout<<"Vowels                   :"<<countVowel(user_text)<<endl;
cout<<"Uppercase Letters        :"<<countUpper(user_text)<<endl;
cout<<"Most Frequent Letter     :"<<countRepeated(user_text)<<endl;
cout<<"Contains Palindrome Word :"<<endl;
checkForPalindrome(user_text);

return 0;
}

// ====================== FUNCTIONS ======================

int countWords(const string& user_text)
{
    if (user_text.empty()) return 0;

    int wordCount = 0;
    bool inWord = false;

    for(char ch : user_text)
{
    if (isspace(ch))
    {
       inWord = false;
    }
    else
    {
      if(!inWord)
       { 
        inWord = true;
        wordCount++;
       }
    }
}
return wordCount;
}

int countUpper(const string& user_text)
{
if (user_text.empty()) return 0;

int upperCase = 0;
for(char ch : user_text)
{
  
   if(isupper(ch))
    upperCase++;   
}
return upperCase;
}

int countVowel(const string& user_text)
{
//convert all letter to small and check for vowels
int vowel_counter = 0;
string vowels = "aeiou";
for(char ch : user_text)
{
char lower = tolower(ch);     
if(vowels.find(lower) != string::npos)
vowel_counter++;
}
return vowel_counter;
}


// check for most repeated letter
int countRepeated(const string& user_text)
{
int checker[26] = {0};
int maxcount =0;
char mostFreqLetter = 'a';
for(char ch : user_text)
{
if(isalpha(ch))
{
char lower = tolower(ch);
checker[lower-'a']++;
}
}
for(int i = 0; i < 26; i++)
{
    
  if(maxcount < checker[i])
{
    maxcount = checker[i];
    mostFreqLetter = 'a' + i;
}
}
 cout<<maxcount<<mostFreqLetter;
return maxcount;
}

void checkForPalindrome (const string& user_text)
{
    string word ="";
  for(char ch : user_text)
  {
    if(isspace(ch))
    {

        if(!word.empty())
        {
        process( ispalindrope(word),word);
        word ="";
        }
    }
    else
    word += ch;
  }
if(!word.empty())
{
process( ispalindrope(word),word);
}

}

bool  ispalindrope(string word)
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

void process(bool  ispalindrope, string word)
{
  
 if( ispalindrope && counter == 0) 
 {
  cout<<"yes"<<setw(10)<<word;
  counter++;
 }
 else if( ispalindrope)
 cout<<"  "<<word;
}

/* working but worse way
bool process(string word)
{
string lower;
string temp ="";
int strlength = word.length();
int i = 0;
  for(char ch : word)
  {
  lower += tolower(ch);
  }
  for(char ch : lower)
    {
      temp += lower[strlength - i];
      i++;
    }
if( lower == temp)
return 1;
else
return 0;
}
*/

