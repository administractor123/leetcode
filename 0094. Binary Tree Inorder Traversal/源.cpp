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
	void	inorder(TreeNode* root, vector<int>& nums)
	{
		if (root == nullptr)
		{
			return;
		}

		inorder(root->left, nums);
		nums.push_back(root->val);
		inorder(root->right, nums);
	}

	//Ñ­»·
	void inorder2(TreeNode* root, vector<int>& nums)
	{
		stack<TreeNode*> st;
		TreeNode* current = root;

		while (current != nullptr || !st.empty())
		{
			while (current != nullptr)
			{
				st.push(current);
				current = current->left;
			}

			current = st.top();
			st.pop();
			nums.push_back(current->val);

			current = current->right;
		}
	}

	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> res;
		inorder(root, res);
		return res;
	}
};