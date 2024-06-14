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
	void preorder(TreeNode* root, vector<int>& nums)
	{
		if (root == nullptr)
		{
			return;
		}

		nums.push_back(root->val);
		preorder(root->left, nums);
		preorder(root->right, nums);
	}

	//Ñ­»·
	void preorder2(TreeNode* root, vector<int>& nums)
	{
		if (root == nullptr)
		{
			return;
		}

		stack<TreeNode*> st;
		st.push(root);

		while (!st.empty())
		{
			TreeNode* node = st.top();
			st.pop();
			nums.push_back(node->val);

			if (node->right) st.push(node->right);
			if (node->left) st.push(node->left);
		}
	}

	vector<int> preorderTraversal(TreeNode* root)
	{
		vector<int> res;
		preorder(root, res);
		return res;
	}
};