// Remove Leaves In Generic Tree
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
bool cutleaf(node * root){
    if(root->children.size() == 0) return false;
    int n = root->children.size();
    for(int i = 0; i<n; i++){
        if(cutleaf(root->children[i]) == false) root->children[i]= nullptr;
    }
    for(int i = 0; i < root->children.size(); i++){
        if(root->children[i] == nullptr) {
          for(int j =i; j<n-1; j++) {
              root->children[j] = root->children[j+1];
            }
            i--;
            root->children.pop_back();
        }
    }
    return true;
}
void cutleaf2(node* root){
  node *child;
  for(int i = root->children.size()-1; i>=0; i--){
    child = root->child// Remove Leaves In Generic Tree
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
bool cutleaf(node * root){
    if(root->children.size() == 0) return false;
    int n = root->children.size();
    for(int i = 0; i<n; i++){
        if(cutleaf(root->children[i]) == false) root->children[i]= nullptr;
    }
    for(int i = 0; i < root->children.size(); i++){
        if(root->children[i] == nullptr) {
          for(int j =i; j<n-1; j++) {
              root->children[j] = root->children[j+1];
            }
            i--;
            root->children.pop_back();
        }
    }
    return true;
}
void cutleaf2(node* root){
  node *child;
  for(int i = root->children.size()-1; i>=0; i--){
    child = root->children[i];
    if(child->children.size()==0) root->children.erase(root->children.begin()+i);
  }
  for(auto &i: root->children) cutleaf2(i);
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
 cutleaf2(root);
 display(root);
  return 0;
}ren[i];
    if(child->children.size()==0) root->children.erase(root->children.begin()+i);
  }
  for(auto &i: root->children) cutleaf2(i);
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
 cutleaf2(root);
 display(root);
  return 0;
}