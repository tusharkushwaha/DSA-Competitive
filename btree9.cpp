#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
#define debug(a) cout<<#a<<' ';_print(a); cout<<endl;
template <class T> void _print(T a) {cout<<a;}
template <class T> void _print(vector<T>a) {cout<<'['; for(auto &i: a) cout<<i<<' '; cout<<']'; }
template<class T> void _print(vector<vector<T>>a){cout<<'[';for(auto &i:a){cout<<'{';for(auto &j:i)cout<<j<<',';cout<<'}'<<endl;}cout<<']';}

class node{
  public: int data; node* left; node *right;
    node(int data, node* left, node* right){ this->data = data; this->left = left; this->right = right; }
    node(int data):data(data),left(nullptr), right(nullptr){}
};
class pr{
  public: node* addr; int state;
    pr(node* add):state(1),addr(add){}    
};
void clonel(node *root){
  if(root == nullptr) return;
  node *temp = new node(root->data);
  temp->left = root->left;
  clonel(root->left); clonel(root->right);
  root->left = temp;  
}
void displaytree(node* root){
  if(root == nullptr) return;
  if(root->left != nullptr and root->right != nullptr) cout<<root->data<<"-->"<<root->left->data<<", "<<root->right->data<<"\n";
  else if(root->left != nullptr) cout<<root->data<<"-->"<<root->left->data<<"\n";
  else if(root->right != nullptr) cout<<root->data<<"-->"<<root->right->data<<"\n";
  else cout<<root->data<<"\n";
  displaytree(root->left);
  displaytree(root->right);

}
void task(node* root){
  clonel(root);
  displaytree(root);
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
  task(root);
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