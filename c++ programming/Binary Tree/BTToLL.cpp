// Date:07/06/2026
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


// Time Complexity: O(n) - visits each node once
// Space Complexity: O(h) - recursion stack depth where h is height of tree
class Solution {
    public:
        void Traverse(TreeNode *root)
        {
            if(!root) return;

            while(root->right != nullptr)
            {
                cout<<root->val<<" ";
                root=root->right;
            }
        }
        TreeNode *nextRight = nullptr;
        void flatten(TreeNode *root)
        {
            if(!root) return;
            flatten(root->right);
            flatten(root->left);
            root->left=nullptr;
            root->right=nextRight;
            nextRight=root;
        }
};

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    s.flatten(root);
    s.Traverse(root);
    return 0;
}