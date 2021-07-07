#include <iostream>
#include <vector>
using namespace std;

int mincost(vector<vector<int>> &q, vector<vector<int>> &arr, int row, int col){
   if(row == arr.size() || col == arr[0].size()) return INT32_MAX;
   if(row == arr.size()-1 and col == arr[0].size()-1) return arr[row][col];
   if(q[row][col] != 0) return q[row][col];
   q[row][col] = min( mincost(q,arr, row, col+1) , mincost(q,arr, row+1, col)) + arr[row][col]; // right + down   
   return q[row][col];
                        
}

int mincosttab(vector<vector<int>> &arr){
   int n= arr.size(); int m= arr[0].size();
   vector<vector<int>> q (n, vector<int>(m, INT32_MAX));
   for(int i= n-1; i>=0; i--){
      for(int j=m-1; j>=0; j--){
         if(j+1 < m && i+1 < n) q[i][j]= min(q[i+1][j], q[i][j+1]) + arr[i][j];
         else if(i+1 == n && j+1 !=m) q[i][j]= q[i][j+1] + arr[i][j];
         else if(i+1 != n && j+1 ==m) q[i][j]= q[i+1][j] + arr[i][j];
         else q[i][j]= arr[i][j];
      }
   }
   return q[0][0];
}

int main(){
   int n,m;
   cin>>n>>m;
   vector<vector<int>> arr(n,vector<int>(m,0));
   vector<vector<int>> q(n,vector<int>(n,0));
   for(int i= 0;i<n;i++){
      for(int j=0; j<m; j++){
         cin>>arr[i][j];
      }
   }

   cout<<mincost(q,arr, 0, 0)<<endl;
   // cout<<mincosttab(arr);
   
   return 0;
}