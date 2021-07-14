#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int knapsack01(vector<int> val, vector<int> wt, int cp, int n){
   int q[cp+1];
   q[0]=0;
   for(int i=1; i<=cp; i++){
      q[i]=q[i-1];
      for(int j=0; j<n;j++){
         if(i-wt[j]>=0)
            q[i]= max(q[i], val[j] + q[i-wt[j]]);
         
      }
   }
   return q[cp];
}

int main()
{
   int n;
   cin >> n;
   vector<int> value(n, 0);
   vector<int> weight(n, 0);
   for (int i = 0; i < n; i++)
   {
      cin >> value[i];
   }
   for (int i = 0; i < n; i++)
   {
      cin >> weight[i];
   }
   int capacity;
   cin >> capacity;
   cout << knapsack01(value, weight, capacity, n);

   return 0;
}