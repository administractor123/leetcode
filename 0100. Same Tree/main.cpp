#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool CompareTreeNode(TreeNode* left, TreeNode* right)
    {
        if(left == NULL && right == NULL)
            return true;
        else if(left == NULL && right != NULL)
            return false;
        else if(left != NULL && right == NULL)
            return false;
        else if(left->val != right->val)
            return false;
        else
            return CompareTreeNode(left->left,right->left)
                && CompareTreeNode(left->right, right->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        return CompareTreeNode(p, q);
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

