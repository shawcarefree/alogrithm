struct ListNode *detectCycle(struct ListNode *head) {
     struct ListNode *fast = head;
     struct ListNode *slow = head;
     while(fast && fast->next)
     {
         slow = slow->next;
         fast = fast->next->next;
         if(slow == fast)
         {
             struct ListNode *meet = fast;
             while(meet != head)
             {
                 meet = meet->next;
                 head = head->next;
             }
             return meet;
         }
     }
     return NULL;
}