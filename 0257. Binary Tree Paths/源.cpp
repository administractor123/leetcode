#include <vector>
#include <stack>
#include <string>
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
	vector<string> binaryTreePaths(TreeNode* root)
	{
		stack<TreeNode*> treeSt;
		stack<string> pathSt;
		vector<string> result;

		if (root == nullptr)
			return result;
		treeSt.push(root);
		pathSt.push(to_string(root->val));

		while (!treeSt.empty())
		{
			TreeNode* node = treeSt.top();
			treeSt.pop();

			string path = pathSt.top();
			pathSt.pop();

			if (node->left == nullptr && node->right == nullptr)
			{
				result.push_back(path);
			}

			if (node->right)
			{
				treeSt.push(node->right);
				pathSt.push(path + "->" + to_string(node->right->val));
			}

			if (node->left)
			{
				treeSt.push(node->left);
				pathSt.push(path + "->" + to_string(node->left->val));
			}
		}

		return result;
	}
};