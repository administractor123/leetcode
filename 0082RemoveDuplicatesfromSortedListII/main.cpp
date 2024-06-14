#include<iostream>
using namespace std;
#include<vector>

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* createListNode(vector<int> nums)
{
	ListNode* head = new ListNode(nums[0]);
	ListNode* pc = head;

	for (int i = 1; i < nums.size(); i++)
	{
		pc->next = new ListNode(nums[i]);
		pc = pc->next;
	}

	return head;
}

void printListNode(ListNode* head)
{
	ListNode* pc = head;
	while (pc)
	{
		cout << pc->val << " ";
		pc = pc->next;
	}
	cout << endl;
}

ListNode* deleteDuplicates(ListNode* head)
{
	if (!head)
	{
		return head;
	}

	ListNode* dummy = new ListNode(-100,head);
	ListNode* p = dummy;
	while (p->next && p->next->next)
	{
		if (p->next->val == p->next->next->val)
		{
			//存储相同的值，p不动，val保证完全删除重复的值
			int val = p->next->val;
			while (p->next != nullptr && p->next->val == val)
			{
				//消除p->next
				p->next = p->next->next;
			}
		}
		else
		{
			p = p->next;
		}
	}
	return dummy->next;
}

int main()
{
	vector<int> nums = { 1,1,2,2,2,3 };
	ListNode* head = createListNode(nums);
	printListNode(head);

	head = deleteDuplicates(head);
	printListNode(head);
}