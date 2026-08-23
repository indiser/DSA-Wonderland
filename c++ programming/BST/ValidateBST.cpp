// Date: 19/06/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Time Complexity: O(n)
// Space Complexity: O(h)
class Solution
{
    public:
        bool isBST(TreeNode *root, TreeNode *min, TreeNode *max)
        {
            if(root == nullptr) return true;
            if(min != NULL && root->val <= min->val) return false;
            if(max != NULL && root->val >= max->val) return false;

            return isBST(root->left, min, root) && isBST(root->right, root, max);
        }
        bool isValidBST(TreeNode *root)
        {
            return isBST(root, NULL, NULL);
        }
};

int main()
{
    TreeNode *root = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left = new TreeNode(1);

    Solution s;
    cout<<s.isValidBST(root)<<endl;
    return 0;
}