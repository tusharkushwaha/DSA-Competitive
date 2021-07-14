#include <iostream>
#include <vector>
using namespace std;

int maxSubarraySum(vector<int>& nums) {
   int temp=0; int result=nums[0];
   int n=nums.size(); int startPositive = n;
   for(int i = 0; i<n; i++){
      if(nums[i]>0) {startPositive = i; break;}
   }
   if (startPositive == n)
   {
      for(auto &i : nums){
         result= max(result, i);
      }
      return result;
   }
   else{
      for(int i = startPositive; i<n; i++){
         if (temp<=temp+nums[i])
         {
            temp=temp+nums[i];
            if(result<temp){result = temp;}
         }
         else if(temp>temp+nums[i] and temp+nums[i]>=0){
            temp = temp+nums[i];
         }
         else{
            temp=0;
         }

      }  
      return result;
   }
   
   
}

int main(){
   vector<int> arr{2,0,3,-2};
   cout<< maxSubArray(arr);
   return 0;
}