class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carray = 0;
        int n1 = 0;
        int n2 = 0;
        int n = 0;
        auto c1 = l1;
        auto c2 = l2;

        ListNode* node = nullptr;
        ListNode* prev = nullptr;

        while(c1  != nullptr || c2 != nullptr)
        {
            n1 = c1 != nullptr ? c1->val : 0;
            n2 = c2 != nullptr ? c2->val : 0;
            n = n1 + n2 + carray;

            prev = node;
            node = new ListNode(n % 10);
            node->next = prev;
            carray = n / 10;
            c1 = c1 != nullptr ? c1->next : nullptr;
            c2 = c2 != nullptr ? c2->next : nullptr;
        }

        if(carray == 1)
        {
            prev = node;
            node = new ListNode(1);
            node->next = prev;
        }

        return reverseList(node);
    }
private:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode*  next= nullptr;

        while(head != nullptr)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }
};