#include <iostream>

using namespace std;
int main()
{

int i,j,k,x;
i = j = k = x = 0 ;


cout<<"enter the number: "<<endl;
cin>> x;

for(i = 1; i <= x * 3 ; ++i)
   {    
      for(j = 1 ; j <= (2*x) -1 ; ++j)
     
     
      {
        if(i <= x)
      {
       if(j >=2*x -i)
       cout<<"*";
      else 
      cout<<" ";
      }
     
     
     
      else if(i <=2*x)
      { 
            k = 0;
          if(j == x)
            {cout<<"|"; k = 1;}
          if(j<=(i - x - 1))
            {cout<<"*";k= 1;} 
          if(j >= i)
            {cout<<"*"; k = 1;}
          if(k == 0)
          cout<<" ";
        
      }
 
 
      else if(i <=3*x)
       {
         if(j <=3*x + 1 - i )
      cout<<"*"; 
      else 
      cout<<" ";
       }
 
 
 
    } 
 cout<<endl;
  }

}








