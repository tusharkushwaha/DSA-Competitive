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
  stack <node*> s1, s2; 
    s1.push(root); cout<<root->data<<endl;
    while(s1.empty() != true or s2.empty()!=true ){
        if(s1.empty() != true){B
            while(s1.empty() != true){
                int n = s1.top()->children.size();
                for(int i = n-1; i>=0; i--) {
                    cout<<s1.top()->children[i]->data<<" ";
                    s2.push(s1.top()->children[i]);
                }
                s1.pop();
            }    
        }else{
            while(s2.empty()!= true){
                for(auto &i: s2.top()->children){
                    cout<<i->data<<" ";
                    s1.push(i);
                }
                s2.pop();
            }
        }
        cout<<endl;
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
  //debug(display(root))
  display(root);
  
  return 0;
}