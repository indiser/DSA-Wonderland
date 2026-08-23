#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Time Complexity: O(n) - visits each node once
// Space Complexity: O(n) - queue and result vector store all nodes
class Solution {
    public:
        vector<vector<int>> levelOrderTraversal(TreeNode *root)
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
                level++;
            }
            return ans;
        }
        int findBottomLeftValue(TreeNode *root)
        {
            vector<vector<int>> ans = levelOrderTraversal(root);
            reverse(ans.begin(),ans.end());
            return ans[0][0];
        }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(6);
    root->right->left = new TreeNode(5);
    root->right->left->left = new TreeNode(7);

    Solution s;
    cout<<s.findBottomLeftValue(root)<<endl;
    return 0;
}