#include <iostream>
#include "../head/leetCode.h"

using namespace std;

class Solution
{
public:
    vector<int> findMode(TreeNode* root)
    {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;

        int maxCount = 0;
        int count = 0;

        vector<int> res;
        while (cur!=nullptr || !st.empty())
        {
            if(cur!=nullptr)
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = st.top();
                st.pop();
                if(pre == nullptr)
                    count = 1;
                else if(pre->val == cur->val)
                    count++; 
                else
                    count = 1;
                
                if(count == maxCount)
                    res.push_back(cur->val);
                
                if(count > maxCount)
                {
                    maxCount = count;
                    res.clear();
                    res.push_back(cur->val);
                }
                pre = cur;
                cur = cur->right;
            }//end of else
        }//end of while(cur!=nullptr || !st.empty())

        return res;
    }
};

int main()
{
    return 0;
}