#include <iostream>
#include <vector>
using namespace std;
bool isSubsequence(string t, string s) {
   int n = s.size(); int j=0; int m = t.size();
   if(m==0) return true;
   for(int i=0; i<n; i++){
      if(s[i]==t[j]){
         j++;
      }
      if(j==m) return true;
   }
   return false;
}
int main(){
   string s = "";
   string t = "";
   cout<< isSubsequence(s, t);
   return 0;
}