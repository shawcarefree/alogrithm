class Solution {
public:  
/*
	1.确认从当前结点跳K次后的位置
	2.L - R 位置逆序
*/
ListNode* get_TheK_endPosition(ListNode* start, int k)
{
	while (--k != 0 && start != nullptr)
	{
		start = start->next;
	}
	
	//返回跳K个节点后的位置
	return start;
}

void reverseLtoR(ListNode* begin, ListNode* end)
{
	//
	end = end->next;

	ListNode* prev = nullptr;
	ListNode* cur = begin;
	ListNode* next = nullptr;

	while (cur != end)
	{
		//反转
		next = cur->next;
		cur->next = prev;
		prev = cur;

		cur = next;
	}
	
	//使得链表完整
	begin->next = end;
}
    
    
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* start = head;
	ListNode* end = get_TheK_endPosition(start, k);

	if (end == nullptr)
	{
		//如果第一组根本不满足有K个节点，则返回
		return head;
	}
	
	head = end;

	//反转start - end
	reverseLtoR(start, end);
	
	//上一组的结尾节点
	ListNode* lastEnd = start;

	
	while (lastEnd->next != nullptr)
	{
		start = lastEnd->next;
		end = get_TheK_endPosition(start, k);
		
		if (end == nullptr)
		{
			return head;
		}

		reverseLtoR(start, end);

		lastEnd->next = end;

		lastEnd = start;
	}

	    return head;
    }
};