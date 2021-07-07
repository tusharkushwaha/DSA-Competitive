#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int coinChg(int arr[], int amt, int n)
{
   if (amt == 0)
      return 1;
   if (n == 0)
      return 0;
   int times = amt / arr[n - 1] + 1;
   int count = 0;
   while (times > 0)
   {
      if (amt - (times - 1) * arr[n - 1] >= 0)
         count += coinChg(arr, amt - (times - 1) * arr[n - 1], n - 1);
      times--;
   }
   return count;
}
int tabcoin(int arr[], int amt, int n){
   int q[amt+1];
   for(int i=0; i<=amt; i++)
      q[i]=0;
   q[0]=1;
   for(int i=0;i<n;i++){
      for(int j=1; j<=amt; j++){
         if(j-arr[i]>=0 && 0 != q[j-arr[i]])
         q[j]+=q[j-arr[i]]; 
      }
   }
   return q[amt];
   
}
int main()
{
   int n;
   cin >> n;
   int arr[n];
   for (int i = 0; i < n; i++)
      cin >> arr[i];
   int amt;
   cin >> amt;
   // cout << coinChg(arr, amt, n)<<endl;
   cout<<tabcoin(arr,amt,n);
   return 0;
}