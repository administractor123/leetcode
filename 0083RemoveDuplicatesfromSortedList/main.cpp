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
	ListNode* temp = head;
	if (temp == nullptr)
	{
		return temp;
	}
	ListNode* pSlow = head, * pFast = head;
	while (pFast)
	{
		if (pFast->val == pSlow->val)
		{
			pFast = pFast->next;
		}
		else 
		{
			pSlow->next = pFast;
			pSlow = pFast;
			pFast = pFast->next;
		}
	}
	if (pFast == nullptr)
	{
		pSlow->next = pFast;
	}

	return temp;
}

int main()
{
	vector<int> nums = { 1,1,1,2,2,3,3 };
	ListNode* head = createListNode(nums);
	printListNode(head);

	deleteDuplicates(head);
	printListNode(head);

	return 0;
}