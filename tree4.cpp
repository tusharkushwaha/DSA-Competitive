// Linearize A Generic Tree
#include <bits/stdc++.h>
using namespace std;
#define debug(a) cout<<#a<<' ';_print(a); cout<<endl;
template <class T> void _print(T a) {cout<<a;}
template <class T> void _print(vector<T>a) {cout<<'['; for(auto &i: a) cout<<i<<' '; cout<<']'; }
template<class T> void _print(vector<vector<T>>a){cout<<'[';for(auto &i:a){cout<<'{';for(auto &j:i)cout<<j<<',';cout<<'}'<<endl;}cout<<']';}

class node{
  public:
    int data; vector<node*>chl;
};

void display(node *root){ 
  int n = root->chl.size();
  cout<<root->data<<" -> ";
  for(int i=0; i<n; i++)cout<<root->chl[i]->data<<", ";
  cout<<"."<<endl;
  for(int i=0 ; i<n; i++) display(root->chl[i]);
}
node* getLinear(node* root){
    int n = root->chl.size();
    if(n==0) return root;
    for(int i=0; i<n-1; i++ ){
        getLinear(root->chl[i])->chl = {root->chl[i+1]};
    }
    node* temp =getLinear(root->chl[n-1]);
    while(n-- > 1){
      root->chl.pop_back();
    }
    return temp;
}
int main(){
	int n;
	cin>>n;
  int  arr[n];
  for(int i =0 ;i<n;i++) cin>>arr[i];
  node *root = new node(); root->data = arr[0]; 
  stack<node*> st; st.push(root);
  for(int i=1; i<n ;i++){
      if(arr[i] == -1) st.pop();
      else{
          node *c = new node();
          c->data = arr[i];
          st.top()->chl.push_back(c);          
          st.push(c);
      }
      
 }
  getLinear(root);
  display(root);
  return 0;
}