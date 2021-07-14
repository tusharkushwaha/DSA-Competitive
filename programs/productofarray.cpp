#include <iostream>
#include <vector>
using namespace std;

vector<int> productArray(vector<int>& nums) {
   int frontproduct=1; int endProduct=1;  int n = nums.size();
   vector<int> result(n,1);
   for(int i=0; i<n; i++){
      result[i] *= frontproduct;
      frontproduct *= nums[i];
      result[n-i-1] *= endProduct;
      endProduct *= nums[n-i-1];
   }
   return result;

}

int main(){
   vector<int> nums{-1,1,0,-3,3};
   auto p =  productExceptSelf(nums);
   for (auto &&i : p)
   {
      cout<< i<< " ";
   }
   
   return 0;
}