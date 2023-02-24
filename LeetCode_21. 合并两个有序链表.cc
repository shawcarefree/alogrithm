struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if(list1 == NULL)
    {
        return list2;
    }
    if(list2 == NULL)
    {
        return list1;
    }
       struct ListNode* head = NULL;
       struct ListNode* tail = NULL;
       while(list1 && list2)
       {
           if(list1->val < list2->val)
           {
               if(head == NULL)
               {
                   head = tail = list1;
               }
               else
               {
                   tail->next = list1;
                   tail = list1;
               }
               list1 = list1->next;
           }
           else
           {
               if(head == NULL)
               {
                   head = tail = list2;
               }
               else
               {
                   tail->next = list2;
                   tail = list2;
               }
               list2 = list2->next;
           }
       }
       if(list1)
       {
           tail->next = list1;
       }
       if(list2)
       {
           tail->next = list2;
       }

       return head;
}