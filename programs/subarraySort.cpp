#include <iostream>
using namespace std;
#include <vector>

vector<int> subarray(vector<int>a){
   int n =a.size(); int largest=-1; int lowest=-1; int l=0; int h=0; int templ=1; int temph=1; 
   for(int i=0; i<n-1; i++){
      if(a[i+1]<a[i]){
         if(largest<a[i]) largest=a[i];
         if(lowest==-1 || lowest>a[i+1]) lowest=a[i+1];
      }
   }
   if (largest==-1 & lowest==-1) return {-1,-1};
  
   
   for (int i = 0; i < n; i++)
   {
      if(lowest<a[i] && templ) {l=i; templ=0;}
      if(largest>a[n-i-1] && temph) {h=n-i-1; temph=0;}
   }
   return {l,h};
}

int main(){
   vector<int> a {5,8,13,15,9,10,11,12,14,16};
   auto result = subarray(a);
   cout<<"{"<<result[0]<<", "<<result[1]<<"}";
   return 0;
}