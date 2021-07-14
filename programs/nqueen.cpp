#include <iostream>
#include <vector>
using namespace std;

bool isqueensafe(vector<vector<int>> chess, int row, int col)
{

   //vertical testing
   for (int i = row - 1; i >= 0; i--)
   {
      if (chess[i][col])
         return false;
   }

   for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; j--, i--)
   {
      if (chess[i][j] == 1)
         return false;
   }
   for (int i = row - 1, j = col + 1; i >= 0, j < chess.size(); i--, j++)
   {
      if (chess[i][j] == 1)
         return false;
   }

   return true;
}
void nqueen(vector<vector<int>> chess, int row, string ans)
{

   if (row == chess.size())
   {
      cout << ans << endl;
      return;
   }

   for (int col = 0; col < chess.size(); col++)
   {
      chess[row][col] = 1;
      cout << isqueensafe(chess, row + 1, col) << endl;
      if (0)
         nqueen(chess, row + 1, ans + to_string(row) + to_string(col) + " ");
      chess[row][col] = 0;
   }
}

int main()
{
   int n = 4;
   vector<vector<int>> chess(n, vector<int>(n, 0));
   nqueen(chess, 0, "");
   return 0;
}