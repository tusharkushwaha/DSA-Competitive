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
ListNode *middll(ListNode *head)
{
   ListNode *fast = head;
   while (fast->next != nullptr and fast->next->next != nullptr)
   {
      head = head->next;
      fast = fast->next->next;
   }
   ListNode* temp =head->next;
   head->next = nullptr;
   return temp;
}
ListNode *reversell(ListNode *head)
{
   ListNode *pre = head;
   ListNode *nxt = head->next;
   head->next = nullptr;
   ListNode *curr = nxt;
   while (curr != nullptr)
   {
      nxt = curr->next;
      curr->next = pre;
      pre = curr;
      curr = nxt;
   }
   return pre;
}
void fold(ListNode *head)
{
   if (head == nullptr or head->next == nullptr)
      return;
   ListNode *mid = middll(head);
   ListNode *rev = reversell(mid);
   ListNode *fir = head;
   ListNode *sec = rev;
   ListNode *firhlp;
   ListNode *sechlp;
   while (firhlp != nullptr and sechlp != nullptr)
   {
      firhlp = fir->next;
      sechlp = sec->next;
      fir->next = sec;
      sec->next = firhlp;
      fir = firhlp;
      sec = sechlp;
   }
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
   fold(head);
   printList(head);

   return 0;
}