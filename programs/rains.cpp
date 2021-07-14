#include <iostream>
using namespace std;
#include <vector>

int totalWater(vector<int>height){
   int n = height.size();  int result = 0;
   if(n<=2) return 0;
    vector<int> leftsorted (n,0); vector<int> rightsorted(n, 0);
   rightsorted[n-1]= height[n-1]; leftsorted[0]=height[0];
   for (int i = 1; i < n; i++)
   {
      leftsorted[i] = (max(height[i],leftsorted[i-1]));
      rightsorted[n-i-1]= max(height[n-i-1],rightsorted[n-i]);
   }
   for(int i=0; i<n; i++){
      result+= min(leftsorted[i],rightsorted[i])- height[i];
   }
   return result;

}

int main(){
   vector<int> a{};
   cout<<totalWater(a);
   return 0;
}