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

ListNode *midNode(ListNode *head)
{
   if(head == NULL or head->next == NULL){
      return head;
   }
   ListNode* fast = head;
   while(fast->next != NULL and fast->next->next != nullptr){
      head = head->next;
      fast = fast->next->next;
   }

    return head;
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

    ListNode *head = midNode(dummy->next);
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}