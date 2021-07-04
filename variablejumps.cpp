#include <iostream>
using namespace std;
#include <vector>

int cs(int arr[], int n, vector<int> qb)
{
   if (n < 0)
      return 0;
   if (n == 0)
      return 1;
   if (qb[n - 1] != 0)
      return qb[n - 1];
   for (int i = 1; i <= arr[n - 1]; i++)
   {
      qb[n - 1] += cs(arr, n - i, qb);
   }
   return qb[n - 1];
}

int tabulationcs(int arr[], int n)
{
   int q[n + 1];
   for(int i =0; i<n+1; i++){
      q[i]=0;
   }
   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= arr[i-1]; j++)
      {
         q[i] += q[i - j];
         if (i - j == 0){
            q[i]++;
            break;
         }
            
      }
   }
   return q[n];
}

int main()
{
   int n = 3;
   int arr[] = {0, 2, 3};
   vector<int> qb(n, 0);

   // cout << cs(arr, n, qb) << endl;
   cout << tabulationcs(arr, n) << endl;
   return 0;
}