// Date: 23/06/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution
{
    public:
        vector<vector<int>> levelOrderTraversal(TreeNode *root)
        {
            if(root == nullptr) return{};

            queue<TreeNode*> q;
            int level=0;

            vector<vector<int>> ans;
            q.push(root);

            while(!q.empty())
            {
                int len=q.size();
                ans.push_back({});

                for (int i = 0; i < len; i++)
                {
                    TreeNode *node=q.front();
                    q.pop();

                    ans[level].push_back(node->val);

                    if(node->left != nullptr) q.push(node->left);
                    if(node->right != nullptr) q.push(node->right);
                }
                level++;
            }
            return ans;
        }
        TreeNode *prev = nullptr;
        TreeNode *first = nullptr;
        TreeNode *sec = nullptr;
        void inorder(TreeNode *root)
        {
            if(!root) return;

            inorder(root->left);

            if(prev != nullptr && prev->val > root->val)
            {
                if(!first) first = prev;
                sec = root;
            }
            prev = root;
            inorder(root->right);
        }
        void recoverTree(TreeNode *root)
        {
            inorder(root);

            swap(first->val, sec->val);
        }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(2);

    Solution s;
    s.recoverTree(root);
    vector<vector<int>> ans = s.levelOrderTraversal(root);
    for(auto val:ans)
    {
        for(auto v:val)
        {
            cout<<v<<" ";
        }
        cout<<endl;
    }
    return 0;
}