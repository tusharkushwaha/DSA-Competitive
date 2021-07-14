#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k){
   int n = nums.size();
   unordered_map<int,int> m;
   m[0]++; int cumsum=0; int count = 0;
   for(int i=0;i<n;i++){
      cumsum+= nums[i];
      count+= m[cumsum-k];
      m[cumsum]++;
   }
   return count;
}

int main(){
   vector<int> nums = {1}; int k = 0;
   cout<<subarraySum(nums, k);
   return 0;
}