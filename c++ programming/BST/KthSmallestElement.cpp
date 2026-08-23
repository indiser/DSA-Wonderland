// Date: 20/06/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Time Complexity: O(n) n = number of nodes in the BST
// Space Complexity: O(h) h = height stack of the BST
class Solution
{
    public:
        void helper(TreeNode *root, vector<int> &ans)
        {
            if(!root) return;
            helper(root->left, ans);
            ans.push_back(root->val);
            helper(root->right, ans);
        }
        vector<int> inOrderTraversal(TreeNode *root)
        {
            vector<int> ans;
            helper(root,ans);
            return ans;
        }
        int kthSmallest(TreeNode *root, int k)
        {
            vector<int> arr = inOrderTraversal(root);
            return arr[k-1];
        }
};

int main()
{
    int k = 3;
    TreeNode *root = new TreeNode(3);
    root->right = new TreeNode(4);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    Solution s;
    cout<<s.kthSmallest(root,k)<<endl;
    return 0;
}