#include <iostream>
#include "../head/leetCode.h"

using namespace std;

class Solution
{
public:
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    // {
    //     if(root->val > p->val && root->val > q->val)
    //         return lowestCommonAncestor(root->left, p, q);
    //     else if(root->val < p->val && root->val < q->val)
    //         return lowestCommonAncestor(root->right, p, q);
    //     else 
    //         return root;
    // }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        while (root)
        {
            if(root->val>p->val && root->val>q->val)
                root = root->left;
            else if(root->val<p->val && root->val<q->val)
                root = root->right;
            else
                return root;
        }
        return nullptr; 
    }

};

int main()
{
    return 0;
}