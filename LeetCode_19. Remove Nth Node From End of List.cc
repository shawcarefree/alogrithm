class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto cur = head;
        ListNode* pre = nullptr;

        //保持两个指针相对距离为n
        while(cur != nullptr)
        {
            n--;
            if(n == -1) pre = head;
            if(n < -1) pre = pre->next;

            cur = cur->next;
        }


        if(n > 0) return head;

        if(pre == nullptr)//删除头结点
        {
            cur = head->next;
            delete head;
            return cur;
        }
         

        //删除倒数第n个节点
        cur = pre->next->next;
        delete pre->next;
        pre->next = cur;
	return head;
    }
};