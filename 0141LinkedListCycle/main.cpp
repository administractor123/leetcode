#include<iostream>
using namespace std;
#include<vector>
#include<unordered_set>

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

bool hasCycle01(ListNode* head)
{
	ListNode* pSlow = head, * pFast = head;
	do
	{
		if (pFast == nullptr || pFast->next == nullptr)
		{
			return false;
		}
		pSlow = pSlow->next;
		pFast = pFast->next->next;
	} while (pSlow != pFast);

	return true;
}

bool hasCycle02(ListNode* head)
{
	unordered_set<ListNode*> seen;
	while (head != nullptr)
	{
		if (seen.count(head))
		{
			return true;
		}
		seen.insert(head);
		head = head->next;
	}
	return false;
}


int main()
{

	return 0;
}