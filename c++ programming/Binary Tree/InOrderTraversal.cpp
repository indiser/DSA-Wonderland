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
        // void helper(TreeNode *root, vector<int> &ans)
        // {
        //     if(!root) return;
        //     helper(root->left, ans);
        //     ans.push_back(root->val);
        //     helper(root->right, ans);
        // }
        // vector<int> inOrderTraversal(TreeNode *root)
        // {
        //     vector<int> ans;
        //     helper(root,ans);
        //     return ans;
        // }
        vector<int> inOrderTraversal(TreeNode *root)
        {
            if(!root) return {};
            vector<int> ans;
            TreeNode *curr = root;

            while(curr != NULL)
            {
                if(curr->left == NULL)
                {
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
                else
                {
                    TreeNode *IP = curr->left;
                    while(IP->right != NULL && IP->right != curr) IP = IP->right;

                    if(IP->right == NULL)
                    {
                        IP->right = curr;
                        curr = curr->left;
                    }
                    else
                    {
                        IP->right = NULL;
                        ans.push_back(curr->val);
                        curr = curr->right;
                    }
                }
            }
            return ans;

        }
};

int main()
{
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    
    Solution sol;
    vector<int> result=sol.inOrderTraversal(root);
    
    for(int val : result)
        cout << val << " ";
    
    return 0;
}