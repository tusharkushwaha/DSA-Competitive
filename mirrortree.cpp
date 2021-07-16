// Mirror A Generic Tree
#include <bits/stdc++.h>
using namespace std;
#define debug(a) cout<<#a<<' ';_print(a); cout<<endl;
template <class T> void _print(T a) {cout<<a;}
template <class T> void _print(vector<T>a) {cout<<'['; for(auto &i: a) cout<<i<<' '; cout<<']'; }
template<class T> void _print(vector<vector<T>>a){cout<<'[';for(auto &i:a){cout<<'{';for(auto &j:i)cout<<j<<',';cout<<'}'<<endl;}cout<<']';}

class node{
  public:
    int data; vector<node*>children;
};

void display(node *root){ 
  int n = root->children.size();
  cout<<root->data<<" -> ";
  for(int i=0; i<n; i++)cout<<root->children[i]->data<<", ";
  cout<<"."<<endl;
  for(int i=0 ; i<n; i++) display(root->children[i]);
}

void displayreverse(node *root){ 
  int n = root->children.size();
  cout<<root->data<<" -> ";
  for(int i=n-1; i>= 0; i--)cout<<root->children[i]->data<<", ";
  cout<<" ."<<endl;
  for(int i=n-1 ; i>= 0; i--) displayreverse(root->children[i]);
}
void displayrev2(node *root){
    reverse(root->children.begin(),root->children.end());
    for(auto &i: root->children){
        displayrev2(i);
    }
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
          st.top()->children.push_back(c);          
          st.push(c);
      }
      
 }
  display(root);
//   displayreverse(root);
  displayrev2(root);
    display(root);
  return 0;
}