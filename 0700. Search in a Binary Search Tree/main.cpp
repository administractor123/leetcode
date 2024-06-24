#include <iostream>
#include "../head/treeNode.h"
#include <queue>

using namespace std;

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        if(root == NULL)    return NULL;

        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty())
        {
            TreeNode* node = que.front();
            que.pop();

            if(node->val == val)
                return node;
            
            if(node->left != NULL)
                que.push(node->left);
            if(node->right != NULL)
                que.push(node->right);
        }

        return NULL; 
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

