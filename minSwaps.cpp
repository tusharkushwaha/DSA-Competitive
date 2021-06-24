#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int minSwaps(vector<int>&nums){
      int n = nums.size(); int swaps = 0;
      
      vector<pair<int,int>> ap(n,{0,0});
      for(int i=0; i<n; i++){
         ap[i].first = nums[i]; ap[i].second = i;
      }
      sort(ap.begin(),ap.end());
      vector<bool> visited(n,false);
      for(int i=0;i<n;i++)
      {  
         int originalPosition = ap[i].first; 
         if(visited[i] or ap[i].second==i) continue;
         int node = i;
         int cycle=0;
         while(!visited[node]){
            visited[node] = true;
            node = ap[node].second;
            cycle+=1;
         }
         swaps+=(cycle-1);
      }
      return swaps;

	}

int main(){
   vector<int> arr{10, 19, 6, 3, 5};
   cout<<minSwaps(arr);
   return 0;
}