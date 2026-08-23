// Date: 29/06/2026
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

// Time Complexity: O(n+m)
// Space Comeplxity: O(n+m)
class Solution
{
    public:
        void inorder(TreeNode *root, vector<int> &ans)
        {
            if(!root) return;

            inorder(root->left, ans);
            ans.push_back(root->val);
            inorder(root->right, ans);
        }
        vector<int> merge(TreeNode *root1, TreeNode *root2)
        {
            vector<int> first, second;

            inorder(root1, first);
            inorder(root2, second);

            vector<int> ans;

            int i = 0, j = 0;
            int len1 = first.size(), len2 = second.size();

            while(i < len1 && j < len2)
            {
                if(first[i] <= second[j])
                {
                    ans.push_back(first[i]);
                    i++;
                }
                else
                {
                    ans.push_back(second[j]);
                    j++;
                }
            }

            while(i < len1)
            {
                ans.push_back(first[i]);
                i++;
            }

            while(j < len2)
            {
                ans.push_back(second[j]);
                j++;
            }
            
            return ans;
        }
};

int main()
{
    TreeNode *root1 = new TreeNode(3);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(5);

    TreeNode *root2 = new TreeNode(4);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(6);

    Solution s;
    vector<int> ans = s.merge(root1, root2);

    for(int val: ans)
    {
        cout<< val <<" ";
    }
    return 0;
}