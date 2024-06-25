#include <iostream>
#include "../head/leetCode.h"

using namespace std;

class Solution
{
public:
    TreeNode* buildMaxRoot(vector<int>& nums)
    {
        if(nums.empty())
            return nullptr;

        auto max = max_element(nums.begin(), nums.end());
        int n = max - nums.begin();

        TreeNode* root = new TreeNode(*max);

        vector<int> numsLeft(nums.begin(), nums.begin()+n);
        vector<int> numsRight(nums.begin()+n+1, nums.end());

        root->left = buildMaxRoot(numsLeft);
        root->right = buildMaxRoot(numsRight);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        if(nums.empty())
            return nullptr;

        return buildMaxRoot(nums);
    }
};

int main()
{
    return 0;
}