#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*
 * Time Complexity: O(n) - visits each node exactly once
 * Space Complexity: O(h) - recursion stack depth, where h is tree height
 */
class Solution
{
    private:
        void reverseInorder(TreeNode *root, int &sum)
        {
            if(!root) return;
            reverseInorder(root->right, sum);
            sum += root->val;
            root->val = sum;
            reverseInorder(root->left, sum);
        }
        void helper(TreeNode *root, vector<int> &ans)
        {
            if(!root) return;
            helper(root->left, ans);
            ans.push_back(root->val);
            helper(root->right, ans);
        }
    public:
        vector<int> inOrderTraversal(TreeNode *root)
        {
            vector<int> ans;
            helper(root,ans);
            return ans;
        }
        TreeNode *bstToGst(TreeNode *root)
        {
            int sum = 0;
            reverseInorder(root, sum);
            return root;
        }
};

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(3);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(8);

    Solution s;

    cout<<"Before: "<<endl;
    vector<int> prev=s.inOrderTraversal(root);
    for(int val: prev)
    {
        cout<< val <<" ";
    }
    cout<<endl;

    s.bstToGst(root);
    cout<<"After: "<<endl;
    vector<int> result=s.inOrderTraversal(root);
    for(int val: result)
    {
        cout<< val <<" ";
    }
    cout<<endl;
    return 0;
}