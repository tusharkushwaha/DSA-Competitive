#include <iostream>
#include <vector>
using namespace std;
#include <cstring>

void symbols(char *str){
   int spaces=0;
   for(int i=0; str[i]!= '\0'; i++){
      if(str[i] == ' ') spaces++;
   }
   int itr = strlen(str) + 2* spaces;
   str[itr--]= '\0';
   for(int i=strlen(str)-1; i>=0; i--){
      if(str[i]!= ' '){
          str[itr--]=str[i];
      }
      else{
         str[itr--] = '0';
         str[itr--] = '2';
         str[itr--] = '%';
      }
   }
   cout<<str;
}

int main(){
   char s[1000];
   cin.getline(s,10000);    
   symbols(s);
   return 0;
}