// Date: 27/06/2026
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
// Space Complexity: O(1)
class Solution
{
    TreeNode *rightMostInLeft(TreeNode *root)
    {
        TreeNode *ans = nullptr;
        while(root != nullptr)
        {
            ans = root;
            root = root->right;
        }
        return ans;
    }
    TreeNode *leftMostInRight(TreeNode *root)
    {
        TreeNode *ans = nullptr;
        while(root != nullptr)
        {
            ans = root;
            root = root->left;
        }
        return ans;
    }
    public:
        vector<int> inorderPredSucc(TreeNode *root, int key)
        {
            if(!root) return {-1, -1};
            TreeNode *pred = nullptr;
            TreeNode *succ = nullptr;

            TreeNode *curr = root;

            while(curr != nullptr)
            {
                if(key < curr->val)
                {
                    succ = curr;
                    curr = curr->left;
                }
                else if(key > curr->val)
                {
                    pred = curr;
                    curr = curr->right;
                }
                else
                {
                    if(curr->left != nullptr)
                    {
                        // Right Most Value In Left Subtree
                        succ =  rightMostInLeft(curr);
                    }
                    if(curr->right != nullptr)
                    {
                        // Left Most In Right Subtree
                        pred = leftMostInRight(curr);
                    }
                    break;
                }
            }

            int pVal = pred ? pred->val : -1;
            int sVal = succ ? succ->val : -1;
            return {pVal, sVal};
        }
       
};

int main()
{
    int key = 0;
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
    vector<int> ans = s.inorderPredSucc(root, key);
    cout << "Inorder Predecessor: "<< ans[0]<<endl;
    cout << "Inorder Succesor: "<< ans[1]<<endl;

    return 0;
}