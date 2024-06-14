#include<vector>
#include<queue>
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
	vector<double> averageOfLevels(TreeNode* root)
	{
		queue<TreeNode*> que;
		vector<double> res;
		if (root != nullptr)
			que.push(root);

		while (!que.empty())
		{
			int size = que.size();
			double aveSum = 0;
			for (int i = 0; i < size; i++)
			{
				TreeNode* temp = que.front();
				que.pop();
				aveSum += temp->val;

				if (temp->left) que.push(temp->left);
				if (temp->right) que.push(temp->right);
			}
			res.push_back(aveSum / size);
		}

		return res;
	}
};