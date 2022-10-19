class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* a = head; ListNode* a2 = head;
        int sz = 1;
        while(a -> next != nullptr)
        {
            a = a->next;
            sz++;
        }
        
        for(int i = 0; i < sz - n - 1; i++)
            a2 = a2 -> next;
        if(sz - n - 1 < 0)
            head = head -> next;
        if(a2 ->next != NULL)
            a2->next = a2->next->next;
        else
            head = NULL;
        return head;
    }
};
