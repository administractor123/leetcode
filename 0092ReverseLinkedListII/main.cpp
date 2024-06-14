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

ListNode* reverseBetween(ListNode* head, int left, int right)
{
	if (!head)
	{
		return head;
	}
	ListNode* dommey = new ListNode(-501,head);
	ListNode* pre = dommey;
	for (int i = 0; i < left - 1; i++)
	{
		pre = pre->next;
	}
	ListNode* cur = pre->next;
	ListNode* next = cur->next;

	for (int i = 0; i < right-left; i++)
	{
		cur->next = next->next;
		next->next = pre->next;
		pre->next = next;
		next = cur->next;
	}

	return dommey->next;
}

ListNode* reverseList(ListNode* head)
{
	ListNode* temp = nullptr;
	ListNode* pre = head, * p = head->next;
	while (p != nullptr)
	{
		pre->next = temp;
		temp = pre;
		pre = p;
		p = p->next;
	}
	if (pre!=nullptr)
	{
		pre->next = temp;
		temp = pre;
	}

	return temp;
}

int main()
{
	vector<int> nums = { 1,2,3,4,5,6,7 };
	ListNode* head = createListNode(nums);
	printListNode(head);

	head = reverseBetween(head, 3, 6);
	printListNode(head);

}