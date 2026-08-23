// Date: 24/06/2026
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

/*
Time Complexity : O(n)
Space Complexity : O(n)
*/
class Solution
{
        
    public:
        vector<int> inOrderTraversal(TreeNode *root)
        {
            if(!root) return {};
            vector<int> ans;
            TreeNode *curr = root;

            while(curr != NULL)
            {
                if(curr->left == NULL)
                {
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
                else
                {
                    TreeNode *IP = curr->left;
                    while(IP->right != NULL && IP->right != curr) IP = IP->right;

                    if(IP->right == NULL)
                    {
                        IP->right = curr;
                        curr = curr->left;
                    }
                    else
                    {
                        IP->right = NULL;
                        ans.push_back(curr->val);
                        curr = curr->right;
                    }
                }
            }
            return ans;

        }
        TreeNode *helper(vector<int> &preorder, int &index, int upperBound)
        {
            if(index >= preorder.size() || preorder[index] > upperBound) return nullptr;

            TreeNode *root = new TreeNode(preorder[index++]);
            root->left = helper(preorder, index, root->val);
            root->right = helper(preorder, index, upperBound);
            return root;
        }
        TreeNode *bstFromPreOrder(vector<int> &preorder)
        {
            int i = 0;
            return helper(preorder, i, INT_MAX);
        }
        
};

int main()
{
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    Solution s;
    TreeNode *root = s.bstFromPreOrder(preorder);

    vector<int> ans = s.inOrderTraversal(root);
    for(int val: ans)
    {
        cout<< val << " ";
    }
    return 0;
}