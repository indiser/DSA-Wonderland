#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Time Complexity: O(n) - visits each node once
// Space Complexity: O(h) - recursion stack where h is height of tree
class Solution {
public:
    int diameterOfBinaryTree(TreeNode *root) {
        int maxDiameter = 0; 
        calculateHeight(root, maxDiameter);
        return maxDiameter;
    }

private:
    int calculateHeight(TreeNode* node, int& maxDiameter) {
        if (!node) return 0;

        int leftHeight = calculateHeight(node->left, maxDiameter);
        int rightHeight = calculateHeight(node->right, maxDiameter);

        maxDiameter = max(maxDiameter, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution s;
    cout << "Diameter: " << s.diameterOfBinaryTree(root) << endl; 
    
    return 0;
}