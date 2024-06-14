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
	if (head == nullptr)
	{
		cout << "nullptr" << endl;
		return;
	}
	ListNode* pc = head;
	while (pc)
	{
		cout << pc->val << " ";
		pc = pc->next;
	}
	cout << endl;
}

ListNode* reverseList(ListNode* head)
{
	if (head == nullptr)return;
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

int main()
{

}