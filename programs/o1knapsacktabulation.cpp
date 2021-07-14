#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int knapsack01(vector<int> val, vector<int> wt, int cp, int n)
{
   int q[n + 1][cp + 1];
   for (int i = 0; i < n + 1; i++)
      q[i][0] = 0;
   for (int i = 0; i <= cp; i++)
      q[0][i] = 0;

   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= cp; j++)
      {
         if (j - wt[i - 1] >= 0)
            q[i][j] = max(q[i - 1][j], val[i - 1] + q[i - 1][j - wt[i - 1]]);
         else
            q[i][j] = q[i - 1][j];
      }
   }
   return q[n][cp];
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