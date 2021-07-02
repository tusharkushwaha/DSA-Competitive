void floodfill(vector<vector<int>> maze, int sr, int sc, string ans, vector<vector<int>> visited)
// {
//    if (sr < 0 || sc < 0 || sr >= maze.size() || sc >= maze[0].size() || ans.length()>= maze.size() * maze[0].size())
//       return;
//    if (maze[sr][sc] == 1)
//       return;
//    if (sr == maze.size() - 1 && sc == maze[0].size() - 1)
//    {
//       cout << ans << endl;
//       return;
//    }

//    if(ans.back() != 'b') floodfill(maze, sr - 1, sc, ans + "t");
//    if(ans.back() != 'l') floodfill(maze, sr, sc + 1, ans + "r");
//    if(ans.back() != 't') floodfill(maze, sr + 1, sc, ans + "b");
//    if(ans.back() != 'r') floodfill(maze, sr, sc - 1, ans + "l");
// }