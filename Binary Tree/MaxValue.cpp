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
        int maxValue(TreeNode *root)
        {
            if(!root) return INT_MIN;
            
            int leftValue = maxValue(root->left);
            int rightValue = maxValue(root->right);
            
            return max(root->val, max(leftValue, rightValue));
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
    cout<<s.maxValue(root)<<endl;
    return 0;
}