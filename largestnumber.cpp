#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

string largestNumber(vector<int>& nums) {
   int n = nums.size(); long int first,last; int digits;
   for(int i=0; i<n-1; i++){
      for(int j=i+1; j<n;j++){
         digits = (int)log10(nums[j])+1;
         first=nums[i]* pow(10,digits) +nums[j];
         digits= (int)log10(nums[i])+1;
         last=nums[j]* pow(10, digits) +nums[i];
         if (first<last)
         {
            swap(nums[i],nums[j]);
         }
         
      }
   }
   string result;
   for(int i=0;i<n;i++){
      result +=to_string(nums[i]);
   }
   return result;
}
int main(){
   vector <int>nums = {1,2,3,4,5,6,7,8,9,0};
   cout<<largestNumber(nums);
   return 0;
}