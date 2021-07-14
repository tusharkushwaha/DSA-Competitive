#include <iostream>
#include <vector>
using namespace std;

void printSS(string ques, string ans)
{  
   int n= ques.length();

   if(n==0){
      cout<<ans<<endl;
      return; //
   }
   string temp = ques.substr(1,n);
   printSS(temp, ans + ques[0]);
   printSS(temp, ans);

}

int main()
{
   string str = "c";
   printSS(str, "");
}