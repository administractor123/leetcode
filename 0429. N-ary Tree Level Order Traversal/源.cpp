#include<vector>
#include<queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(Node* root)
    {
        queue<Node*> que;
        vector<vector<int>> res;
        if (root != nullptr)
            que.push(root);

        while (!que.empty())
        {
            int size = que.size();
            vector<int> vec;
            for (int i = 0; i < size; i++)
            {
                Node* temp = que.front();
                que.pop();
                vec.push_back(temp->val);

                for (auto it : temp->children )
                {
                    que.push(it);
                }
            }
            res.push_back(vec);
        }
        
        return res;
    }
};