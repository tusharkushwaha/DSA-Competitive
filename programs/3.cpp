#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> findPairSum(vector<int> arr, int dif, int l)
{
   vector<vector<int>> result;
   int h = arr.size();
   while (l+1 < h-1)
   {
      if (arr[l + 1] + arr[h - 1] == dif)
      {
         result.push_back({arr[l],arr[l + 1], arr[h - 1]});
         l++;
         h--;
      }
      else if (arr[l + 1] + arr[h - 1] < dif)
      {
         l++;
      }
      else
      {
         h--;
      }
   }
   return result;
}

vector<vector<int>> findTriplet(vector<int> arr, int sum)
{
   vector<vector<int>> result;
   for (int i = 0; i < arr.size(); i++)
   {
      int dif = sum - arr[i];
      vector<vector<int>> gotPair = findPairSum(arr, dif, i);
      if (gotPair.size() != 0)
      {
         // result.push_back({arr[i], gotPair[0], gotPair[1]});
         result.insert(result.end(), gotPair.begin(), gotPair.end());
      }
   }
   return result;
}

int main()
{
   vector<int> arr{1, 2, 3, 5, 4, 6, 7, 9, 8, 15};
   sort(arr.begin(), arr.end());   
   int Sum = 18;
   auto result = findTriplet(arr, Sum);
   if (result.size() != 0)
   {
      for (int i = 0; i < result.size(); i++)
      {
         cout << "{";
         for (int j=0; j<3; j++)
         {
            cout << result[i][j] << " ";
         }
         cout << "}";
      }
   }
   else
   {
      cout << "No such triplet found";
   }
   return 0;
}
