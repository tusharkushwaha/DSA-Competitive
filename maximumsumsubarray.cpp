#include <iostream>
#include <vector>
using namespace std;

int maximumSumSubarray(int K, vector<int> &Arr , int N){
   int max=0; int i=0; int j=0; 
   while(j-i+1<=K){
      max+= Arr[j];
      j++;
   }
   int temp=max;
   for(i,j; j<N; j++){
      temp = max-Arr[i]+Arr[j];
      if(temp>max) max=temp;
      i++;
      
   }
   return max;
}

int main(){
   int N = 4; int K = 2;
   vector <int>Arr = {100, 200, 300, 400};
   cout<< maximumSumSubarray(K, Arr, N);
   return 0;
}