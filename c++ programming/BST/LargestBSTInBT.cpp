// Date: 28/06/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Time Complexity: O(n^2)
// Space Complexity: O(h)
class Solution
{
    private:
        bool isBST(TreeNode *root, TreeNode *min, TreeNode *max)
        {
            if(root == nullptr) return true;
            if(min != NULL && root->val <= min->val) return false;
            if(max != NULL && root->val >= max->val) return false;

            return isBST(root->left, min, root) && isBST(root->right, root, max);
        }
        bool isValidBST(TreeNode *root)
        {
            return isBST(root, NULL, NULL);
        }
        int countNodes(TreeNode *root)
        {
            if(!root) return 0;
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    public:
        void returnNum(TreeNode *root, int &cnt)
        {
            if(!root) return;

            returnNum(root->left, cnt);

            if(isValidBST(root)) cnt = max(cnt, countNodes(root));

            returnNum(root->right, cnt);

        }
        int largestInBST(TreeNode *root)
        {
            int largest = 0;
            returnNum(root, largest);

            return largest;
        }
};

class Info
{
    public:
        int min, max, sz;
        Info(int mi, int ma, int s)
        {
            min = mi;
            max = ma;
            sz = s;
        }
};

// Time Complexity: O(n)
// Space Complexity: O(h)
class OptimizedSolution
{
    public:
        Info helper(TreeNode *root)
        {
            if(root == nullptr) return Info(INT_MAX, INT_MIN, 0);

            Info left = helper(root->left);
            Info right = helper(root->right);

            if(root->val > left.max && root->val < right.min)
            {
                int currMin = min(root->val, left.min);
                int currMax = max(root->val, right.max);
                int currSize = left.sz + right.sz +1;
                return Info(currMin, currMax, currSize);
            }

            return Info(INT_MIN, INT_MAX, max(left.sz, right.sz));
        }
        int largestInBST(TreeNode *root)
        {
            Info info = helper(root);
            return info.sz;
        }
};

int main()
{
    // Test Case 1
    // TreeNode *root = new TreeNode(10);
    // root->right = new TreeNode(15);
    // root->left = new TreeNode(5);
    // root->left->right = new TreeNode(8);
    // root->left->left = new TreeNode(1);
    // root->right->right = new TreeNode(7);

    // Test Case 2
    // TreeNode *root = new TreeNode(4);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(6);
    // root->left->left = new TreeNode(1);
    // root->left->right = new TreeNode(3);
    // root->right->left = new TreeNode(5);
    // root->right->right = new TreeNode(7);

    // Test Case 3
    // TreeNode *root = new TreeNode(10);
    // root->left = new TreeNode(5);
    // root->right = new TreeNode(15);
    // root->left->left = new TreeNode(1);
    // root->left->right = new TreeNode(8);
    // root->left->left->left = new TreeNode(0);
    // root->right->right = new TreeNode(7);

    // Test Case 4
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(6);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    // Test Case 5
    // TreeNode *root = new TreeNode(25);
    // root->left = new TreeNode(18);
    // root->right = new TreeNode(50);

    // root->left->left = new TreeNode(10);
    // root->left->right = new TreeNode(20);

    // root->right->left = new TreeNode(35);
    // root->right->right = new TreeNode(60);

    // root->right->left->right = new TreeNode(40);
    // root->right->right->left = new TreeNode(55);
    // root->right->right->right = new TreeNode(70);


    Solution s;
    cout<<"Unoptimzed Solution: "<<s.largestInBST(root)<<endl;

    OptimizedSolution os;
    cout<<"Optimized Solution: "<<os.largestInBST(root)<<endl;
    return 0;
}