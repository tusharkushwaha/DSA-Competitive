#include <iostream>

#include <vector>

using namespace std;

void floodfill(vector<vector<int>> maze, int sr, int sc, string ans, vector<vector<bool>> visited)
{  
   
   
   if (sr < 0 || sc < 0 || sr >= maze.size() || sc >= maze[0].size() || ans.length() >= maze.size() * maze[0].size())
      return;
   if (maze[sr][sc] == 1)
      return;
   if (sr == maze.size() - 1 && sc == maze[0].size() - 1)
   {
      cout << ans << endl;
      return;
   }
   if (sr-1>=0 && visited[sr - 1][sc] != true)
   {
      visited[sr - 1][sc] = true;
      floodfill(maze, sr - 1, sc, ans + "t", visited);
   }
   if (sc + 1 <=maze[0].size()-1 && visited[sr][sc + 1] != true)
   {
      visited[sr][sc + 1] = true;
      floodfill(maze, sr, sc + 1, ans + "r", visited);
   }
   if (sr + 1 < maze.size() && visited[sr + 1][sc] != true)
   {
      visited[sr + 1][sc] = true;
      floodfill(maze, sr + 1, sc, ans + "b", visited);
   }
   if (sc + 1 < maze[0].size() && visited[sr][sc + 1] != true)
   {
      visited[sr][sc + 1] = true;
      floodfill(maze, sr, sc - 1, ans + "l", visited);
   }
}
int main()
{

   int n, m;
   cin >> n >> m;
   vector<vector<int>> arr(n, vector<int>(m));
   vector<vector<bool>> visited(n, vector<bool>(m, false));

   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
         cin >> arr[i][j];
   }
   floodfill(arr, 0, 0, "", visited);
}
