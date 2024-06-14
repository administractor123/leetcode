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
    bool compareTreeNode(TreeNode* left, TreeNode* right)
    {
        if(left==NULL && right==NULL)
            return true;
        else if(left!=NULL && right==NULL)
            return false;
        else if(left==NULL && right!=NULL)
            return false;
        else if(left->val != right->val)
            return false;
        else
            return compareTreeNode(left->left, right->left)
                && compareTreeNode(left->right, right->right);
    }

    bool subTreeHelper(TreeNode* root, TreeNode* subRoot)
    {
        if(!root)
            return false;
        
        return compareTreeNode(root, subRoot)  
            || subTreeHelper(root->left, subRoot)
            || subTreeHelper(root->right, subRoot);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        return subTreeHelper(root, subRoot);
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

