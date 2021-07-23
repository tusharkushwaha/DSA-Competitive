// Find And Nodetorootpath In Binary Tree
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
void traversal(node* root){
    string pre; string in; string post;
    stack<pr*>st; pr *temp = new pr(root); st.push(temp);
    // debug(st.top()->addr->data)
    while(st.empty() != true){
        if(st.top()->state == 1){
            pre =pre +" " +to_string(st.top()->addr->data);
            st.top()->state++;
            pr* temp = new pr(st.top()->addr->left);
            if(st.top()->addr->left != nullptr) st.push(temp);
        }
        else if(st.top()->state == 2){
            in = in + " "+ to_string(st.top()->addr->data);
            st.top()->state++;
            pr* temp = new pr(st.top()->addr->right);
            if(st.top()->addr->right != nullptr) st.push(temp);
        }
        else{
            post = post + " " + to_string(st.top()->addr->data);
            st.pop();
        }
    }
    cout<<pre<<"\n";
    cout<<in<<"\n";
    cout<<post<<"\n";
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
  traversal(root);
    
    
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