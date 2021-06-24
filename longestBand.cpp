#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>

int largestBand(vector<int> nums)
{
   int n = nums.size();
   int result  = 0;
   int count = 0;
   unordered_set<int> s;
   for (auto &&i : nums)
   {
      s.insert(i);
   }
   for (auto &i : nums)
   {
      if (s.count(i - 1) != 0)
      {
         continue;
      }
      count++;
      while (true)
      {
         if (s.count(i + count) != 0)
         {
            count++;
            continue;
         }
         break;
      }
      if (result < count)
         result = count;
      count = 0;
   }
   return result;
}

int main()
{
   vector<int> a{1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};
   cout << "The Largest Band is: " << largestBand(a) << endl;
   return 0;
}