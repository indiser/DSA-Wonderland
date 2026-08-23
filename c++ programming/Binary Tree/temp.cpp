#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<math.h>
#include<algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    public:
        void helper(TreeNode *root, vector<int> &ans)
        {
            if(!root) return;
            helper(root->left, ans);
            ans.push_back(root->val);
            helper(root->right, ans);
        }
        vector<int> inOrderTraversal(TreeNode *root)
        {
            vector<int> ans;
            helper(root,ans);
            return ans;
        }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left=new TreeNode(4);
    root->right->right=new TreeNode(3);

    Solution s;
    vector<int> res = s.inOrderTraversal(root);

    vector<int> rev(res.rbegin(),res.rend());
    
    if(res == rev)
    {
        cout<<"Same"<<endl;
    }
    else
    {
        cout<<"Not same"<<endl;
    }
    
    return 0;
}