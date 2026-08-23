// Date: 17/06/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Time Complexity:O(n)
// Space Complexity: o(n)
class Solution
{
    public:
        void doer(TreeNode *root, vector<int> &ans)
        {
            if(!root) return;
            doer(root->left, ans);
            doer(root->right, ans);
            ans.push_back(root->val);
        }
        vector<int> postOrderTraversal(TreeNode *root)
        {
            vector<int> ans;
            doer(root,ans);
            return ans;
        }
        TreeNode *helper(vector<int> &nums, int start, int end)
        {
            if(start > end) return nullptr;

            int mid = start + (end - start) / 2;
            TreeNode *root = new TreeNode(nums[mid]);

            root->right = helper(nums, mid + 1, end);
            root->left = helper(nums, start, mid - 1);

            return root;
        }
        TreeNode *sortedArrayToBST(vector<int> &nums)
        {
            return helper(nums,0, nums.size()-1);
        }
};

int main()
{
    vector<int> nums = {-10, -3, 0, 5, 9};
    Solution s;
    vector<int> ans = s.postOrderTraversal(s.sortedArrayToBST(nums));
    for(int val:ans)
    {
        cout<< val << endl;
    }
    return 0;
}