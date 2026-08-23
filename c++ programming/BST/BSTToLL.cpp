// Date: 27/06/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Time Complexity: O(n)
// Space Complexity: O(h)
class Solution
{
    public:
        TreeNode *first = nullptr;
        TreeNode *last = nullptr;
        void inorder(TreeNode *root)
        {
            if(!root) return;
            inorder(root->left);

            if(last)
            {
                last->right = root;
                root->left = last;
            }
            else
            {
                first = root;
            }
            last = root;
            inorder(root->right);
        }
        TreeNode *doublyLinkedList(TreeNode *root)
        {
            inorder(root);
            last->right = first;
            first->left = last;
            return first;
        }

        void Traverse(TreeNode *head)
        {
            if(!head) return;
            TreeNode *curr = head;
            
            do{
                cout<< curr->val <<" ";
                curr = curr->right;
            }while(curr != head);
        }

};

int main()
{
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
    TreeNode *head = s.doublyLinkedList(root);
    s.Traverse(head);
    return 0;
}