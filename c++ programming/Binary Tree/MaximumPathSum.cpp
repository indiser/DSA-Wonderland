// Date: 11/06/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Time Complexity: O(N)
// Space Complexity: O(H)
class Solution {
    public:
        int maxSum = INT_MIN;
        int dfs(TreeNode *root)
        {
            if(!root) return 0;

            int leftGrain = max(0, dfs(root->left));
            int rightGain = max(0, dfs(root->right));

            int currSum = root->val + leftGrain + rightGain;
            maxSum = max(maxSum, currSum);

            return root->val + max(leftGrain, rightGain);
        }
        int maxPathSum(TreeNode *root)
        {
            dfs(root);
            return maxSum;
        }
};

int main() {
    TreeNode *root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    
    // TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(-2);
    // root->right = new TreeNode(-3);
    // root->right->left = new TreeNode(-2);
    // root->left->right = new TreeNode(3);
    // root->left->left = new TreeNode(1);
    // root->left->left->left = new TreeNode(-1);

    Solution s;
    cout<<s.maxPathSum(root)<<endl;
    return 0;
}