#include <iostream>
#include "treeNode.h"

using namespace std;

class Solution {
public:
    int getHeight(TreeNode* node)
    {
        if(node == nullptr)
            return 0;

        int leftHeight = getHeight(node->left);
        if(leftHeight == -1)
            return -1;

        int rightHeight = getHeight(node->right);
        if(rightHeight == -1)
            return -1;

        int n = leftHeight - rightHeight > 0 ?
            leftHeight - rightHeight : 
            rightHeight - leftHeight;
        return n > 1 ? -1 : 1+max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) 
    {
        return getHeight(root) == -1? false:true;
    }
};

int main()
{
    return 0;
}

