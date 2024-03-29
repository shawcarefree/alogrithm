struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* fast =head;
    struct ListNode* slow =head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}