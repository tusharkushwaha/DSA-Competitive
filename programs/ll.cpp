#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node{
   public:
      int data;
      Node *next;
};

void traversell(Node* node){
   while(node != NULL){
      cout<<node->data<<endl;
      node = node->next;
   }
}
void addlast(int data, Node* &ref){
   Node * temp = new Node();
   ref = temp;
   temp->data = data;
   temp->next = NULL;
   cout<<temp->data<<endl;   
}
int main(){
   string s;
   getline(cin,s);
   Node* head = NULL;
   int n=0;
   while(s != "quit"){
      if(s.find("addLast")== 0){
         addlast(stoi(s.substr(8)), head);
         n++;
      }
      getline(cin,s);
   }
   cout<<n<<endl;
   if(head != NULL) cout<<head->data;

   return 0;
}