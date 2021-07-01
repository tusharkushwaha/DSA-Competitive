#include <iostream>
#include <vector>
using namespace std;

vector<string> gss(string s){
   int n = s.length();
   if(n==1) {
      string temp;
      temp+=s[0];
      vector<string> base{"", temp};
      return base ;      
   }
   string substr = s.substr(1,n);
   vector<string> previouss = gss(substr);
   // cout<<previouss.size()<<endl;
   vector<string> next;
   for (auto &&i : previouss)
   {
      next.push_back(i);
      next.push_back(s[0]+i);
   }


   

   // for (auto &k : previouss)  
   // {  
   //    string temp = s.substr(0,1).append(k);
   //    cout<<k<<endl;
   //    previouss.push_back(temp);
   // }
   return next;
       
}
int main(){
   string s= "abffffffgghghffffggfcl";   
   auto result= gss(s);
   for(auto &i :  result){
      cout<<i<<endl;
   }
   return 0;
}