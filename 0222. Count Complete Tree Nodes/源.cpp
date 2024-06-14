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
	int countNodes1(TreeNode* root)
	{
		if (root == nullptr)
			return 0;

		TreeNode* leftNode = root->left;
		TreeNode* rightNode = root->right;
		int leftDepth = 0, rightDepth = 0;
		while (leftNode)
		{
			leftNode = leftNode->left;
			leftDepth++;
		}
		while (rightNode)
		{
			rightNode = rightNode->right;
			rightDepth++;
		}

		if (leftDepth == rightDepth)
		{
			return (2 << leftDepth) - 1;
		}

		return countNodes(root->left) + countNodes(root->right) + 1;
	}

	int countNodes(TreeNode* root)
	{
		if (root == nullptr)
			return 0;

		return countNodes(root->left) + countNodes(root->right) + 1;
	}
};