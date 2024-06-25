#include <iostream>
#include "../head/leetCode.h"

using namespace std;

class Solution
{
public:
    TreeNode* buildRoot(vector<int>& preorder, vector<int>& inorder)
    {
        if(preorder.empty())
            return nullptr;
        
        int value = preorder.front();
        TreeNode* root = new TreeNode(value);

        if(preorder.size() == 1)
            return root;

        auto it = find(inorder.begin(), inorder.end(), value);
        int n = distance(inorder.begin(), it);

        vector<int> inorder_left(inorder.begin(), inorder.begin()+n);
        vector<int> inorder_right(inorder.begin()+n+1, inorder.end());

        vector<int> preorder_left(preorder.begin()+1, preorder.begin()+1+n);
        vector<int> preorder_right(preorder.begin()+1+n, preorder.end());

        root->left = buildRoot(preorder_left, inorder_left);
        root->right = buildRoot(preorder_right, inorder_right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        if(preorder.empty())
            return nullptr;
        
        return buildRoot(preorder, inorder);
    }
};

int main()
{
    return 0;
}