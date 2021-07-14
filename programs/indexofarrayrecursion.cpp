#include <iostream>
#include <vector>
using namespace std;

int firstIndex(int arr[], int n, int x){
    if(n==0){
       if(x==arr[0]) return 0;
       return -1;
    }
    if(x== arr[n]){
       return n;
    }
    return firstIndex(arr, n-1, x);
    
}

int main(){
   int arr[] {34,34,56,78,999,-3,0,12,1, 34,34};
   int n= sizeof(arr)/sizeof(arr[0]);
   cout<<firstIndex(arr, n-1, 34);
   return 0;
}



