#include<vector>
#include<queue>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};

class Solution
{
public:
	bool isSymmetric1(TreeNode* root)
	{
		if (root == nullptr) return true;
		
		queue<TreeNode*> que;
		que.push(root->left);
		que.push(root->right);
		
		while (!que.empty())
		{
			TreeNode* leftNode = que.front();
			que.pop();
			TreeNode* rightNode = que.front();
			que.pop();

			if (!leftNode && !rightNode)
				continue;
			if (!leftNode || !rightNode || leftNode->val != rightNode->val)
				return false;

			que.push(leftNode->left);
			que.push(rightNode->right);
			que.push(leftNode->right);
			que.push(rightNode->left);
		}
		return true;
	}

	//************************************************************************************
	//ตÝน้
	bool compare(TreeNode* left, TreeNode* right)
	{
		if (!left && !right) return true;
		if (!left || !right) return false;

		bool outside = compare(left->left, right->right);
		bool inside = compare(left->right, right->left);
		bool now = (left->val == right->val);
		return (outside && inside && now);
	}

	bool isSymmetric(TreeNode* root)
	{
		return compare(root->left, root->right);
	}
};