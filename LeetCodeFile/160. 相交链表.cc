struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode * tailA = headA;
    struct ListNode * tailB = headB;
    struct ListNode * longList = NULL;
    struct ListNode * shortList = NULL;
    int lenA = 0;
    int lenB = 0;
    int gap = 0;
    while(tailA->next)
    {
        tailA = tailA->next;
        lenA++;
    }
    
    while(tailB->next)
    {
        tailB = tailB->next;
        lenB++;
    }
    if(tailA != tailB)
    {
        return NULL;
    }
    if(lenA > lenB)
    {
        gap = lenA-lenB;
        longList = headA;
        shortList = headB;
    }
    else
    {
        gap = lenB-lenA;
        longList = headB;
        shortList = headA;
    }
    while(gap--)
    {
        longList = longList->next;
    }
    while(longList && shortList)
    {
        if(longList == shortList)
        {
            return shortList;
        }
        longList = longList->next;
        shortList = shortList->next;
    }

    return NULL;
}
