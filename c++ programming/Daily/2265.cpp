// Date: 10/09/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *right;
    TreeNode *left;

    TreeNode(int _val)
    {
        val = _val;
        right = nullptr;
        left = nullptr;
    }
};

// Time Complexity: O(n)
// Space Compelexity: O(h)
class Solution
{
    public:
        vector<int> Traverse(TreeNode *root, vector<int> &traverseList)
        {
            if(root == nullptr) return {};

            Traverse(root->left, traverseList);
            Traverse(root->right, traverseList);
            traverseList.push_back(root->val);

            return traverseList;
        }

        int count = 0;
        pair<int, int> postOrder(TreeNode *root)
        {
            if(!root) return {0, 0};

            pair<int, int> right = postOrder(root->right);
            pair<int, int> left = postOrder(root->left);

            int sum = left.first + right.first + root->val;
            int nodeCount = left.second + right.second + 1;

            if((sum / nodeCount) == root->val) count++;

            return {sum, nodeCount};
        }

        int avgOfTree(TreeNode *root)
        {
            postOrder(root);
            return count;
        }
};

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(8);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(6);

    Solution s;
    vector<int> traversal;
    vector<int> result = s.Traverse(root, traversal);

    // for(auto val: result) cout << val <<endl;
    cout << s.avgOfTree(root)<< endl;

    return 0;
}