#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) 
    {
        int res = 0;
        stack<TreeNode*> st;
        if(root != NULL)
            st.push(root);
        
        while (!st.empty())
        {
            TreeNode* temp = st.top();
            st.pop();

            if(temp->left) 
            {
                if(temp->left->left == NULL && temp->left->right==NULL)
                    res += temp->left->val;
                st.push(temp->left);
            }
            if(temp->right) 
                st.push(temp->right);
        }
        return res;    
    }
};

int main(int argc,char* argv[])
{
    return 0;
}

