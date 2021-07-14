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

ListNode *reverse(ListNode *head)
{   
    ListNode * nxt;
    nxt = head->next;
    head->next = NULL;
    ListNode *temp;
    while(nxt != NULL){
        temp = nxt->next;
        nxt->next = head;
        head = nxt;
        nxt = temp;
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

    ListNode *head = reverse(dummy->next);
    while (head != nullptr){
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}


