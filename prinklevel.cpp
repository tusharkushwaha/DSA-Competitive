#include <bits/stdc++.h>
using namespace std;
#define debug(a) cout<<#a<<' ';_print(a); cout<<endl;
template <class T> void _print(T a) {cout<<a;}
template <class T> void _print(vector<T>a) {cout<<'['; for(auto &i: a) cout<<i<<' '; cout<<']'; }
template<class T> void _print(vector<vector<T>>a){cout<<'[';for(auto &i:a){cout<<'{';for(auto &j:i)cout<<j<<',';cout<<'}'<<endl;}cout<<']';}

class Node{
  public: int data; Node* left; Node *right;
    Node(int data, Node* left, Node* right){ this->data = data; this->left = left; this->right = right; }
    Node(int data):data(data),left(nullptr), right(nullptr){}
};
class pr{
  public: Node* addr; int state;
    pr(Node* add):state(1),addr(add){}
    
};
vector<int> Kdistance( Node *root, int k)
{
vector<int>v;
if(k==0){
    v.push_back(root->data);
    return v;
}
  queue<Node*> q; q.push(root); q.push(nullptr);
  while(q.empty() != true){
      if(q.front() != nullptr){
          if(q.front()->left != nullptr and q.front()->right != nullptr) {q.push(q.front()->left); q.push(q.front()->right);}
          else if(q.front()->left != nullptr) q.push(q.front()->left);
          else if(q.front()->right != nullptr) q.push(q.front()->right);
          q.pop();
      }
      else{
          q.pop();
          if(q.empty() != true) q.push(nullptr);
      
          if(k==1){
              q.push(nullptr);
              while(q.front() != nullptr){
                 v.push_back(q.front()->data) ; q.pop();
              }
              break;
          }
          k--;
      }
  }
  // cout<<1;
  return v;
}
void maketree( vector<int>arr, int n){
  stack<pr*>st; Node* root = new Node(arr[0]); pr *rootp = new pr(root);
   st.push(rootp); int i=1;
  while(st.empty() != true and i<n){
    if(arr[i] != -1){
      if(st.top()->state !=3){
        Node *temp = new Node(arr[i]); pr *next = new pr(temp);
        if(st.top()->state ==1 ) st.top()->addr->left = temp;
        else st.top()->addr->right = temp;
        st.top()->state++;
        st.push(next);
      }
      else{
          st.pop(); continue;
      }
    }
    else{
        if(st.top()->state ==3){
            st.pop(); continue;
        }
        else st.top()->state++;
        
    }
    i++;
  } 
    vector<int>v;
    int given; cin>>given;
    auto p = Kdistance(root, given);
    for(auto &i: p) cout<<i<<" ";
    
    
}
int main(){
  int n;
  cin>>n; vector<int>arr;
  string s; cin.ignore();
  getline(cin,s);
  stringstream ss(s); string token;
  while(getline(ss,token,' ')){
    if(token[0] != 'n') arr.push_back(stoi(token));
    else arr.push_back(-1);
  }

  maketree(arr,n);
  return 0;
}