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

ListNode* detectCycle01(ListNode* head)
{

}

ListNode* detectCycle02(ListNode* head)
{
	ListNode* temp = head;
	unordered_set<ListNode*> seen;
	while (temp!=nullptr)
	{
		if (seen.count(temp))
		{
			return temp;
		}
		seen.insert(temp);
		temp = temp->next;
	}
	return nullptr;
}

int main()
{

}