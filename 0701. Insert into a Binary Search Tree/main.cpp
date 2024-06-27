#include <iostream>
#include "../head/leetCode.h"

using namespace std;

class Solution
{
public:
    TreeNode* insertIntoBST(TreeNode* root, int val)
    {
        if(root == nullptr)
        {
            return new TreeNode(val);
        }

        TreeNode* cur = root;
        TreeNode* parent = root;
        TreeNode* temp = new TreeNode(val);

        while (cur)
        {
            parent = cur;
            if(val < cur->val)
                cur = cur->left;
            else if(val > cur->val)
                cur = cur->right;
        }
        
        if(val < parent->val)
            parent->left = temp;
        else
            parent->right = temp;
        
        return root;
    }
};

int main()
{
    return 0;
}