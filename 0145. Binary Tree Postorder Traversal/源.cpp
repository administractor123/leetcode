#include<vector>
#include<stack>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {};
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {};
};

class Solution
{
public:
	//µÝ¹é
	void postorder(TreeNode* root, vector<int>& nums)
	{
		if (root == nullptr)
		{
			return;
		}

		postorder(root->left, nums);
		postorder(root->right, nums);
		nums.push_back(root->val);
	}

	//Ñ­»·
	void postorder2(TreeNode* root, vector<int>& nums)
	{
		if (root == nullptr)
		{
			return;
		}

		stack<TreeNode*> st1, st2;
		st1.push(root);

		while (!st1.empty())
		{
			TreeNode* node = st1.top();
			st1.pop();
			st2.push(node);

			if (node->left) st1.push(node->left);
			if (node->right) st1.push(node->right);
		}

		while (!st2.empty())
		{
			TreeNode* node = st2.top();
			nums.push_back(node->val);
			st2.pop();
		}
	}

	vector<int> postorderTraversal(TreeNode* root)
	{
		vector<int> res;
		postorder(root, res);
		return res;
	}
};