#include <iostream>
#include <vector>
using namespace std;
int maxarray(int arr[], int index){
   if(index== 0) {
      return arr[0];
   }
   return max(arr[index], maxarray(arr,index-1));
}

int main(){
   int arr[] = {10,44, -99,-999, 10000,199, 0, 3};
   int n = sizeof(arr)/sizeof(arr[0]);
   cout<<maxarray(arr, n-1);
   return 0;
}