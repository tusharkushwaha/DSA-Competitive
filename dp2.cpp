#include <iostream>
#include <vector>
using namespace std;

int mincost(vector<vector<int>> &q, vector<vector<int>> &arr, int row, int col){
   if(row == arr.size() || col == arr[0].size()) return 0;
   if(row == arr.size()-1 and col == arr[0].size()-1) return arr[row][col];
   if(q[row][col] != 0) return q[row][col];
   cout<<"print -->"<<row<<col<<endl;
   q[row][col] = mincost(q,arr, row, col+1) + mincost(q,arr, row+1, col) + arr[row][col]; // right + down   
   return q[row][col];
                        
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
   // for(int i= 0;i<n;i++){
   //    for(int j=0; j<m; j++){
   //       cout<<q[i][j]<<endl;
   //    }
   // }

   cout<<mincost(q,arr, 0, 0);
   
   return 0;
}