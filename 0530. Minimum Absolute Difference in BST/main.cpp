#include <iostream>
#include "../head/treeNode.h"
#include "limits"

using namespace std;

class Solution {
private:
    int ret = numeric_limits<int>::max();
    TreeNode* pre = NULL;
public:
    void calcDiff(TreeNode* root)
    {
        if(root == nullptr)
            return;
        
        calcDiff(root->left);

        if(pre != nullptr)
            ret = min(ret, root->val-pre->val);
        pre = root;
        
        calcDiff(root->right);

    }

    int getMinimumDifference(TreeNode* root) 
    {
        calcDiff(root);
        return ret;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

