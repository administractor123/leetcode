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
	TreeNode* invertTree(TreeNode* root)
	{
		queue<TreeNode*> que;
		if (root != nullptr)
			que.push(root);

		while (!que.empty())
		{
			int size = que.size();
			for (int i = 0; i < size; i++)
			{
				TreeNode* temp = que.front();
				que.pop();
				swap(temp->left, temp->right);

				if (temp->left) que.push(temp->left);
				if (temp->right) que.push(temp->right);
			}
		}

		return root;
	}
};