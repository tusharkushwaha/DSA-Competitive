#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int memoGoldmine(int row, int col,vector<vector<int>> arr){
   
}

int main(){
   int row,col;
   cin>>row>>col;
   vector<vector<int>> arr(row, vector<int>(col,0));
   for(int i = 0; i< row; i++){
      for(int j=0; j<col; j++){
         cin>> arr[i][j] ;
      }
   }
   vector<vector<int>> q(row,vector<int>(0,col));
   memoGoldmine(row, col,arr);
   return 0;
}