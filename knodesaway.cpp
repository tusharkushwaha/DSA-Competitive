#include <bits/stdc++.h>
using namespace std;
#define debug(a) cout<<#a<<' ';_print(a); cout<<endl;template <class T> void _print(T a) {cout<<a;};template <class T> void _print(vector<T>a) {cout<<'['; for(auto &i: a) cout<<i<<' '; cout<<']'; };template<class T> void _print(vector<vector<T>>a){cout<<'[';for(auto &i:a){cout<<'{';for(auto &j:i)cout<<j<<',';cout<<'}'<<endl;}cout<<']';};

class node{
  public: int data; node* left; node *right;
    node(int data, node* left, node* right){ this->data = data; this->left = left; this->right = right; }
    node(int data):data(data),left(nullptr), right(nullptr){}
};
class pr{
  public: node* addr; int state;
    pr(node* add):state(1),addr(add){}
    
};
void printnodes(node* root, int k, int bachav){
  if(root == nullptr or k<0 or root->data == bachav) return;
  if(k==0) cout<<root->data<<" ";
  printnodes(root->left, k-1, bachav);
  printnodes(root->right, k-1, bachav);
}
vector<int> ppath(node* root, int data, vector<int>v){
    // vector<node*>v;
    if(root == nullptr) return v;
    if(root->data == data) {
        v.push_back(data);
        return v;
    }
    v.push_back(root->data);
    auto p = ppath(root->left, data,v);
    if(p.back() == data) return p;
    auto p1 =  ppath(root->right, data, v);
    if(p.back() == data ) return p1;
}
void maketree( vector<int>arr, int n){
  stack<pr*>st; node* root = new node(arr[0]); pr *rootp = new pr(root);
   st.push(rootp); int i=1;
  while(st.empty() != true and i<n){
    if(arr[i] != -1){
      if(st.top()->state !=3){
        node *temp = new node(arr[i]); pr *next = new pr(temp);
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
  int data; cin>>data;
  vector<int> v;
  auto p = ppath(root, data, v);
  reverse(p.begin(), p.end());
  // debug(p);
  int k; cin>>k;
  int n1 = p.size();
  for(int i= 0 ; i<n1; i++){
    printnodes(p[i], k-i ,(i==0 )? -1 : p[i-1]);      
    if(k-i<0) break;
  }
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