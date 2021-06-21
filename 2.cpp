#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>

bool binarysearch(vector<int> arr, int l, int h, int key)
{
   if (l == h)
   {
      if (arr[l] == key)
         return true;
      else
         return false;
   }
   else
   {
      int mid = (l + h) / 2;
      if (key == arr[mid])
         return true;
      else if (key < arr[mid])
         return binarysearch(arr, 0, mid, key);
      else
         return binarysearch(arr, mid + 1, h, key);
   }
}

vector<int> pairsum(vector<int> arr, int sum)
{
   int l = 0;
   int h = arr.size() - 1;
   for (auto &&i : arr)
   {
      int otherno = sum - i;
      if (binarysearch(arr, l, h, otherno))
      {
         return {i, otherno};
      }
   }
   return {};
}

int main()
{
   vector<int> arr{10, 5, 2, 3, -6, 9, 11};
   sort(arr.begin(), arr.end());
   int sum = 4;
   auto p = pairsum(arr, sum);
   cout<<p[0]<<","<<p[1];
   return 0;
}