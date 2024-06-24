#include <iostream>
#include "../head/treeNode.h"
#include <limits>

using namespace std;

class Solution {
public:
    bool checkRoot(TreeNode* root, long min, long max)
    {
        if(root == NULL)
            return true;
        
        if(root->val <= min || root->val >= max)
            return false;

        return checkRoot(root->left, min, root->val)
                &&checkRoot(root->right, root->val, max);
    }

    bool isValidBST(TreeNode* root) 
    {
        return checkRoot(root, numeric_limits<long>::min(), numeric_limits<long>::max());
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

