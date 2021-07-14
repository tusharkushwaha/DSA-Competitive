#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int* nxtg(int arr[], int n){
   int *result = new int [n];
   stack<int> s;
   result[n-1] = -1; s.push(arr[n-1]);
   for(int i=n-2; i>=0; i--){
      while(s.empty()==false and s.top() < arr[i]){
            s.pop();
         }
      if(s.empty() == true) {result[i] = -1;}
      else result[i] = s.top();
      s.push(arr[i]);
      
   }
   return result;
}

int main(){
   int n ;
   cin>>n;
   int arr[n];
   for(int i =0; i<n; i++)
      cin>>arr[i];
   int *result = nxtg(arr, n);
   for(int i=0; i<n;i++)
   cout<< result[i]<<endl;
   return 0;
}