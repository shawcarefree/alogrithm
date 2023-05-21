struct ListNode* removeZeroSumSublists(struct ListNode *head)
{
    //哨兵
    struct ListNode* prev = (struct ListNode*)malloc(sizeof(struct ListNode));
    prev->next = head;

    struct ListNode* cur = prev;
    while (cur != NULL)
    {
        int sum = 0;
        struct ListNode* next = cur->next;
        while (next)
        {
            sum += next->val;
            if (sum == 0)
            {
                cur->next = next->next;
                //释放被删除的节点
                struct ListNode *del = cur->next;
                while(del != next->next)
                {
                    struct ListNode *tmp = del;
                    del = del->next;
                    free(tmp);
                }
            }

            next = next->next;
        }

        cur = cur->next;
    }

    head = prev->next;

    free(prev);

    return head;
}