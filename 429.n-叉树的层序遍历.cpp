/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start

// Definition for a Node.
#include <vector>
#include <queue>

using namespace std;

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


class Solution {
public:
    vector<vector<int>> res;

    void bfs(Node* root)
    {
        if(!root) return;
        queue<Node*> q;
        q.push(root);

        while(q.size())
        {
            int n = q.size();
            vector<int> tmp;
            for(int i = 0; i < n; i++)
            {
                auto t = q.front();
                q.pop();
                tmp.push_back(t->val);

                for(auto e : t->children) q.push(e);
            }
            res.push_back(tmp);
        }
    }

    vector<vector<int>> levelOrder(Node* root) {
        bfs(root);

        return res;
    }
};
// @lc code=end

