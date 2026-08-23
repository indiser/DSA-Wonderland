#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode()
    {
        val=0;
        left=nullptr;
        right=nullptr;
    }
    TreeNode(int _val)
    {
        val=_val;
        left=right=nullptr;
    }
};

class Solution
{
    public:
        void helper(TreeNode *root, vector<int> &ans)
        {
            if(!root) return;
            helper(root->left, ans);
            helper(root->right, ans);
            ans.push_back(root->val);
        }
        vector<int> postorderTraversal(TreeNode *root)
        {
            vector<int> ans;
            helper(root,ans);
            return ans;
        }
};

int main()
{
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    
    Solution sol;
    vector<int> result=sol.postorderTraversal(root);
    
    for(int val : result)
        cout << val << " ";
    
    return 0;
}