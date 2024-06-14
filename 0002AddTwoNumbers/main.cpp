#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* list = new ListNode(0), * head = list;
	int isUp = 0;
	while (l1 || l2)
	{
		int temp = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + isUp;
		isUp = temp / 10;

		head->next = new ListNode(temp % 10);
		head = head->next;

		if (l1)
		{
			l1 = l1->next;
		}
		if (l2)
		{
			l2 = l2->next;
		}
	}
	if (isUp > 0)
	{
		head->next = new ListNode(isUp);
	}

	return list->next;
}

int main()
{

}
