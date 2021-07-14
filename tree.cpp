#include <bits/stdc++.h>
using namespace std;
#define debug(a) cout<<#a<<' ';_print(a); cout<<endl;
template <class T> void _print(T a) {cout<<a;}
template <class T> void _print(vector<T>a) {cout<<'['; for(auto &i: a) cout<<i<<' '; cout<<']'; }
template<class T> void _print(vector<vector<T>>a){cout<<'[';for(auto &i:a){cout<<'{';for(auto &j:i)cout<<j<<',';cout<<'}'<<endl;}cout<<']';}

class node{
  public:
    int data; vector<node>children;
};

int main(){
  int const arr[] = {10,20,50,-1,60,-1,-130,70,-1,80,110, -1, 120, -1, -1, 90, -1, -1, 40,100, -1, -1, -1};
  node root;
 
  return 0;
}