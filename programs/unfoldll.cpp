#include <iostream>
using namespace std;

class ListNode
{
public:
   int val = 0;
   ListNode *next = nullptr;

   ListNode(int val)
   {
      this->val = val;
   }
};

void unfold(ListNode *head){
   int t = 1;
   ListNode* node = head;
   ListNode *nxt;
   ListNode *temp = node->next->next;
   while (node->next != nullptr)
   {
      nxt = node->next;
      if (t % 2 == 1)
      {
         node->next = temp;
      }
      else
      {
         if (t == 2)
            node->next == nullptr;
         if (nxt->next != nullptr and nxt->next->next != nullptr){
            temp = nxt->next->next;
            nxt->next->next->next = node;
         }
         else if(nxt->next != nullptr){
            temp = nxt->next;
         }
         else if(nxt->next== nullptr){
            node->next = nxt;
         }
      }
      t++;
      node = nxt;
   }
}

void printList(ListNode *node)
{
   ListNode *curr = node;
   while (curr != nullptr)
   {
      cout << curr->val << " ";
      curr = curr->next;
   }
   cout << endl;
}

int main()
{
   int n;
   cin >> n;
   ListNode *dummy = new ListNode(-1);
   ListNode *prev = dummy;
   while (n-- > 0)
   {
      int val;
      cin >> val;
      prev->next = new ListNode(val);
      prev = prev->next;
   }

   ListNode *head = dummy->next;
   unfold(head);
   printList(head);

   return 0;
}