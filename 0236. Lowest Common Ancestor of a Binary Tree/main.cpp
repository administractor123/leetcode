#include <iostream>
#include "../head/leetCode.h"

using namespace std;

class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == nullptr || root->val == p->val || root->val == q->val)
            return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left!=nullptr && right!=nullptr)
            return root;
        if(left==nullptr)
            return right;
        return left;
        
    }
};

int main()
{
    return 0;
}