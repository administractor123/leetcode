#include <iostream>
#include "../head/leetCode.h"

using namespace std;

class Solution
{
public:
    TreeNode* deleteHelper(TreeNode* node)
    {
        if(node == nullptr) 
            return node;
        
        if(node->right == nullptr)
            return node->left;
        
        TreeNode* cur = node->right;
        while (cur->left)
        {
            cur = cur->left;
        }
        cur->left = node->left;
        
        return node->right;
    }

    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if(root == nullptr)
            return root;

        TreeNode* parent = nullptr;
        TreeNode* cur = root;
        while (cur)
        {
            if(key == cur->val)
                break;

            parent = cur;
            cur = (key<cur->val) ? (cur->left):(cur->right);
       }

        if(parent == nullptr)
            return deleteHelper(cur);
        if(parent->left && parent->left->val == key)
            parent->left = deleteHelper(cur);
        if(parent->right && parent->right->val == key)
            parent->right = deleteHelper(cur);

        return root;
    }
};

int main()
{
    return 0;
}