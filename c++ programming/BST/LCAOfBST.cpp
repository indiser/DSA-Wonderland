// Date: 21/06/2026
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

// Time Complexity: O(h)
// Space Complexity: O(h)
class Solution
{
    public:
       TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
       {
            if(!root) return nullptr;
            if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
            if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
            return root;
       }
};

int main()
{
    TreeNode *root = new TreeNode(6);
    root->right = new TreeNode(8);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left = new TreeNode(0);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(5);
    root->right->right = new TreeNode(9);
    root->right->left = new TreeNode(7);

    Solution s;
    TreeNode *result = s.lowestCommonAncestor(root, root->left, root->right);
    cout << result->val << endl;
    return 0;
}