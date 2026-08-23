#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
#include<algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// Time Complexity: O(n) - where n is the number of nodes (inorder traversal visits each node once)
// Space Complexity: O(n) - for storing all node values in the vector
class Solution
{

    public:
        void inOrder(TreeNode *root, vector<int> &vals)
        {
            if(!root) return;
            inOrder(root->left,vals);
            vals.push_back(root->val);
            inOrder(root->right,vals);
        }
        int minDist(TreeNode *root)
        {
            vector<int> vals;
            inOrder(root,vals);

            int min_dist=INT_MAX;

            for (int i = 1; i < vals.size(); i++)
            {
                min_dist = min(min_dist, vals[i] - vals[i-1]);
            }
            return min_dist;
        }
};

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution s;
    cout<<s.minDist(root)<<endl;
    return 0;
}