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

ListNode* removeNthFromEnd01(ListNode* head, int n)
{
	if (!head)
	{
		return head;
	}

	int length = 0;
	ListNode* pc = head;
	while (pc)
	{
		length++;
		pc = pc->next;
	}

	pc = head;
	int pos = length - n;
	if (pos == 0)
	{
		head = head->next;
		return head;
	}

	ListNode* pre = head;
	for (int i = 0; i < pos; i++)
	{
		pre = pc;
		pc = pc->next;
	}
	pre->next = pc->next;
	delete pc;

	return head;
}

ListNode* removeNthFromEnd02(ListNode* head, int n)
{
	ListNode* fast = head;
	ListNode* slow = new ListNode(0);
	slow->next = head;
	
	int length = 0;
	while (fast)
	{
		length++;
		fast = fast->next;
	}
	fast = head;

	int pos = length - n;
	while (pos--)
	{
		fast = fast->next;
	}

	ListNode* temp = fast->next;
	fast->next = fast->next->next;
	delete temp;

	return slow->next;
}


int main()
{
	vector<int> nums = { 1,2,3,4,5 };
	ListNode* head = createListNode(nums);
	printListNode(head);

	//head = removeNthFromEnd01(head, 2);
	printListNode(head);

	return 0;
}