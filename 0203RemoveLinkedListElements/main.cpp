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
	if (pc == nullptr)
	{
		cout << "nullptr" << endl;
		return;
	}
	while (pc)
	{
		cout << pc->val << " ";
		pc = pc->next;
	}
	cout << endl;
}

ListNode* removeElements(ListNode* head, int val)
{
	ListNode* dummy = new ListNode(-1, head);
	ListNode* pre = dummy, * cur = head;
	while (cur != nullptr)
	{
		if (cur->val == val)
		{
			pre->next = cur->next;
			ListNode* temp = cur;
			cur = cur->next;
			free(temp);
		}
		else
		{
			pre = pre->next;
			cur = cur->next;
		}
	}
	return dummy->next;
}

int main()
{
	vector<int> nums = { 1,2,6,3,4,5,6,7,6,6,6 };
	ListNode* head = createListNode(nums);
	printListNode(head);

	head = removeElements(head, 6);
	printListNode(head);

}