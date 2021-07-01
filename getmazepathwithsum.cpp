#include <iostream>
#include <vector>
using namespace std;

vector<string> getMazePaths(int sr ,int sc, int dr, int dc){

   if(dr==sr) {
      return vector<string> {""};
   }
   vector<string> result ;
   for(int i =1; dc+i<=sc ; i++){
      auto temp = getMazePaths(sr,sc,dr,dc+i);
      for (auto &&j : temp)
      {
         result.push_back("h"+to_string(i)+j);
      }
      
   }
   for(int i=1; dr+i<=sr; i++){
      auto temp1 = getMazePaths(sr,sc,dr+i,dc);
      for (auto &&j : temp1)
      {
         result.push_back("v"+to_string(i)+j);
      }
      
   }
   for(int i=1; dc+1<=sc && dr+i<=sr; i++){
      auto temp2 = getMazePaths(sr,sc,dr+i,dc+i);
      for(auto &&j: temp2){
         result.push_back("d"+to_string(i)+j);
      }
   }
   return result;
}

int main(){
   auto result = getMazePaths(4,4,1,1);
   for (auto &&i : result)
   {
      cout<<i<<" ";
   }
   
   return 0;
}
