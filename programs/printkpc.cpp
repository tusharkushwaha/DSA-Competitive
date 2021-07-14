#include <iostream>
#include <vector>
using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void printKPC(string ques, string ans){

   if(ques.length()==0){
      cout<<ans<<endl;
      return;
   }
   string temp = codes[ques[0]-'0'];   
   for(int i=0; i<temp.length();i++){
      printKPC(ques.substr(1), ans+ temp[i]);
   }
    
}

int main(){
    string str = "74";
    printKPC(str, "");
}