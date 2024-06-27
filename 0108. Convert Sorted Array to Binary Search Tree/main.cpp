#include <iostream>
#include "../head/leetCode.h"

using namespace std;

class Solution
{
public:
    TreeNode* buildBST(vector<int>& nums, int left, int right)
    {
        if(left > right)
            return nullptr;
        
        int mid = left + (right - left >> 1);
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildBST(nums, left, mid-1);
        root->right = buildBST(nums, mid+1, right);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
       return buildBST(nums, 0, nums.size()-1); 
    }
};

int main()
{
    return 0;
}