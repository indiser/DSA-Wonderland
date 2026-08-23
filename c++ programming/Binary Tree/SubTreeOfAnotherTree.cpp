#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Time Complexity: O(m * n) where m = nodes in root, n = nodes in subRoot
// Space Complexity: O(h) where h = height of root (recursion stack)
class Solution
{
    public:
        bool isIdentical(TreeNode *root1, TreeNode *root2)
        {
            if(root1 == nullptr && root2 == nullptr) return true;
            if(root1 == nullptr || root2 == nullptr) return false;
            return(root1->val == root2->val) && isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
        }
        bool isSubtree(TreeNode *root, TreeNode *subRoot)
        {
            if(root == nullptr || subRoot == nullptr) return root==subRoot;
            if( root->val == subRoot->val && isIdentical(root,subRoot)) return true;
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
};

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    TreeNode *subRoot = new TreeNode(4);
    subRoot -> left = new TreeNode(1);
    subRoot -> right = new TreeNode(2);

    Solution s;
    cout<<s.isSubtree(root,subRoot)<<endl;

    return 0;
}