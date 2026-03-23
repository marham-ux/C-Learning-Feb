#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
  string password;
  cout<<"  "<<endl;
  getline(cin,password);// geting string

   int length =password.length();//getting length
  
  bool hasUpper = false;
  bool hasLower = false;
  bool hasDigit = false;
  bool hasSpecial = false;
  bool hasLetter = false;
      for(int i =0; i < length ; i++)
        {
         if(isupper(password[i]))     
        {hasUpper = true;} 
         else if(islower(password[i]))
         {hasLower = true;} 
         else if(isdigit(password[i]))
        {hasDigit = true;}
        else if(password[i]== ' ')
        {
            cout<<"space";
        }
        else
           hasSpecial = true;
        }
if(hasUpper || hasLower )
{hasLetter = true;}

if(length < 8)
   {
   cout<< "weak password as  it is short";
   }
else if(!hasLetter || !hasDigit)
{
    cout<<"weak as only one type";
}
else if(length>=8 && length <= 11 )
{
 cout<<"half weak password";
}
else if(length > 11 && hasUpper && hasDigit && hasLower && hasSpecial)
{
    cout<<"very strong";
}
else if(length > 11 && hasUpper && hasDigit && hasLower) 
{
    cout<<"strong";
}
else if(length > 11 && hasUpper && hasDigit)
{
    cout<< "medium";
}


return 0;


}