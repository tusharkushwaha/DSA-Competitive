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

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *small; ListNode *large; ListNode* ret;
    if(l1->val > l2->val) {
        large = l1; small = l2; ret = small;
    }
    else{
        large = l2; small = l1; ret = small;
    }
    ListNode *smnxt; ListNode *larnxt;
    while(small != nullptr){
        smnxt = small->next; larnxt= large->next;
        if(smnxt->val > large->val){
            small->next = large;
           if(smnxt == nullptr or larnxt ==nullptr){
              large->next = small;
              break;
           }
            large = smnxt;
            small = larnxt;
        }
        else{
            if(smnxt != nullptr) small = smnxt; 
            else small->next = large;
        }
    }
    return ret;
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

ListNode *createList(int n)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
    }
    return dummy->next;
}

int main()
{
    int n, m;
    cin >> n ;
    ListNode *h1 = createList(n);
    cin >> m;
    ListNode *h2 = createList(m);

    ListNode *head = mergeTwoLists(h1, h2);
    printList(head);

    return 0;
}