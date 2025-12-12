#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *right;
    TreeNode *left;

    TreeNode(int x)
    {
        val=x;
        right=NULL;
        left=NULL;
    }
};

class Solution
{
    public:
        void inOrderTraversal(TreeNode *root)
        {
            if(root==NULL) return;
            inOrderTraversal(root->left);
            cout<<root->val<<" ";
            inOrderTraversal(root->right);

        }
        TreeNode *invertedTree(TreeNode *root)
        {
            if(root==NULL) return NULL;
            swap(root->left,root->right);
            invertedTree(root->right);
            invertedTree(root->left);
            return root;
        }
};

int main()
{
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(20);
    root->left->left->left = new TreeNode(1);
    root->left->right->right = new TreeNode(9);
    
    Solution s;
    s.inOrderTraversal(root);
    cout<<endl;
    s.invertedTree(root);
    s.inOrderTraversal(root);

    return 0;
}