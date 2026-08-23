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

// Time Complexity: O(n^2) - height() is called for each node, and height() itself is O(n)
// Space Complexity: O(h) - recursion stack depth where h is the height of the tree
class Solution {
    public:
        int height(TreeNode *root)
        {
            if(!root) return 0;

            return 1+max(height(root->left),height(root->right));
        }
        bool isBalanced(TreeNode *root)
        {
            if(!root) return true;

            int leftHeight = height(root->left);
            int rightHeight = height(root->right);

            if(abs(leftHeight - rightHeight) > 1) return false;

            return isBalanced(root->left) && isBalanced(root->right);
        }
};

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    cout<<s.isBalanced(root)<<endl;
    return 0;
}