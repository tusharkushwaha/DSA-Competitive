#include <iostream>
#include <vector>
using namespace std;

void printTargetSumSubsets(vector<int> nums, int sum, int pointer, int target, vector<int> path)
{

   if (pointer == nums.size())
      return;
   int temp = 0;
   temp = sum + nums[pointer];
   if (temp == target)
   {
      cout << "{";
      for (auto &i : path)
      {
         cout << i << " ";
      }
      cout << nums[pointer] << "}" << endl;
   }
   vector<int> path1 = path;

   path1.push_back(nums[pointer]);
   printTargetSumSubsets(nums, temp, pointer + 1, target, path1);
   printTargetSumSubsets(nums, sum, pointer + 1, target, path);
}

int main()
{
   vector<int> nums = {10, 20, 30, -10, 40, 50, 20, -10 , 60};
   int target = 60;
   int sum = 0;
   vector<int> path;
   printTargetSumSubsets(nums, sum, 0, target, path);
   return 0;
}