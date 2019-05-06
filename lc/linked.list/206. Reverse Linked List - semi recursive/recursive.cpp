class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        auto newhead = reverseList(head->next);
        auto newtail = head->next;
        newtail->next = head;
        head->next = NULL;
        return newhead;
    }
};
