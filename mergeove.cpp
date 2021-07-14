#include <bits/stdc++.h>
using namespace std;

#define debug(a) cout<<#a<<' ';_print(a); cout<<endl;
template <class T> void _print(T a) {cout<<a;}
template <class T> void _print(vector<T>a) {cout<<'['; for(auto &i: a) cout<<i<<' '; cout<<']'; }
template<class T> void _print(vector<vector<T>>a){cout<<'[';for(auto &i:a){cout<<'{';for(auto &j:i)cout<<j<<',';cout<<'}'<<endl;}cout<<']';}

class Solution
{
public:
  vector<vector<int>> merge(vector<vector<int>> &arr)
  {
    int n = arr.size();
    vector<vector<int>> result;
    if(n==1) return arr;
    sort(arr.begin(), arr.end());
    stack<int>;
    // debug(arr)
    // for (int i = 0; i < n - 1; i++)
    // {
    //   if (i == n - 2)
    //   {
    //     if (arr[i][1] >= arr[i + 1][0])
    //     {
    //       if (arr[i][1] <= arr[i + 1][1])
    //       {
    //         // arr[i + 1][0] = arr[i][0];
    //         result.push_back({arr[i][0], arr[i+1][1]});
    //       }
    //       else
    //       {
    //         // arr[i + 1][0] = arr[i][0];
    //         // arr[i + 1][1] = arr[i][1];
    //         result.push_back({arr[i][0], arr[i][1]});
    //       }
    //     }
    //     else{
    //       result.push_back(arr[i]);
    //       result.push_back(arr[i+1]);

    //     }
    //     break;
    //   }
    //   if (arr[i][0] <= arr[i + 1][0])
    //   {
    //     if (arr[i][1] <= arr[i + 1][1])
    //     {
    //       arr[i + 1][0] = arr[i][0];
    //     }
    //     else
    //     {
    //       arr[i + 1][0] = arr[i][0];
    //       arr[i + 1][1] = arr[i][1];
    //     }
    //   }
    //   else
    //     result.push_back(arr[i]);
    // }
    return result;
  }
};
int main(){
  vector<vector<int>> arr {{4,6}, {1,7}, {9,16}, {4,8}};
  // Solution s;
  // cout<<arr;
  // auto p = s.merge(arr);
  sort(arr.begin(), arr.end());
  debug(arr)
  return 0;
}