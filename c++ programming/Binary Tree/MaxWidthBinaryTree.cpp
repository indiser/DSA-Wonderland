// Date:08/06/2026
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
class Solution {
    public:
        int widthOfBinaryTree(TreeNode *root)
        {
            queue<pair<TreeNode*,unsigned long long>> q;
            q.push({root,0});
            int maxWidth = 0;

            while(q.size() > 0)
            {
                int currLevel = q.size();
                unsigned long long stIdx = q.front().second;
                unsigned long long  endIdx = q.back().second;

                maxWidth = max(maxWidth, (int)(endIdx - stIdx + 1));

                for (int i = 0; i < currLevel; i++)
                {
                    auto curr = q.front();
                    q.pop();
                    if(curr.first->left) q.push({curr.first->left, curr.second*2+1});
                    if(curr.first->right) q.push({curr.first->right, curr.second*2+2});
                }
            }

            return maxWidth;
        }
};

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    cout<<s.widthOfBinaryTree(root)<<endl;
    return 0;
}