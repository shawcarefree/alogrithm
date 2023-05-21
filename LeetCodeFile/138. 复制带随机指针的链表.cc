struct Node* copyRandomList(struct Node* head) {
    struct Node * cur = head;
   
    while(cur)//拷贝节点，并链接在原节点的后面
    {
        struct Node * copy = (struct Node *)malloc(sizeof(struct Node));
        copy->val = cur->val;

        copy->next = cur->next;
        cur->next = copy;

        cur = cur->next->next;

    }

    cur = head;
    while(cur)//拷贝random
    {
        struct Node * copy = cur->next;

        if(cur->random == NULL)
        {
            copy->random = NULL;
        }
        else
        {
            copy->random = cur->random->next;
        }
        
        cur = cur->next->next;
    }

    cur = head; //恢复
     struct Node * copyHead = NULL;
    struct Node * copyTail = NULL;
                    
    while(cur)
    {
       
        struct Node * copy = cur->next;
        struct Node * next = copy->next;
        cur->next = next;
        if(copyTail == NULL)
        {
            copyHead = copyTail = copy;
        }
        else
        {
            copyTail->next = copy;
            copyTail = copyTail->next;
        }
        cur = next;
    }
    return copyHead;
}