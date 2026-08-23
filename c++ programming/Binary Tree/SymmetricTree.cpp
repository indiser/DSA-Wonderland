#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Time Complexity: O(n) - visits each node once
// Space Complexity: O(h) - recursion stack depth, h is tree height
class Solution
{
    public:
        bool isMirror(TreeNode *left, TreeNode *right)
        {
            if(!left && !right) return true;
            if(!left || !right) return false;
            return (left->val == right->val) && 
                   isMirror(left->left, right->right) && 
                   isMirror(left->right, right->left);
        }
        bool isSymmntric(TreeNode *root)
        {
            return !root || isMirror(root->left, root->right);
        }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left=new TreeNode(4);
    root->right->right=new TreeNode(3);

    Solution s;
    cout<<s.isSymmntric(root)<<endl;
    return 0;
}