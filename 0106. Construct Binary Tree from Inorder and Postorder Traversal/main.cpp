#include <iostream>
#include "../head/treeNode.h"
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    TreeNode* bulidRoot(vector<int>& inorder, vector<int>& postorder)
    {
        if(inorder.empty())
            return NULL;

        int value = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(value);

        if(postorder.size() == 1)
            return root;

        postorder.resize(postorder.size()-1);

        int n;
        for(n=0; n<inorder.size(); ++n)
        {
            if(inorder[n] == value)
                break;
        }
        
        vector<int> inorder_left(inorder.begin(), inorder.begin()+n);
        vector<int> inorder_right(inorder.begin()+n+1, inorder.end());

        vector<int> postorder_left(postorder.begin(), postorder.begin()+inorder_left.size());
        vector<int> postorder_right(postorder.begin()+inorder_left.size(), postorder.end());

        root->left = bulidRoot(inorder_left, postorder_left);
        root->right = bulidRoot(inorder_right, postorder_right);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        if(inorder.empty())
            return nullptr;
        return bulidRoot(inorder, postorder);
    }
};

int main()
{


    return 0;
}

