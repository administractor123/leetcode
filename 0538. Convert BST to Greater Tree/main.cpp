#include <iostream>
#include "../head/leetCode.h"

using namespace std;

class Solution
{
private:
    int sum = 0;
public:
    void sumBST(TreeNode* root)
    {
        if(root == nullptr)
            return;
        
        sumBST(root->right);

        sum += root->val;
        root->val = sum;

        sumBST(root->left);
    }

    TreeNode* convertBST(TreeNode* root)
    {
        sumBST(root);
        return root;
    }
};

int main()
{
    return 0;
}