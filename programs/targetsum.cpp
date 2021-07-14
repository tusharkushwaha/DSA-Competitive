#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> q(100, vector<int>(100, INT32_MAX));
bool targetsum(vector<int> arr, int tar, int n)
{
   if (tar == 0)
      return true;
   if (n < 0)
   {
      return false;
   }

   if (q[n][tar] != INT32_MAX)
   {
      return q[n][tar];
   }
   if (tar - arr[n] < 0)
   {
      q[n][tar] = targetsum(arr, tar, n - 1);
      // cout<< n<<", "<<tar<<" --->"<<q[n][tar]<<endl;
      return q[n][tar];
   }
   else
   {
      return q[n][tar] = targetsum(arr, tar, n - 1) || targetsum(arr, tar - arr[n], n - 1);
   }
}

bool tabtar(int n, vector<int> arr, int tar)
{
   int qb[n + 1][tar + 1];
   for (int i = 0; i <= n; i++)
      qb[i][0] = 1;
   for (int i = 1; i <= tar; i++)
      qb[0][i] = 0;
   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= tar; j++){
         if(j<arr[i-1]) qb[i][j]= qb[i-1][j];
         else qb[i][j]= qb[i-1][j] || qb[i-1][j-arr[i-1]];
      }
   }
   return qb[n][tar];
}

int main()
{
   int n;
   cin >> n;
   vector<int> arr(n, 0);
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }
   int tar;
   cin >> tar;

   if (targetsum(arr, tar, n - 1))
      cout << "true"<<endl;
   else
      cout << "false"<<endl;
   if (tabtar(n, arr, tar))
      cout << "true";
   else
      cout << "false";

   return 0;
}
