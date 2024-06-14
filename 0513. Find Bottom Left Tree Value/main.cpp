#include <iostream>
#include <queue>
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
    int findBottomLeftValue(TreeNode* root) 
    {
        int res = 0;
        queue<TreeNode*> que;
        if(root != NULL)
            que.push(root);

        while (!que.empty())
        {
            int size = que.size();
            for(int i=0; i<size; ++i)
            {
                TreeNode* temp = que.front();
                que.pop();
                if(i==0) res = temp->val;
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
            }
        }
        
        return res;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

