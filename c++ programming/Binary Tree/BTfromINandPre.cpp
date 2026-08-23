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

// Time Complexity: O(n)
// Space Complexity: O(n)
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
        int index = 0;
        unordered_map<int, int> map;
        TreeNode* helper(vector<int>& preorder, int start, int end) 
        {
            if (start > end) return nullptr;

            int rootVal = preorder[index++];
            TreeNode* root = new TreeNode(rootVal);
            int mid = map[rootVal];

            root->left = helper(preorder, start, mid - 1);
            root->right = helper(preorder, mid + 1, end);
            return root;
        }
        TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
        {
            for (int i = 0; i < inorder.size(); ++i)
                map[inorder[i]] = i;
            return helper(preorder, 0, inorder.size() - 1);
        }
        
};

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    
    Solution s;
    TreeNode *root = s.buildTree(preorder, inorder);
    vector<vector<int>> result = s.levelOrderTraversal(root);

    for(auto level : result)
    {
        for(int val : level)
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}