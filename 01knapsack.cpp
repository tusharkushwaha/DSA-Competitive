#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int q[5][5] = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};

int knapsack01(vector<int> value, vector<int> weight, int it, int wajan, int capacity)
{
   if (it == value.size())
      return 0;
   if (wajan + weight[it] <= capacity)
   {
      if (q[it][wajan] != -1)
      {
         return q[it][wajan];
      }

      int sum1 = knapsack01(value, weight, it + 1, wajan + weight[it], capacity);
      int sum2 = knapsack01(value, weight, it + 1, wajan, capacity);
      return q[it][wajan] = max(sum1 + value[it], sum2);
   }
   return 0;
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
   cout << knapsack01(value, weight, 0, 0, capacity);

   return 0;
}
