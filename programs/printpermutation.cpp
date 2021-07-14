#include <iostream>
using namespace std;

void printPermutations(string str, string ans){
    
    if(str.length()==0){
       cout<<ans<<endl;
       return;
    }
   printPermutations(str.substr(1), ans+str[0]);
   for(int i=1; i<str.length() ; i++){
      string temp = str.substr(0,i)+str.substr(i+1);
      printPermutations(temp, ans+str[i]);
   }

    

}

int main(){
    string str;
    cin>>str;
    printPermutations(str,"");
    
}