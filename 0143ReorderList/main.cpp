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

void reorderList01(ListNode* head)
{
	ListNode* pLeft = head;
	ListNode* pRight = head;
	int n = 0;
	while (pRight != nullptr)
	{
		n++;
		pRight = pRight->next;
	}

	if (n%2==0)
	{
		for (int i = 1; i < n / 2; i++)
		{
			pRight = head;
			for (int j = 0; j < n - 2; j++)
			{
				pRight = pRight->next;
			}
			pRight->next->next = pLeft->next;
			pLeft->next = pRight->next;
			pRight->next = nullptr;
			pLeft = pLeft->next->next;
		}
	}
	else
	{
		for (int i = 1; i <= n / 2; i++)
		{
			pRight = head;
			for (int j = 0; j < n - 2; j++)
			{
				pRight = pRight->next;
			}
			pRight->next->next = pLeft->next;
			pLeft->next = pRight->next;
			pRight->next = nullptr;
			pLeft = pLeft->next->next;
		}
	}
}


//method 2
ListNode* findMiddNode(ListNode* head)
{
	ListNode* pSlow = head, * pFast = head;
	while (pFast != nullptr && pFast->next != nullptr)
	{
		pSlow = pSlow->next;
		pFast = pFast->next->next;
	}
	return pSlow;
}

ListNode* reverseList(ListNode* head)
{
	ListNode* temp = nullptr;
	ListNode* p = head->next;
	while (p != nullptr)
	{
		head->next = temp;
		temp = head;
		head = p;
		p = p->next;
	}
	head->next = temp;
	temp = head;
	return temp;
}

void reorderList02(ListNode* head)
{
	ListNode* mid = findMiddNode(head);
	ListNode* start = head;
	while (start->next!=mid)
	{
		start = start->next;
	}
	start->next = nullptr;
	start = head;

	mid = reverseList(mid);

	ListNode* tail = mid->next;
	while (tail != nullptr )
	{
		if (start->next==nullptr)
		{
			start->next = mid;
			return;
		}
		else
		{
			mid->next = start->next;
			start->next = mid;
			start = mid->next;
			if (tail->next == nullptr)
			{
				start->next = tail;
				return;
			}
			mid = tail;
			tail = tail->next;
		}

	}

}

int main()
{
	vector<int> nums = { 1,2,3,4,5};
	ListNode* head = createListNode(nums);
	ListNode* mid = nullptr;
	printListNode(head);

	reorderList02(head);
	printListNode(head);
}