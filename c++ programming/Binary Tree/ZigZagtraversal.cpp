// Date: 10/06/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Time Complexity: O(n) - visit each node once
// Space Complexity: O(n) - queue stores nodes at each level, worst case n/2 nodes at last level
class Solution {
    public:
        vector<vector<int>> zigzagLevelOrder(TreeNode *root)
        {
            if(root == nullptr) return{};

            queue<TreeNode*> q;
            int level=0;

            vector<vector<int>> ans;
            q.push(root);

            while(!q.empty())
            {
                int len=q.size();
                ans.push_back({});

                for (int i = 0; i < len; i++)
                {
                    TreeNode *node=q.front();
                    q.pop();

                    ans[level].push_back(node->val);

                    if(node->left != nullptr) q.push(node->left);
                    if(node->right != nullptr) q.push(node->right);
                }
                if(level % 2 != 0)
                {
                    reverse(ans[level].begin(), ans[level].end());
                }
                level++;
            }
            return ans;
        }
};

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    vector<vector<int>> ans = s.zigzagLevelOrder(root);

    for(auto level : ans)
    {
        for(int val : level)
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}