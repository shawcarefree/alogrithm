class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    ListNode* cur = head;
	if (cur == NULL || cur->next == NULL)
	{
		return head;
	}

	ListNode* prev = NULL;
	ListNode* next = cur->next;

	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;

		cur = next;
	}

    head = prev;
	return head;
    }
};